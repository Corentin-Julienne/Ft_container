/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redBlackTree.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:52:56 by cjulienn          #+#    #+#             */
/*   Updated: 2022/11/22 19:16:24 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RED_BLACK_TREE_HPP
# define RED_BLACK_TREE_HPP

# define RED		true
# define BLACK		false

#include <functional>
#include <memory>
#include <iostream>
#include <string>

#include "Node.hpp"

namespace lab
{
	template < 
		class Key, 
		class T,
		class Cmp = std::less<Key>,
		class Alloc = std::allocator<std::pair<const Key, T> >
	> 
	class redBlackTree
	{			
		
		public:

			/* ALIASES */
			typedef Key									key_type;
			typedef T									mapped_type;
			typedef std::pair<const Key, T>				value_type;
			typedef std::size_t							size_type;
			typedef Cmp									key_compare;
			typedef Node<const Key, T>					node;

			/* CONSTRUCTORS AND DESTRUCTORS */
			redBlackTree() : _root(nullptr), _nil(nullptr), _size(0), _key_comparator(Cmp()), _node_alloc(Alloc()) {}

			~redBlackTree()
			{
				// TO IMPLEMENT
			}

			/**/
			
		private:

			node		*_root;
			node		*_nil;
			size_type	_size;
			Cmp			_key_comparator;
			Alloc		_node_alloc;

		private:

			/* STANDARD BST FUNCTIONS */
			void	_treeInsert(node *z) // to test
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

			/* should be used with start == this->_root */
			node	*_treeDelete(node *start, const Key key) // to test
			{
				if (start == nullptr)
					return (nullptr);
				else if (key < start->_val.first)
					start->_left = this->_treeDelete(start->_left, key);
				else if (key > start->_val.first)
					start->_right = this->_treeDelete(start->_right, key);
				else
				{
					if (start->_left == nullptr && start->_right == nullptr)
					{
						this->_delete_node(start);
						start = nullptr;
					}
					else if (start->_left == nullptr)
					{
						node	*tmp = start;
						
						start = start->_right;
						this->_delete_node(tmp);
					}
					else if (start->_right == nullptr)
					{
						node	*tmp = start;
						
						start = start->_left;
						this->_delete_node(tmp);	
					}
					else
					{
						node	*tmp = _treeMinimum(start->_right);

						start->_val.first = tmp->_val.first;
						start->_right = _treeDelete(start->_right, tmp->_val.first);
					}
					return (start);
				}
			}

			/* RBT FUNCTIONS */

			
	};
}

#endif
