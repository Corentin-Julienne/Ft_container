/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:40:57 by cjulienn          #+#    #+#             */
/*   Updated: 2022/11/17 13:45:35 by cjulienn         ###   ########.fr       */
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
			typedef pair<const Key, T> 						value_type;
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
			// reverse iterators
			typedef std::reverse_iterator<iterator> 		reverse_iterator;
			typedef std::reverse_iterator<const_iterator> 	const_reverse_iterator;

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
			explicit	map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
			{
				// TODO
			}

			/* range constructor */
			template <class InputIterator>
			map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), 
					const allocator_type& alloc = allocator_type())
			{
				// TODO
			}

			/* copy constructor */
			map(const map& x)
			{
				// TODO
			}

			/* destructor */
			virtual	~map()
			{
				// TODO
			}

			/* overloading operator = */
			map&	operator=(const map& x)
			{
				// TODO
			}

		/* METHODS RELATIVE TO MAP CAPACITY */

			bool	empty(void) const
			{
				// TODO
			}

			size_type	size(void) const
			{
				// TODO
			}

			size_type	max_size(void) const
			{
				// TODO
			}

		/* METHODS RELATIVE TO MAP'S ELEMENTS ACCESS */

			mapped_type&	operator[](const key_type& k)
			{
				// TODO
			}
		
			mapped_type&	at(const key_type& k)
			{
				// TODO
			}
			
			const mapped_type&	at(const key_type& k) const
			{
				// TODO
			}

		/* METHODS RELATIVE TO MAP MODIFICATION */

			pair<iterator,bool>	insert(const value_type& val)
			{
				// TODO
			}

			iterator	insert(iterator position, const value_type& val)
			{
				// TODO
			}

			template<class InputIterator>
			void	insert(InputIterator first, InputIterator last)
			{
				// TODO
			}

			void	erase(iterator position)
			{
				// TODO
			}

			size_type	erase(const key_type& k)
			{
				// TODO
			}

			void	erase(iterator first, iterator last)
			{
				// TODO
			}

			void	swap(map& x)
			{
				// TODO
			}

			void	clear(void)
			{
				// TODO
			}

		/* METHODS USED FOR OPERATIONS */

			
		
		/* METHOD FOR GETTING ALLOCATORS */
		
			allocator_type	get_allocator(void) const
			{
				// TODO
			}
	};
	
	template <class Key, class T, class Compare, class Alloc>
	bool	operator==(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
	{
		// TODO
	}

	template <class Key, class T, class Compare, class Alloc>
	bool	operator!=(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
	{
		// TODO
	}

	template <class Key, class T, class Compare, class Alloc>
	bool	operator<(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
	{
		// TODO
	}

	template <class Key, class T, class Compare, class Alloc>
	bool	operator<=(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
	{
		// TODO
	}

	template <class Key, class T, class Compare, class Alloc>
	bool	operator>(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
	{
		// TODO
	}

	template <class Key, class T, class Compare, class Alloc>
	bool	operator>=(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
	{
		// TODO
	}

	template < class Key, class T, class Compare, class Alloc >
	void	swap(map<Key, T, Compare, Alloc>& lhs, map<Key, T, Compare, Alloc>& rhs)
	{
		// TODO
	}
}

#endif
