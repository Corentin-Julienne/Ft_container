/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binarySearchTree.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:38:37 by cjulienn          #+#    #+#             */
/*   Updated: 2022/11/18 16:37:05 by cjulienn         ###   ########.fr       */
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

namespace lab
{
	
	template<typename Key, typename T, typename Cmp = std::less<Key>, 
	typename Allocator = std::allocator<std::pair<const Key, T> > >
	class binarySearchTree
	{
		
		public:

			friend class Node;
			
			/* ALIASES */
			typedef Key									key_type;
			typedef T									mapped_type;
			typedef std::pair<const Key, T>				value_type;
			typedef std::size_t							size_type;
			typedef Node<const Key, T>					node;

			class value_compare // compare two keys using std::less 
			{
				friend class binarySearchTree;
				
				protected:
				
					Cmp		comp;
					
					value_compare(Compare c) : comp(c) {} // protected constructor, usable by tree only

				public:
				
					typedef bool				result_type;
					typedef value_type			first_argument_type;
					typedef value_type			second_argument_type;

					bool operator() (const value_type& x, const value_type& y) const
					{
						return comp(x.first, y.first);
					}
			};

			/* CONSTRUCTORS, DESTRUCTORS, OVERLOADING OPERATOR = */
			binarySearchTree(void) : _root(nullptr), _nil(nullptr), _size(0), _key_comparator(Cmp()),
			_value_alloc(Allocator())
			{
				this->_nodeAlloc = std::allocator<node>();
			}
			
			~binarySearchTree()
			{
				this->postOrderTraversal(this->_root, _deleteNode);
			};

			/* UTILS */

			void	add_and_insert(const value_type &val) // to test
			{
				node		*newNode = this->_createNewNode(val);

				this->treeInsert(newNode);
			}
			
			/* to cover the full tree, elem must be equal to this->_root */
			void	postOrderTraversal(node *elem, void(* func)(* node)) // to test
			{
				if (elem != nullptr)
				{
					this->postOrderTraversal(elem->_left);
					this->postOrderTraversal(elem->_right);
					func(elem);
				}
			}

			void	printTree(void)
			{
				if (this->_root == nullptr)
					return ;
				this->_printTree(this->_root, "", true);
			}

			/* BST FUNCTIONS */

			node	*treeSearch(node *x, const Key k) // to test
			{
				if (x == nullptr || k == x->_val.first)
					return (x);
				if (k < x->_val.first)
					return (treeSearch(x->_left, k));
				else
					return (treeSearch(x->_right, k));
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

			/* should be used with start == this->_root */
			node	*treeDelete(node *start, const Key key) // to test
			{
				if (start == nullptr)
					return (nullptr);
				else if (key < start->_val.first)
					start->_left = this->treeDelete(start->_left, key);
				else if (key > start->_val.first)
					start->_right = this->treeDelete(start->_right, key);
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
						node	*tmp = treeMinimum(start->_right);

						start->_val.first = tmp->_val.first;
						start->_right = treeDelete(start->_right, tmp->_val.first);
					}
					return (start);
				}
			}
	
			/* RBT FUNCTIONS */

			void	RedBlackTreeInsert()
			{
				// TODO
			}
			
		private:

			/* PRIVATE ATTRIBUTES */
			node					*_root;
			node					*_nil; // for iterator
			size_type				_size; // depth of the BST
			Cmp						_key_comparator; // compare two keys using std::less
			Allocator				_value_alloc; // for the pair
			std::allocator<node>	_nodeAlloc; // for the node

		private:

			/* HELPER FUNCTIONS */
			
			bool	_compare(const value_type& x, const value_type& y) const // to test
			{	
				return (value_compare(x, y));
			}

			void	_deleteNode(node *target) // to test
			{
				this->_value_alloc.destroy(&target->_val);
				this->_nodeAlloc.deallocate(target, 1);
			}

			node	*_createNewNode(const value_type &val)
			{
				node		*newNode = this->_nodeAlloc.allocate(1); // alloc space for a node

				this->_value_alloc.construct(&newNode->_val, val); // create obj std::pair to implement in node
				newNode->_color = RED;
				newNode->_parent = nullptr;
				newNode->_right = nullptr;
				newNode->_left = nullptr;
				return (newNode);
			}

			/*  indent should be equal to "" and last to true */
			void	_printTree(node *root, std::string indent, bool last)
			{
				if (root != nullptr)
				{
					if (last == true)
					{
						std::cout << "└────";
						indent += "|    ";
					}
					else
					{
						std::cout << "├────";
						indent += "|    ";
					}
				}
				
				std::cout << root->_val.first << " = " << root->_val.second << std::endl;
				
				this->_printTree(root->left, indent);
				this->_printTree(root->_right, indent);
			}
	};
}

#endif
