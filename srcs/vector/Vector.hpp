/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:25:35 by cjulienn          #+#    #+#             */
/*   Updated: 2022/11/14 16:32:17 by cjulienn         ###   ########.fr       */
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
			explicit vector(const allocator_type& alloc = allocator_type()) : _ptr(nullptr),
			_size(0), _capacity(0), _alloc(alloc) {}

			/* vector filled with scalar or objects */
			explicit vector(size_type n, const value_type& val = value_type(),
				const allocator_type& alloc = allocator_type()) : _ptr(nullptr), _size(0), _capacity(0), _alloc(alloc)
			{
				this->assign(n, val);
			}

			/* fill with a range of iterators */
			template <class InputIterator>
			vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type())
			{
				// TODO : implement, including initializing values			
			}

			/* copy constructor */
			vector(const vector& x) : _ptr(x._ptr), _size(x._size), _capacity(x._capacity), _alloc(x._alloc) 
			{
				// TODO : implement, including initializing values
			}

			/* destructor */
			virtual ~vector()
			{
				// TODO : implement => should " This destroys all container elements,
				// and deallocates all the storage capacity allocated by the vector using its allocator. "
			}

			/* overloading operator = */
			vector& operator=(const vector& x)
			{
				if (this != &x)
				{
					// TODO
				}
				return *this;
			}
		
		/* METHODS RELATIVE TO VECTOR CAPACITY */

			size_type	size(void) const
			{
				// TODO
				/* return the number of elements in the array */
			}

			size_type	max_size(void) const
			{
				// TODO
				/* Returns the maximum number of elements that the vector can hold. */  
			}

			void	resize(size_type n, value_type val = value_type())
			{
				// TODO
			}

			size_type	capacity(void) const
			{
				// TODO
			}

			bool	empty(void) const
			{
				// TODO
			}

			void	reserve(size_type n)
			{
				// TODO
			}
			
		/* METHODS RELATIVE TO VECTOR'S ELEMENT ACCESS */

			/* returns a reference to the element at position n in the vector container.
			can segfault if out-of-range-index */
			reference	operator[](size_type n) { return *(this + n); };

			/* returns a const reference to the element at position n in the vector container. 
			can segfault if out-of-range-index */
			const_reference	operator[](size_type n) const { return *(this + n); };

			/* returns a reference to the element at position n in the vector container.
			if index is wrong, throw a out-of-range-index exception */
			reference	at(size_type n)
			{
				if (n >= this->_size)
					; // throw out of range exception
				return (this->operator[](n));
			}
			
			/* returns a const reference to the element at position n in the vector container.
			if index is wrong, throw a out-of-range-index exception */
			const_reference	at(size_type n) const
			{
				if (n >= this->_size)
					; // throw out of range exception
				return (this->operator[](n));
			}
			
			/* returns a reference to the first value stored in vector */
			reference	front(void) { return (*this->_ptr); };
			
			/* returns a const reference to the first value stored in vector */
			const_reference	front(void) const { return (*this->_ptr); };

			/* returns a reference to the last value stored in vector */
			reference	back(void) { return (*this->_ptr + this->_size); }; 
						
			/* returns a reference to the last value stored in vector */
			const_reference	back(void) const { return (*this->_ptr + this->_size); };

			/* returns a pointer to the memory array used internally by the vector */
			value_type*	data(void) { return this->_ptr ; };

			/* returns a const pointer to the memory array used internally by the vector */
			const value_type* data(void) const { return this->_ptr ; };
			
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
				this->insert(this->begin(), 1, val);
			}

			void	pop_back(void)
			{
				// TODO	
			}

			iterator	insert(iterator position, const value_type& val)
			{
				// TODO	
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
				// TODO
			}

			void	clear(void)
			{
				// TODO
			}

		/* METHOD TO RETURN AN ALLOCATOR */
		
			allocator_type	get_allocator() const { return (this->_alloc); } ;

		private: // private member data

			allocator_type		_alloc;
			size_type			_size;
			size_type			_capacity;
			value_type			*_ptr;
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
