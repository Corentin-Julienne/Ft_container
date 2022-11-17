/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binarySearchTree.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:38:37 by cjulienn          #+#    #+#             */
/*   Updated: 2022/11/17 17:52:33 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINARY_SEARCH_TREE_HPP
# define BINARY_SEARCH_TREE_HPP

#include <functional>
#include <memory>
#include <iostream>

#include "Node.hpp"

# define RED		true
# define BLACK		false

template<typename Key, typename T, typename Cmp = std::less<Key>, 
typename Allocator = std::allocator<std::pair<const Key, T> > >
class binarySearchTree
{
	
	public:

		/* ALIASES */
		typedef Key									key_type;
		typedef T									mapped_type;
		typedef std::pair<const Key, T>				value_type;
		typedef std::size_t							size_type;
		typedef Node<const Key, T>					node;

		/* CONSTRUCTORS, DESTRUCTORS, OVERLOADING OPERATOR = */
		binarySearchTree(void) : _root(nullptr), _nil(nullptr), _size(0), _key_comparator(Cmp()),
		_tree_alloc(Allocator())
		{
			
		}
		
		~binarySearchTree();

		/* BST FUNCTIONS */

		node	*treeSearch(node *x, const Key k) // to test
		{
			if (x == nullptr || k == x->_val.first)
				return (x);
			if (k < x->_val.first)
				return (x->_left, k);
			else
				return (x->_right, k);
		}

		node	*treeMinimum(node *x) // to test
		{
			while (x->_left != nullptr)
				x = x->_left;
			return (x);
		}

		node	*treeMaximun(node *x) // to test
		{
			while (x->_right != nullptr)
				x = x->_right;
			return (x);
		}

		node	*treeSuccessor(node *x) // to test
		{
			if (x->_right != nullptr)
				return (treeMinimum(x->_right));
			
			node	*y = x->_parent;

			while (y != nullptr && x == y->_right)
			{
				x = y;
				y = y->_parent;
			}
			return (y);
		}

		node	*treePredecessor(node *x) // to test
		{
			if (x->_left != nullptr)
				return (treeMinimum(x->_left));
			
			node	*y = x->_parent;

			while (y != nullptr && x == y->_left)
			{
				x = y;
				y = y->_parent;
			}
			return (y);
		}

		void	treeInsert(node *z) // to test
		{
			node		*y = nullptr;
			node		*x = this->_root;

			while (x != nullptr)
			{
				y = x;
				if (z->_val.first < x->_val.first)
					x = x->_left;
				else
					x = x->_right;
			}
			z->_parent = y;
			if (y == nullptr)
				this->_root = z;
			else if (z->_val.first < y->_val.first)
				y->_left = z;
			else
				y->_right = z;
		}

		node	*treeDelete(node *target, const Key key) // to test
		{
			if (target == nullptr)
				return (nullptr);
			else if (key < target->_val.first)
				target->_left = this->treeDelete(target->_left, key);
			else if (key > target->_val.first)
				target->_right = this->treeDelete(target->_right, key);
			else
			{
				if (target->_left == nullptr && target->_right == nullptr)
				{
					// delete target there
					target = nullptr;
				}
				else if (target->_left == nullptr)
				{
					node	*tmp = target;
					
					target = target->_right;
					// delete tmp there 
				}
				else if (target->_right == nullptr)
				{
					node	*tmp = target;
					
					target = target->_left;
					// delete tmp there 	
				}
				else
				{
					node	*tmp = treeMinimum(target->_right);

					target->_val.first = tmp->_val.first;
					target->_right = treeDelete(target->_right, tmp->_val.first);
				}
				return (target);
			}
		}
 
		/* RBT FUNCTIONS */
		
	private:

		/* PRIVATE ATTRIBUTES */
		node					*_root;
		node					*_nil;
		size_type				_size;
		Cmp						_key_comparator;
		Allocator				_tree_alloc;
		std::allocator<node>	_nodeAlloc;

	private:

		/* HELPER FUNCTIONS */
		
		
};

#endif
