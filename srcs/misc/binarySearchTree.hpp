/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binarySearchTree.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:38:37 by cjulienn          #+#    #+#             */
/*   Updated: 2022/11/22 17:48:52 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINARY_SEARCH_TREE_HPP
# define BINARY_SEARCH_TREE_HPP

#include <functional>
#include <memory>
#include <iostream>
#include <string>

# define RED		true
# define BLACK		false

namespace lab
{
	template < 
		class Key, 
		class T,
		class Cmp = std::less<Key>,
		class Alloc = std::allocator<std::pair<const Key,T> >
	> 
	class binarySearchTree
	{
		private:
		
			template <typename nodeKey, typename nodeT>
			struct Node
			{	
				public:

					/* ALIASES */
					typedef nodeKey									key_type;
					typedef nodeT									mapped_type;
					typedef std::pair<const nodeKey, U>				value_type;
					typedef std::size_t								size_type;

					/* CONSTRUCTORS AND DESTRUCTOR */
					
					Node(void) : _color(RED), _parent(nullptr), _right(nullptr), _left(nullptr) {}

					Node(value_type &val) : _color(RED), _parent(nullptr), _right(nullptr), _left(nullptr), _val(val) {};

					~Node() {};

					Node(const Node& original) : _color(original._color), _parent(original._parent), _left(original._left),
					_val(original._val) {}

					value_type		_val;
					bool			_color;
					Node			*_parent;
					Node			*_right;
					Node			*_left;
			};
		
		public:
			
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
					
					value_compare(Cmp c) : comp(c) {} // protected constructor, usable by tree only

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
			_treeAlloc(Allocator())
			{
				this->_nodeAlloc = std::allocator<node>();
				this->_treeAlloc.allocate(1);
			}
			
			~binarySearchTree()
			{
				this->postOrderTraversal(this->_root);
				this->_treeAlloc.deallocate(1);
			};

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
				if (this->_root == nullptr)
					return ;
				if (this->_root->_left)
					std::cout << "there is a left member" << std::endl;
				if (this->_root->_right)
					std::cout << "there is a right member" << std::endl;
				std::cout << "the key is " << this->_root->_val.first 
				<< " and the value is " << this->_root->_val.second  << std::endl;
				std::cout << "right val : " << std::endl;
				std::cout << "key : " << this->_root->_right->_val.first << ", value : " << this->_root->_right->_val.second
				<< std::endl;
				std::cout << "key :" << this->_root->_left->_val.first << ", value : " 
				<< this->_root->_left->_val.second << std::endl;
			}
	
			/* RBT FUNCTIONS */

			void	_redBlackTreeInsert(node *newNode) // to test a lot
			{
				this->_treeInsert(newNode); // standard BST insertion
				while (newNode->_parent->_color == RED)
				{
					if (newNode->_parent == newNode->_parent->_parent->_right)
					{
						node	*uncle = newNode->_parent->_parent->_left;

						if (uncle->_color == RED)
						{
							uncle->_color = BLACK;
							newNode->_parent->_color = BLACK;
							newNode->_parent->_parent->_color = RED;
							newNode = newNode->_parent->_parent;
						}
						else if (newNode == newNode->_parent->_left)
						{
							newNode = newNode->_parent;
							this->_leftRotate(newNode); // to implement
							newNode->_parent->_color = BLACK;
							newNode->_parent->_parent->_color = RED;
							this->_rightRotate(newNode); // to implement
						}
					}
					else
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
				this->_root->_color = BLACK;
			}

			void	_redBlackTreeDelete(node *start, node *target)
			{
				this->_treeDelete(start, target->_val.first);
				while (target != this->_root && target->_color == BLACK)
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

			void	_rightRotate(node *target) // to implement
			{
				
			}

			void	_leftRotate(node *target) // to implement
			{
				
			}
			
		private:

			/* PRIVATE ATTRIBUTES */
			node					*_root;
			node					*_nil; // for iterator
			size_type				_size; // depth of the BST
			Cmp						_key_comparator; // compare two keys using std::less
			Allocator				_nodeAlloc; // for the nodes

		private:

			/* HELPER FUNCTIONS */
			
			bool	_compare(const value_type& x, const value_type& y) const // to test // useful ?
			{	
				return (value_compare(x, y));
			}

			void	_deleteNode(node *target) // to test
			{
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
				std::cout << "go till there" << std::endl;
				
				this->_printTree(root->_left, indent, false); // check this
				this->_printTree(root->_right, indent, true); // check this
			}

			/* BST FUNCTIONS */

			node	*_treeSearch(node *x, const Key k) // to test
			{
				if (x == nullptr || k == x->_val.first)
					return (x);
				if (k < x->_val.first)
					return (_treeSearch(x->_left, k));
				else
					return (_treeSearch(x->_right, k));
			}

			node	*_treeMinimum(node *x) // to test
			{
				while (x->_left != nullptr)
					x = x->_left;
				return (x);
			}

			node	*_treeMaximun(node *x) // to test
			{
				while (x->_right != nullptr)
					x = x->_right;
				return (x);
			}

			node	*_treeSuccessor(node *x) // to test
			{
				if (x->_right != nullptr)
					return (_treeMinimum(x->_right));
				
				node	*y = x->_parent;

				while (y != nullptr && x == y->_right)
				{
					x = y;
					y = y->_parent;
				}
				return (y);
			}

			node	*_treePredecessor(node *x) // to test
			{
				if (x->_left != nullptr)
					return (_treeMinimum(x->_left));
				
				node	*y = x->_parent;

				while (y != nullptr && x == y->_left)
				{
					x = y;
					y = y->_parent;
				}
				return (y);
			}

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
	};
}

#endif
