/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redBlackTree.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:52:56 by cjulienn          #+#    #+#             */
/*   Updated: 2022/11/23 16:42:36 by cjulienn         ###   ########.fr       */
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
		class Alloc = std::allocator<std::pair<const Key, T> > > 
	class redBlackTree
	{			
		public:

			/* ALIASES */
			typedef Key									key_type;
			typedef T									mapped_type;
			typedef std::pair<const Key, T>				value_type;
			typedef std::size_t							size_type;
			typedef Alloc								allocator_type;
			typedef Node<const Key, T>					node;

			/* CONSTRUCTORS AND DESTRUCTORS */
			redBlackTree() : _root(nullptr), _nil(nullptr), _size(0), _pair_alloc(Alloc()) 
			{
				this->_node_alloc = std::allocator<node>();
			}

			~redBlackTree()
			{
				this->postOrderTraversal(this->_root);
			}

			redBlackTree(const redBlackTree &original) : _root(original._root), _nil(original._nil), _size(original._size),
			_pair_alloc(original._pair_alloc), _node_alloc(original._node_alloc) {};

			redBlackTree&	operator=(const redBlackTree &original)
			{
				if (this != &original)
				{
					this->_root = original._root;
					this->_nil = original._nil;
					this->_size = original._size;
					this->_node_alloc = original._node_alloc;
				}
				return *this;
			}

			/* UTILS */

			void	add_and_insert(const value_type &val) // to test
			{
				node		*newNode = this->_createNewNode(val);
				
				this->_treeInsert(newNode);
			}

			/* to cover the full tree, elem must be equal to this->_root */
			void	postOrderTraversal(node *elem) // to test
			{
				if (elem != nullptr)
				{
					this->postOrderTraversal(elem->_left);
					this->postOrderTraversal(elem->_right);
					this->_deleteNode(elem);
				}
			}

			void	printTree(void)
			{
				if (this->_root == nullptr)
					return ;
				this->_printTree(this->_root, "", true);
			}

			void	printTreeDebug(void)
			{
				
			}
			
		private:

			node					*_root;
			node					*_nil;
			size_type				_size;
			allocator_type			_pair_alloc;
			std::allocator<node>	_node_alloc;

		private:

			/* HELPERS */

			void	_deleteNode(node *target) // to test
			{
				this->_pair_alloc.destroy(&target->_val);
				this->_node_alloc.deallocate(target, 1);
			}

			node	*_createNewNode(const value_type &val) // check if useful
			{
				node		*newNode = this->_node_alloc.allocate(1); // alloc space for a node

				this->_node_alloc.construct(&newNode->_val, val); // create obj std::pair to implement in node
				newNode->_color = RED;
				newNode->_parent = nullptr;
				newNode->_right = nullptr;
				newNode->_left = nullptr;
				// debug
				// std::cout << "color = " << newNode->_color << std::endl;
				// std::cout << "parent = " << newNode->_parent << std::endl;
				// std::cout << "left =  " << newNode->_left << std::endl;
				// std::cout << "right = " << newNode->_right << std::endl;
				// debug end
				return (newNode);
			}

			/*  indent should be equal to "" and last to true (and node to this->_root) */
			void	_printTree(node *target, std::string indent, bool last)
			{
				if (target != nullptr)
				{
					if ()
					
					
					if (last == true)
					{
						std::cout << indent;
						std::cout << "└────";
						indent += "    ";
					}
					else
					{
						std::cout << indent;
						std::cout << "├────";
						indent += "|    ";
					}
					std::cout << root->_val.first << " = " << root->_val.second << std::endl;
				}
				else
					return ;
				this->_printTree(root->_left, indent, false);
				this->_printTree(root->_right, indent, true);
			}
 
			
			/* STANDARD BST FUNCTIONS */
			void	_treeInsert(node *z) // to test // debug that shit !!!
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
						node	*tmp = getTreeMin(start->_right);

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
