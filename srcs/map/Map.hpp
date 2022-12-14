/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:40:57 by cjulienn          #+#    #+#             */
/*   Updated: 2022/12/13 19:03:36 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

/* includes */ // check this
# include <limits>
# include <memory>
# include <vector>
# include <cstddef>
# include <sstream>
# include <functional>

# include "../utils/pair.hpp"
# include "./mapIterator.hpp"
# include "../utils/reverseIterator.hpp"
# include "./redBlackTree.hpp"

namespace ft
{
	template < 
		class Key, 
		class T,
		class Compare = std::less<Key>,
		class Alloc = std::allocator<ft::pair<const Key,T> >
	> 
	class map
	{
		/* ALIASES */
		public:

			typedef Key										key_type;
			typedef T										mapped_type;
			typedef ft::pair<const Key, T> 					value_type;
			typedef Compare									key_compare;
			// put value compare there
			typedef Alloc									allocator_type;
			typedef typename Alloc::reference 				reference;
			typedef typename Alloc::const_reference 		const_reference;
			typedef typename Alloc::pointer					pointer;
			typedef typename Alloc::const_pointer			const_pointer;
			typedef typename std::size_t 					size_type;
			typedef typename std::ptrdiff_t 				difference_type;
			// iterators to put there
			typedef ft::mapIterator<Key, T>					iterator;
			typedef ft::mapIterator<Key, T, true>			const_iterator;
			typedef ft::reverseIterator<iterator> 			reverse_iterator;
			typedef ft::reverseIterator<const_iterator> 	const_reverse_iterator;
			// tree
			typedef ft::redBlackTree<Key, T, Alloc>			binary_tree;

		/* CLASS TO COMPARE KEYS */

			class value_compare // compare two keys using std::less 
			{
				friend class map;
				
				protected:
				
					Compare	comp;
					
					value_compare(Compare c) : comp(c) {} // protected constructor, usable by map only

				public:
				
					typedef bool				result_type;
					typedef value_type			first_argument_type;
					typedef value_type			second_argument_type;

					bool operator() (const value_type& x, const value_type& y) const
					{
						return comp(x._first_type, y._first_type);
					}
			};

		/* CONSTRUCTORS, DESTRUCTOR, COPY, OVERLOADING ASSIGNMENT OPERATOR (COPLIEN FORM) */

			/* default constructor, create empty map */
			explicit	map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) :
			 _tree(nullptr), _size(0) , _alloc(alloc), _comparator(comp) {} // to test

			/* range constructor */
			template <class InputIterator>
			map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), 
					const allocator_type& alloc = allocator_type()) : _tree(nullptr), _size(0),
					_alloc(alloc), _comparator(comp)  // to test
			{
				this->insert(first, last);
			}

			/* copy constructor */
			map(const map& x) : _tree(x._tree), _size(0), _alloc(x._alloc), _comparator(x._comparator) {}; // to test

			/* destructor */
			virtual	~map() // to test
			{
				if (this->size() >= 2)
					this->erase(this->begin(), this->end());
				else if (this->size() == 1)
					this->erase(this->begin());
			}

			/* overloading operator = */
			map&	operator=(const map& x) // to test
			{
				if (this != &x)
				{
					this->_tree = x._tree;
					this->_size = x._size;
					this->_comparator = x._comparator;
					this->_alloc = x._alloc;
				}
				return *this;
			}

		/* MAP ITERATORS */
		
			iterator	begin(void) // to test
			{
				iterator	target(this->_tree->getMin());

				return (target);	
			}

			iterator	end(void) // to test
			{
				iterator	target(this->_tree->getMax());

				return (target);
			}

			const_iterator	cbegin(void) // to test
			{
				const_iterator		target(this->_tree->getMin());

				return (target);	
			}

			const_iterator	cend(void) // to test
			{
				const_iterator		target(this->_tree->getMax());

				return (target);
			}

			reverse_iterator	rbegin(void) // to test
			{
				reverse_iterator	target(this->_tree->getMin());

				return (target);	
			}

			reverse_iterator	rend(void) // to test
			{
				reverse_iterator	target(this->_tree->getMax());

				return (target);
			}

			const_reverse_iterator	crbegin(void) // to test
			{
				const_reverse_iterator		target(this->_tree->getMin());

				return (target);
			}

			const_reverse_iterator	crend(void) // to test
			{
				const_reverse_iterator		target(this->_tree->getMax());

				return (target);
			}
		
		/* METHODS RELATIVE TO MAP CAPACITY */

			bool	empty(void) const // to test
			{
				return (this->_tree->getSize() == 0);
			}

			size_type	size(void) const // to test
			{
				return (this->_tree->getSize());
			}

			size_type	max_size(void) const // to test
			{
				return (this->_alloc.max_size());
			}

		/* METHODS RELATIVE TO MAP'S ELEMENTS ACCESS */

			/* operator[] returns the value of a given key if it exists. Otherwise,
			it creates it and returns it */
			mapped_type&	operator[](const key_type& k) // to test
			{
				mapped_type		target = this->_tree.getValOfKey(k);

				if (target == nullptr)
					this->_tree->BinarySearchTreeInsertion(); // change this to RBT
				return (target);
			}
		
			/* returns the value of key if exists, otherwise throw out-of-range exception */
			mapped_type&	at(const key_type& k) // to test
			{
				mapped_type		target = this->_tree.getValOfKey(k);

				if (target == nullptr)
					throw std::out_of_range();
				return (target);
			}

			/* returns the value of key if exists, otherwise throw out-of-range exception */			
			const mapped_type&	at(const key_type& k) const // to test
			{
				const mapped_type		target = this->_tree.getValOfKey(k);

				if (target == nullptr)
					throw std::out_of_range();
				return (target);
			}

		/* METHODS RELATIVE TO MAP MODIFICATION */

			/* inserts a single element */
			pair<iterator, bool>	insert(const value_type& val) // to test
			{
				iterator	it = this->begin();

				// verif key does not exists
				if (this->_tree->IsKeyAlreadyExisting(val.first) == false)
				{
					while (it->first != val.first) // while *it is not equal to already existing key
						it++;
					return (ft::make_pair<iterator, bool>(it, false));
				}
				this->_tree->BinarySearchTreeInsertion(val); // replace by RBT insertion
				while (it->first != val.first) // while *it is not equal to inserted key
					it++;
				return (ft::make_pair<iterator, bool>(it, true));
			}

			/* insert a single value at iterators position */
			iterator	insert(iterator position, const value_type& val) // pb understanding
			{
				// TODO
			}

			/* inserts a range of values */
			template<class InputIterator>
			void	insert(InputIterator first, InputIterator last) // to test
			{
				while (first != last)
				{
					this->_tree->BinarySearchTreeInsertion(*first); // replace by red black tree insertion	
					first++;
				}
			}

			/* erase some node at position position */
			void	erase(iterator position) // to test
			{
				this->_tree->deleteNode(position->first);
			}

			/* erase a range of size_type iterators */
			size_type	erase(const key_type& k) // to test
			{
				if (this->find(k) == this->end())
					return (0);
				this->erase(this->find(k));
				return (1);
			}

			/* erase a range of iterators */
			void	erase(iterator first, iterator last) // to test
			{
				while (first != last)
				{
					this->erase(first);
					first++;
				}
			}

			/* swap all the private attributes of two maps (this and x) */
			void	swap(map& x) // to test
			{	
				binary_tree					tmp_tree = x._tree;
				allocator_type				tmp_alloc = x._alloc;
				key_compare					tmp_comparator = x._comparator;

				x._tree = this->_tree;
				x._alloc = this->_alloc;
				x._comparator = this->_comparator;

				this->_tree = tmp_tree;
				this->_alloc = tmp_alloc;
				this->_comparator = tmp_comparator;
			}

			/* delete all nodes and values */
			void	clear(void) // to test
			{
				this->_tree->postOrderTraversalDeletion(this->_tree->getRoot());
			}

		/* OBSERVERS */

			key_compare	key_comp() const
			{
				// TO IMPLEMENT
			}

			value_compare	value_comp() const
			{
				// TO IMPLEMENT
			}

		/* METHODS USED FOR OPERATIONS */

			/* Searches the container for an element with a key equivalent to k
			and returns an iterator to it if found, otherwise it returns an iterator to map::end. */
			iterator	find(const key_type& k) // to test
			{
				iterator		res = this->begin();
				
				while (res != this->end())
				{
					if ((*res).first == k)
						break ;
					res++;
				}
				return (res);
			}

			/* Searches the container for an element with a key equivalent to k
			and returns an iterator to it if found, otherwise it returns an iterator to map::end. */
			const_iterator	find(const key_type& k) const // to test
			{
				iterator		res = this->begin();
				
				while (res != this->end())
				{
					if ((*res).first == k)
						break ;
					res++;
				}
				
				const_iterator	const_res(res); // check this
				
				return (const_res);
			}

			/* Searches the container for elements with a key equivalent to k and returns the number of matches.
			There is no duplicte keys in map, so result is either 0 or 1 */
			size_type	count(const key_type& k) const // to test
			{
				if (this->find(k) == this->end())
					return (0);
				return (1);
			}

			/* return either the key if existing or the first elem that is not less than key k */
			iterator	lower_bound(const key_type& k) // to test
			{
				iterator		it = this->begin();

				while (it != this->end())
				{
					if (key_comp((*it).first, k) == false)
						break ;
					it++;
				}
				return (it);
			}

			const_iterator	lower_bound(const key_type& k) const // to test
			{
				iterator		it = this->begin();

				while (it != this->end())
				{
					if (key_comp((*it).first, k) == false)
						break ;
					it++;
				}
				
				const_iterator	it_const(it);

				return (it_const);				
			}

			/* return either the next if key exists or the element after the first elem that is not less than key k */
			iterator	upper_bound(const key_type& k) // to test
			{
				iterator		it = this->begin();

				while (it != this->end())
				{
					if (key_comp((*it).first, k) == false)
						break ;
					it++;
				}
				it++;
				return (it);
			}

			const_iterator	upper_bound(const key_type& k) const // to test
			{
				iterator		it = this->begin();

				while (it != this->end())
				{
					if (key_comp((*it).first, k) == false)
						break ;
					it++;
				}
				it++;
				
				const_iterator	it_const(it);

				return (it_const);	
			}
			
			/* returns a pair with first elem equal to lower_bound and second second elem equal to upper_bound */
			pair<iterator,iterator>	equal_range(const key_type& k) // to test
			{
				iterator		lower = this->lower_bound(k);
				iterator		upper = this->upper_bound(k);

				return (ft::make_pair<iterator, iterator>(lower, upper));
			}

			pair<const_iterator,const_iterator>	equal_range(const key_type& k) const // to test
			{
				const_iterator		lower = this->lower_bound(k);
				const_iterator		upper = this->upper_bound(k);

				return (ft::make_pair<const_iterator, const_iterator>(lower, upper));
			}
		
		/* METHOD FOR GETTING ALLOCATORS */
		
			allocator_type	get_allocator(void) const // to test
			{
				return (this->_alloc);
			}
		
		private:

			binary_tree			*_tree;
			size_type			_size;
			allocator_type		_alloc;
			key_compare			_comparator;
	};
	
	template <class Key, class T, class Compare, class Alloc>
	bool	operator==(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs) // to test
	{
		if (lhs.size() != rhs.size())
			return (false);
		else
			return (equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	template <class Key, class T, class Compare, class Alloc>
	bool	operator!=(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs) // to test
	{
		return (!lhs == rhs);
	}

	template <class Key, class T, class Compare, class Alloc>
	bool	operator<(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs) // to test
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()); // ?
	}

	template <class Key, class T, class Compare, class Alloc>
	bool	operator<=(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs) // to test
	{
		return (!(rhs < lhs));
	}

	template <class Key, class T, class Compare, class Alloc>
	bool	operator>(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs) // to test
	{
		return (rhs < lhs);
	}

	template <class Key, class T, class Compare, class Alloc>
	bool	operator>=(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs) // to test
	{
		return (!(lhs < rhs));
	}

	template <class Key, class T, class Compare, class Alloc>
	void	swap(map<Key, T, Compare, Alloc>& lhs, map<Key, T, Compare, Alloc>& rhs) { x.swap(y); }; // to test
}

#endif
