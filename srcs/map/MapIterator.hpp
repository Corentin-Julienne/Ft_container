/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MapIterator.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:41:03 by cjulienn          #+#    #+#             */
/*   Updated: 2022/11/28 11:59:50 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_ITERATOR_HPP
# define MAP_ITERATOR_HPP

# include "../utils/iteratorTraits.hpp"
# include "../utils/enableConst.hpp"
# include "./Node.hpp" // add this

# include <limits>
# include <memory>
# include <vector>
# include <cstddef>
# include <sstream>
# include <functional>

# include <iterator>

namespace ft
{
	template <class Key, class T, bool IsConst = false> // non const by default
	class MapIterator
	{

		public:

			/* ALIASES */
			typedef Key																			key_type;
			typedef T																			mapped_type;
			typedef std::pair<const Key, T> 													value_type;		
			typedef std::ptrdiff_t																difference_type;
			typedef std::size_t																	size_type;
			typedef typename ft::enable_const<IsConst, *value_type, const *value_type>::type	pointer;
			typedef typename ft::enable_const<IsConst, &value_type, const &value_type>::type	reference;

		private:

			typedef Node<Key, T>			node;

		public:

			/* CONSTRUCTORS, DESTRUCTORS, OVERLOAD OPERATOR = */
			
			MapIterator(void) : _node(nullptr), _end_reached(false) {};

			MapIterator(const MapIterator<Key, T, IsConst> &original) : _node(original._node), _end_reached(original._end_reached) {};

			~MapIterator() {};
			
			MapIterator&	operator=(const MapIterator<Key, T> &original)
			{
				if (this != &original)
				{
					this->_node = original._node;
					this->_end_reached = original._end_reached;
				}
				return *this;
			}

			/* OVERLOADS OPERATORS */
			MapIterator&	operator++(void)
			{
				node		*tmp = this->_node;

				tmp->getTreeSucc(tmp);
				if (tmp == nullptr)
					this->_end_reached = true;
				else
					this->_node = tmp;
				return *this;
			}

			MapIterator&	operator--(void)
			{
				node		*tmp;
				tmp->getTreePred(tmp);
				if (tmp == nullptr)
					this->_end_reached = true;
				else
					this->_node = tmp;
				return *this;
			}

			MapIterator&	operator++(int)
			{
				node		*tmp = this->_node;
				
				++this->_node;
				return (tmp);
			}

			MapIterator&	operator--(int)
			{
				node		*tmp = this->_node;
				
				--this->_node;
				return (tmp);
			}

			MapIterator&	operator*(void) const // dereferencing
			{

			}

			MapIterator*	operator->(void) const // give pointer address
			{
				
			}

			/* EQUIVALENCY OPERATORS */

			friend bool	operator==(const MapIterator &alpha, const MapIterator &bravo)
			{
				
			}

			friend bool	operator!=(const MapIterator &alpha, const MapIterator &bravo)
			{
				
			}

		private:

			node		*_node;
			bool		_end_reached;
	};
}

#endif
