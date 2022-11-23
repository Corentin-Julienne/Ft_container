/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:52:54 by cjulienn          #+#    #+#             */
/*   Updated: 2022/11/23 13:43:24 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_HPP
# define NODE_HPP

#include <functional>
#include <memory>
#include <iostream>
#include <string>

namespace lab
{
	template <typename Key, typename T>
	class Node
	{
		
		public:
			
			/* ALIASES */
			typedef Key										key_type;
			typedef T										mapped_type;
			typedef std::pair<const Key, T>					value_type;
			typedef typename std::size_t 					size_type;
			typedef typename std::ptrdiff_t 				difference_type;
			
			/* CONSTRUCTORS AND DESTRUCTORS, OVERLOADING OPERATOR = */

			Node(value_type pair) : _color(RED), _parent(nullptr), _left(nullptr), _right(nullptr), _val(pair) {};
			
			~Node() {}

			Node(const Node &original) : _val(original._val), _color(original._color), _parent(original._parent),
			_left(original._left), _right(original._right) {};

			Node&	operator=(const Node &original)
			{
				if (this != &original)
				{
					this->_val = original._val;
					this->_color = original._color;
					this->_parent = original._parent;
					this->_left = original._left;
					this->_right = original._right;
				}
				return *this;
			}

			/* GETTERS */

			Node	*getTreeSearch(Node *x, const Key k) { return this->_treeSearch(x, k); };
			Node	*getTreeMin(Node *x) { return this->_treeMinimum(x); };
			Node	*getTreeMax(Node *x) { return this->_treeMaximun(x); };
			Node	*getTreeSucc(Node *x) { return this->_treeSuccessor(x); };
			Node	*getTreePred(Node *x) { return this->_treePredecessor(x); };

		public:
		
			value_type			_val; // is a pair
			bool				_color;
			Node				*_parent;
			Node				*_left;
			Node				*_right;

		private:

			Node	*_treeSearch(Node *x, const Key k) // to test
			{
				if (x == nullptr || k == x->_val.first)
					return (x);
				if (k < x->_val.first)
					return (_treeSearch(x->_left, k));
				else
					return (_treeSearch(x->_right, k));
			}

			Node	*_treeMinimum(Node *x) // to test
			{
				while (x->_left != nullptr)
					x = x->_left;
				return (x);
			}

			Node	*_treeMaximun(Node *x) // to test
			{
				while (x->_right != nullptr)
					x = x->_right;
				return (x);
			}

			Node	*_treeSuccessor(Node *x) // to test
			{
				if (x->_right != nullptr)
					return (_treeMinimum(x->_right));
				
				Node	*y = x->_parent;

				while (y != nullptr && x == y->_right)
				{
					x = y;
					y = y->_parent;
				}
				return (y);
			}

			Node	*_treePredecessor(Node *x) // to test
			{
				if (x->_left != nullptr)
					return (_treeMinimum(x->_left));
				
				Node	*y = x->_parent;

				while (y != nullptr && x == y->_left)
				{
					x = y;
					y = y->_parent;
				}
				return (y);
			}
	};
}

#endif
