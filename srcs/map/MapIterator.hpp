/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MapIterator.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:41:03 by cjulienn          #+#    #+#             */
/*   Updated: 2022/12/13 18:06:09 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_ITERATOR_HPP
# define MAP_ITERATOR_HPP

# include "../utils/iteratorTraits.hpp"
# include "../utils/enableConst.hpp"
# include "../utils/pair.hpp"
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
	class mapIterator
	{

		public:

			/* ALIASES */
			
			typedef std::bidirectional_iterator_tag												iterator_category;
			typedef Key																			key_type;
			typedef T																			mapped_type;
			typedef ft::pair<const Key, T> 														value_type;		
			typedef std::ptrdiff_t																difference_type;
			typedef std::size_t																	size_type;
			typedef typename ft::enable_const<IsConst, *value_type, const *value_type>::type	pointer;
			typedef typename ft::enable_const<IsConst, &value_type, const &value_type>::type	reference;

		private:

			typedef Node<Key, T>			node;

		public:

			/* CONSTRUCTORS, DESTRUCTORS, OVERLOAD OPERATOR = */
			
			mapIterator(void) : _node(nullptr), _end_reached(false) {}; // to test

			mapIterator(node *target) : _node(target), _end_reached(false) // to test
			{
				if (target == nullptr)
					this->_end_reached = true;
			}

			mapIterator(const mapIterator<Key, T, IsConst> &original) : _node(original._node),
			_end_reached(original._end_reached) {}; // to test

			~mapIterator() {}; // to test
			
			mapIterator&	operator=(const mapIterator<Key, T> &original) // to test
			{
				if (this != &original)
				{
					this->_node = original._node;
					this->_end_reached = original._end_reached;
				}
				return *this;
			}

			/* OVERLOADS OPERATORS */
			mapIterator&	operator++(void) // to test
			{
				node		*tmp = this->_node;

				tmp->getTreeSucc(tmp);
				if (tmp == nullptr)
					this->_end_reached = true;
				else
					this->_node = tmp;
				return *this;
			}

			mapIterator&	operator--(void) // to test
			{
				node		*tmp = this->_node;
				
				tmp->getTreePred(tmp);
				if (tmp == nullptr)
					this->_end_reached = true;
				else
					this->_node = tmp;
				return *this;
			}

			mapIterator&	operator++(int) // to test
			{
				mapIterator		tmp(*this);
				
				++(*this);
				return (tmp);
			}

			mapIterator&	operator--(int) // to test
			{
				mapIterator		tmp(*this);
				
				--(*this);
				return (tmp);
			}

			reference	operator*(void) const // to test
			{
				return (this->_node->_val);			
			}

			pointer		operator->(void) const // to test
			{
				return (&this->_node->_val);
			}

			/* EQUIVALENCY OPERATORS */

			friend bool	operator==(const mapIterator &alpha, const mapIterator &bravo)
			{
				// TO IMPLEMENT
			}

			friend bool	operator!=(const mapIterator &alpha, const mapIterator &bravo)
			{
				// TO IMPLEMENT
			}

		private:

			node		*_node;
			bool		_end_reached;
	};
}

#endif
