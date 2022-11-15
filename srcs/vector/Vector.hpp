/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:25:35 by cjulienn          #+#    #+#             */
/*   Updated: 2022/11/15 17:28:20 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

/* includes */ // check this
# include <limits>
# include <memory>
# include <vector>
# include <cstddef>
# include <sstream>

/* include other files */

# include "VectorIterator.hpp"
# include "VectorConstIterator.hpp"
# include "../utils/reverseIterator.hpp"

/* put synopsis there */

namespace ft // called by ft::Vector
{
	template <class T, class Alloc = std::allocator<T> >
	class vector
	{
		/* ALIASES */
		public:
			
			typedef T													value_type;
			typedef Alloc												allocator_type;
			typedef typename Alloc::reference 							reference;
			typedef typename Alloc::const_reference 					const_reference;
			typedef typename Alloc::pointer 							pointer;
			typedef typename Alloc::const_pointer 						const_pointer;
			typedef typename std::size_t 								size_type;
			typedef typename std::ptrdiff_t 							difference_type;
			/* aliases for iterators */
			typedef typename ft::vectorIterator<T>						iterator;
			typedef typename ft::vectorConstIterator<T>					const_iterator;
			typedef typename ft::reverseIterator<iterator>				reverse_iterator;
			typedef typename ft::reverseIterator<const_iterator>		const_reverse_iterator;

		/* CONSTRUCTORS, DESTRUCTOR, COPY, OVERLOADING ASSIGNMENT OPERATOR (COPLIEN FORM) */

			/* basic constructor (empty vector) */
			explicit vector(const allocator_type& alloc = allocator_type()) : _ptr(nullptr), // to test
			_size(0), _capacity(0), _alloc(alloc) {}

			/* vector filled with scalar or objects */
			explicit vector(size_type n, const value_type& val = value_type(),
				const allocator_type& alloc = allocator_type()) : _ptr(nullptr), _size(0), _capacity(0), _alloc(alloc) // to test
			{
				this->assign(n, val);
			}

			/* fill with a range of iterators */
			template <class InputIterator>
			vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()) // to test
			{
				this->assign(first, last);			
			}

			/* copy constructor */
			vector(const vector& x) : _ptr(x._ptr), _size(x._size), _capacity(x._capacity), _alloc(x._alloc) {} // to test

			/* destructor */
			virtual ~vector() // to test
			{
				this->clear();
				this->_alloc.deallocate(this->_ptr, this->_capacity);
			}

			/* overloading operator = */
			vector& operator=(const vector& x) // to test
			{
				if (this != &x)
				{
					this->_alloc = x._alloc;
					this->_size = x._size;
					this->_capacity = x._capacity;
					this->_ptr = x._ptr;
				}
				return *this;
			}
		
		/* METHODS RELATIVE TO VECTOR CAPACITY */

			/* return the number of elements in the array */
			size_type	size(void) const { return this->_size; }; // to test

			/* Returns the maximum number of elements that the vector can hold. */ 
			size_type	max_size(void) const { return this->_alloc.max_size() ; }; // to test

			/* resize the container so it contains n elements. Performs increase of
			container memory capacity if needed */
			void	resize(size_type n, value_type val = value_type()) // to test
			{
				if (n == this->_size)
					return ;
				if (n > this->max_size())
					; // handle err (check behaviour of real vector)
				if (n > this->_capacity)
				{
					this->_change_mem_allocated(n);
					for (size_type i = this->_size; i < this->_capacity; i++)
						this->_alloc.construct(this->_ptn + i, val);
					this->_size = this->_capacity;
				}
				else
				{
					for (size_type i = n; i < this->_size; i++)
						this->_alloc.destroy(this->_ptn + i);
					this->_size = n;
				}
			}

			/* returns the total number of elements that the vector can hold without reallocation */
			size_type	capacity(void) const {return this->_capacity; }; // to test

			/* return true if vector is empty, false otherwise */
			bool	empty(void) const {return (this->_size == 0); }; // to test

			/* reserve will make sur at vector can contain at least n elements.
			Do nothing if at least n elements are already allocated. Triggers exception if 
			n is superior to this->_max_size() */
			void	reserve(size_type n) // to test
			{
				if (n <= this->_capacity)
					return ;
				else if (n > this->max_size())
					throw std::length_error();
				else
					this->_change_mem_allocated(n);
			}

		/* METHODS RELATIVE TO VECTOR'S ELEMENT ACCESS */

			/* returns a reference to the element at position n in the vector container.
			can segfault if out-of-range-index */
			reference	operator[](size_type n) { return *(this + n); }; // to test

			/* returns a const reference to the element at position n in the vector container. 
			can segfault if out-of-range-index */
			const_reference	operator[](size_type n) const { return *(this + n); }; // to test

			/* returns a reference to the element at position n in the vector container.
			if index is wrong, throw a out-of-range-index exception */
			reference	at(size_type n) // to test
			{
				if (n >= this->_size)
					; // throw out of range exception TODO !!!
				return (this->operator[](n));
			}
			
			/* returns a const reference to the element at position n in the vector container.
			if index is wrong, throw a out-of-range-index exception */
			const_reference	at(size_type n) const // to test
			{
				if (n >= this->_size)
					; // throw out of range exception TODO !!!
				return (this->operator[](n));
			}
			
			/* returns a reference to the first value stored in vector */
			reference	front(void) { return (*this->_ptr); }; // to test
			
			/* returns a const reference to the first value stored in vector */
			const_reference	front(void) const { return (*this->_ptr); }; // to test

			/* returns a reference to the last value stored in vector */
			reference	back(void) { return (*this->_ptr + this->_size); };  // to test
						
			/* returns a reference to the last value stored in vector */
			const_reference	back(void) const { return (*this->_ptr + this->_size); }; // to test

			/* returns a pointer to the memory array used internally by the vector */
			value_type*	data(void) { return this->_ptr ; }; // to test

			/* returns a const pointer to the memory array used internally by the vector */
			const value_type* data(void) const { return this->_ptr ; }; // to test
			
		/* METHODS RELATIVE TO VECTOR MODIFICATION */

			template <class InputIterator>
			void	assign(InputIterator first, InputIterator last) // to test
			{
				for (first; first != last; first++)
					this->push_back(*first);
			}

			void	assign(size_type n, const value_type& val) // to test
			{
				for (int i = 0; i < n; i++)
					this->push_back(val);
			}

			void	push_back(const value_type& val) // to test
			{
				if (this->_size == this->_capacity)
					this->_expand_mem_allocated();
				this->_alloc.construct(this->_ptr + this->_size + 1, val);
			}

			void	pop_back(void) { this->_alloc.destroy(this->_ptr + this->_size); }; // to test

			iterator	insert(iterator position, const value_type& val)
			{
				if (this->_size + 1 > this->_capacity) // check if unsufficient capacity (trigger exception ?)
					this->_expand_mem_allocated();
				if (position != this->end())
					this->_shift_objs_in_vect(position, 1);
			}

			void	insert(iterator position, size_type n, const value_type& val)
			{
				// TODO
			}

			template <class InputIterator>
			void	insert(iterator position, InputIterator first, InputIterator last)
			{
				// TODO
			}

			iterator	erase(iterator position)
			{
				// TODO
			}
			
			iterator	erase(iterator first, iterator last)
			{
				// TODO
			}

			void	swap(vector& x)
			{
				ft::vector<value_type>		tmp = *this;
				
				// TODO
		
			}

			void	clear(void) // to test
			{
				for (size_type i = 0; i < this->_size; i++)
					this->_alloc.destroy(this->_ptr + i);
				this->_size = 0;
			}

		/* METHOD TO RETURN AN ALLOCATOR */
		
			allocator_type	get_allocator() const { return (this->_alloc); } ; // to test

		/* ITERATORS */

			iterator begin(void) { return iterator(this->_ptr); }; // to test
			
			const_iterator begin(void) const { return const_iterator(this->_ptr); }; // to test

			iterator end(void) { return iterator(this->_ptr + this->_size); }; // to test
			
			const_iterator end(void) const { return const_iterator(this->_ptr + this->_size); }; // to test

			reverse_iterator rbegin(void) { return reverse_iterator(this->_ptr); }; // to test
			
			const_reverse_iterator rbegin(void) const { return const_reverse_iterator(this->_ptr); }; // to test

			reverse_iterator rend(void) { return reverse_iterator(this->_ptn + this->_size); }; // to test
			
			const_reverse_iterator rend(void) const { return const_reverse_iterator(this->_ptn + this->_size); }; // to test

		private: // private member data

			allocator_type		_alloc;
			size_type			_size;
			size_type			_capacity;
			value_type			*_ptr;

		private: // private member methods (helpers)

			/* resize the vector capacity. Copy the values in the new array if there is enough space.
			Then, delete the values in the old arr, update_capacity and _size and make the pointer point
			to the new arr after freeing the old one */
			void	_change_mem_allocated(size_type n)
			{
				value_type		*new_arr;
				
				new_arr = this->_alloc.allocate(n); // allocate n contiguous blocks of mem
				for (size_type i = 0; i < this->_size && i < n; i++) // copy obj in new array (don't do it if not enough space)
					this->_alloc.construct(new_arr + i, this->at(i));
				for (size_type i = 0; i < this->_size; i++)
					this->_alloc.destroy(this->_ptr + i); // suppress all objects in old arr
				if (this->_size > n)
					this->_size = n;
				this->_ptr = new_arr;
				this->_capacity = n;
			}

			/* resize the vector capacity by a factor two (good ratio for performance) */
			void	_expand_mem_allocated(void) 
			{ 
				if (this->_capacity * 2 <= this->max_size())
					this->_change_mem_allocated(this->_capacity * 2);
				else if (this->_capacity == this->max_size())
					return ;
				else
					this->_change_mem_allocated(this->max_size());
			}

			/* change the position of all a sequence of objects in vector
			(if n is positive, in the right direction, left otherwise) */
			void	_shift_objs_in_vect(iterator pos, int n)
			{
				ft::vectorIterator<value_type>		it;
				ft::vector<value_type>				tmp;

				// copy the arr int a tmp vect
				for (size_type i = 0; i < this->_size; i++)
					tmp.push_back(this->at(i));
				// iterate through the arr 				
				it = this->begin();
				while (it != pos)
					it++;
				// destroying value to create a "hole" in the array
				while (it != (pos + n))
				{
					this->_alloc.destroy(it->()); // functionnal ?
					it++;
				}
				tmp.clear(); // useful ?
			}

			void	_fulfill_hole_in_vect() // useful ? 
			{
				
			}
	};
	
	/* OUT OF THE CLASS OVERLOADS FOR OPERATORS */

	template <class T, class Alloc>
	bool operator==(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		// TODO
	}

	template <class T, class Alloc>
	bool operator!=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		// TODO
	}
	template <class T, class Alloc>
	bool operator<(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		// TODO
	}

	template <class T, class Alloc>
	bool operator<=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		// TODO
	}

	template <class T, class Alloc>
	bool operator>(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		// TODO
	}

	template <class T, class Alloc>
	bool operator>=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		// TODO
	}

	template <class T, class Alloc>
	void swap(vector<T,Alloc>& x, vector<T,Alloc>& y)
	{
		// TODO
		
		/* This is an overload of the generic algorithm swap that improves its performance by mutually transferring 
		ownership over their assets to the other container (i.e., the containers exchange references to their data, 
		without actually performing any element copy or movement): 
		It behaves as if x.swap(y) was called. */
	}
}

#endif
