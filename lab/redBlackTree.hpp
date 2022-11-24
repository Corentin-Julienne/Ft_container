/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redBlackTree.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:52:56 by cjulienn          #+#    #+#             */
/*   Updated: 2022/11/24 17:32:03 by cjulienn         ###   ########.fr       */
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

			void	addAndInsert(const value_type &val) // to test
			{
				node		*newNode = this->_createNewNode(val);
				
				this->_treeInsert(newNode);
			}

			void	deleteNode(const Key &key)
			{
				this->_treeDelete(this->_root, key);
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

			/* print the tree in 2D : the root value appears in the center of the vertical axis,
			in the left side of the terminal. Debug and visual function */
			void	printTree(void)
			{
				if (this->_root == nullptr)
					return ;
				this->_printTree(this->_root, 0);
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
				target = nullptr;
			}

			node	*_createNewNode(const value_type &val) // check if useful
			{
				node		*newNode = this->_node_alloc.allocate(1); // alloc space for a node

				this->_node_alloc.construct(&newNode->_val, val); // create obj std::pair to implement in node
				newNode->_color = RED;
				newNode->_parent = nullptr;
				newNode->_right = nullptr;
				newNode->_left = nullptr;
				return (newNode);
			}

			/*  space should be equal to 0, target to this->_root */
			void	_printTree(node *target, int space) // functionnal
			{
				const int	indent = 5;
				
				if (target ==  nullptr)
					return ;
				space += indent;
				this->_printTree(target->_right, space);
				// prints data
				std::cout << std::endl;
				for (int i = indent; i < space; i++)
        			std::cout << " ";
				std::cout << "[" << target->_val.first << "]" << std::endl;
				
				this->_printTree(target->_left, space);
			}
			
			/* STANDARD BST FUNCTIONS */
			void	_treeInsert(node *z) // functionnal
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
				if (start == nullptr) // case target is NULL
					return (nullptr);
				else if (key < start->_val.first) // case key inferior to start node
					start->_left = this->_treeDelete(start->_left, key);
				else if (key > start->_val.first) // case key superior to start node
					start->_right = this->_treeDelete(start->_right, key);
				else // we reach node target, now we have to make relevant ops
				{
					if (start->_left == nullptr && start->_right == nullptr) // case target got no child
					{
						this->_deleteNode(start);
						start = nullptr;
					}
					else if (start->_left == nullptr) // case target got only right child
					{
						node	*tmp = start;
						
						start = start->_right;
						this->_deleteNode(tmp);
						tmp = nullptr;
					}
					else if (start->_right == nullptr) // case target got only left child
					{
						node	*tmp = start;
						
						start = start->_left;
						this->_deleteNode(tmp);
						tmp = nullptr;
					}
					else // case taget has two children node left and right
					{
						node	*tmp = this->_root->getTreeMin(start->_right);
						node	*newNode = this->_replace_key(start, tmp->_val);
						
						this->_deleteNode(start);
						start = newNode;
						start->_right = _treeDelete(start->_right, tmp->_val.first);
					}
				}
				return (start);
			}

			/* create a copy of a node, but with another key,
			then replace links from other links from target to newNode */
			node	*_replace_key(node *target, value_type newPair) // to test
			{
				node	*newNode = this->_createNewNode(newPair);

				newNode->_color = target->_color;
				newNode->_parent = target->_parent;
				newNode->_left = target->_left;
				newNode->_right = target->_right;
				if (target->_parent != nullptr)
				{
					if (target->_parent->_right
						&& target->_parent->_right->_val.first == target->_val.first)
						target->_parent->_right = newNode;
					else
						target->_parent->_left = newNode;
				}
				if (target->_right != nullptr)
					target->_right->_parent = newNode;
				if (target->_left != nullptr)
					target->_left->_parent = newNode;
				return (newNode);
			}

			/* returns a copy of a dinamically allocated node (not shallow copy) */
			node	*_copyNode(node *target)
			{
				node	*cpy = this->_createNewNode(target->_val);
				
				cpy->_color = target->_color;
				cpy->_parent = target->_parent;
				cpy->_left = target->_left;
				cpy->_right = target->_right;
				return (cpy);
			}
			
			/* RBT FUNCTIONS */

			/* Basic rule of red-black tree :

			1) Every node in T is either red or black.
			2) The root node of T is black.
			3) Every NULL node is black. (NULL nodes are the leaf nodes. They do not contain any keys.
			When we search for a key that is not present in the tree, we reach the NULL node.)
			4) If a node is red, both of its children are black. This means no two nodes on a path can be red nodes.
			5) Every path from a root node to a NULL node has the same number of black nodes.*/

			void	_leftRotate(node *x) // to test
			{
				node	*y = x->_right;
				
				x->_right = y->_left;
				if (x->_right != nullptr)
					x->_right->_parent = x;
				y->_parent = x->_parent;
				if (y->_parent != nullptr)
				{
					if (y->_parent->_left->_val.first == y->_val.first) // case y is the left node
						y->_parent->_left = y;
					else // case y is the right node
						y->_parent->_right = y;
				}
				y->_left = x;
				x->_parent = y;
			}

			void	_rightRotate(node *y) // to test
			{
				node	*x = y->_left;

				y->_left = x->_right;
				if (x->_right != nullptr)
					x->_right->_parent = y;
				x->_parent = y->_parent;
				if (x->_parent != nullptr)
				{
					if (x->_parent->_left->_val.first == x->_val.first) // case x is the left node
						x->parent->_left = x;
					else // case x is the right node
						x->_parent->_right = x;
				}
				x->_right = y;
				y->_parent = x;
			}

			void	_redBlackTreeInsert(node *newNode) // to test a lot
			{
				this->_treeInsert(newNode); // standard BST insertion
				if (newNode->_parent == nullptr) // case of root insertion
					return ;
				newNode->_color = RED; // coloring the node in red, by default
				while (newNode->_parent->_color == RED) // if parent is black, do nothing, does not violates RBT rules
				{
					/* newNode->_parent->_parent is always accesible because when root is newNode->_parent,
					then it is always black and the while condition is never met */
					if (newNode->_parent->_val.first == newNode->_parent->_parent->_right->_val.first)
					{
						node	*uncle = newNode->_parent->_parent->_left;  // case uncle is situated at the left of node

						if (uncle->_color == RED)
						{
							uncle->_color = BLACK; // changing color of the uncle to black
							newNode->_parent->_color = BLACK; // changing color of the parent to black
							newNode->_parent->_parent->_color = RED; // changing color of GP to red
							newNode = newNode->_parent->_parent;
						}
						else if (newNode == newNode->_parent->_left) // case new node is situated at the left
						{
							newNode = newNode->_parent;
							this->_leftRotate(newNode); // to implement
							newNode->_parent->_color = BLACK;
							newNode->_parent->_parent->_color = RED;
							this->_rightRotate(newNode); // to implement
						}
					}
					else // case uncle is situated at the right of the node
					{
						node	*uncle = newNode->_parent->_parent->_right;

						if (uncle->_color == RED)
						{
							uncle->_color = BLACK;
							newNode->_parent->_color = BLACK;
							newNode->_parent->_parent->_color = RED;
							newNode = newNode->_parent->_parent;
						}
						else if (newNode == newNode->_parent->_right)
						{
							newNode = newNode->_parent;
							this->_rightRotate(newNode); // to implement
							newNode->_parent->_color = BLACK;
							newNode->_parent->_parent->_color = RED;
							this->_leftRotate(newNode); // to implement
						}
					}
				}
				this->_root->_color = BLACK; // rule 2 : root node is ALLWAYS black
			}

			void	_redBlackTreeDelete(node *start, node *target)
			{
				this->_treeDelete(start, target->_val.first); // standard BST deletion
				while (target != this->_root && target->_color == BLACK) // if node is RED, nothing to do
				{
					if (target == target->_parent->_left)
					{
						node	*sibling = target->_parent->_right;

						if (sibling->_color == RED)
						{
							
						}
						if (sibling->_left->_color == BLACK && sibling->_right->_color == BLACK)
						{

						}
						else if (sibling->_right->_color == BLACK)
						{
							
						}
					}
					else
					{
						
					}
				}
				target->_color = BLACK;
			}
			
	};
}

#endif
