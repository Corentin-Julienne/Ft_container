/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AVLTree.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 18:54:49 by cjulienn          #+#    #+#             */
/*   Updated: 2022/12/20 12:11:40 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AVL_TREE_HPP
# define AVL_TREE_HPP

#include <functional>
#include <memory>
#include <iostream>
#include <string>

#include "./node.hpp"

/* macros for root replacement */
#define LEAF			0
#define RIGHT			1
#define LEFT			2
#define BOTH			3

/* used by insertion and deletion : can choose between BST and AVL tree */
#define STD				1
#define AVL				2

namespace ft
{
	template < 
		class Key,
		class T,
		class Alloc = std::allocator<std::pair<const Key, T> > 
	> 
	class AVLTree
	{
		public:
		
		/* ALIASES */
			typedef Key									key_type;
			typedef T									mapped_type;
			typedef std::pair<const Key, T>				value_type;
			typedef std::size_t							size_type;
			typedef Alloc								allocator_type;
			typedef Node<Key, T>						node;

			/* CONSTRUCTORS AND DESTRUCTORS */
			AVLTree() : _root(nullptr), _size(0), _pair_alloc(Alloc())
			{
				this->_node_alloc = std::allocator<node>();
			}

			~AVLTree() 
			{ 
				this->postOrderTraversalDeletion(this->_root); 
			}

			AVLTree(const AVLTree &original) : _root(original._root), _size(original._size),
			_pair_alloc(original._pair_alloc), _node_alloc(original._node_alloc) {};

			AVLTree&	operator=(const AVLTree &original)
			{
				if (this != &original)
				{
					this->_root = original._root;
					this->_size = original._size;
					this->_pair_alloc = original._pair_alloc;
					this->_node_alloc = original._node_alloc;
				}
				return *this;
			}

			/* GETTERS */
			
			size_type	getSize(void)		{ return (this->_size); };
			node*		getRoot(void)		{ return (this->_root); };
			node*		getMinNode(void)	{ return (this->_root->getTreeMin(this->_root)); };
			node*		getMaxNode(void)	{ return (this->_root->getTreeMax(this->_root)); };

			key_type	getMinKey(void)
			{
				node 		*minNode = this->getMinNode();

				return (minNode->_val.first);
			}	
			
			key_type	getMaxKey(void)
			{
				node		*maxNode = this->getMaxNode();

				return (maxNode->_val.first);
			}

			mapped_type		getMinVal(void)
			{
				node 		*minNode = this->getMinNode();

				return (minNode->_val.second);
			}

			mapped_type		getMaxVal(void)
			{
				node		*maxNode = this->getMaxNode();

				return (maxNode->_val.second);
			}
			
			/* PUBLIC METHODS */

			/* INSERTION FUNCTIONS */

			/* create a node and insert it using a standard BST methodology */
			void	treeInsertion(const value_type &val, int tree = AVL) // to test
			{
				node		*newNode = this->_createNewNode(val);
				
				if (tree == AVL)
					this->_AVLtreeInsert(newNode);
				else
					this->_treeInsert(newNode);
			}

			/* SEARCH FUNCTIONS */

			/* check whether a key exists or not */
			bool	IsKeyAlreadyExisting(const Key &key)
			{
				node 	*target = this->_root->getTreeSearch(this->_root, key);
				
				if (target == nullptr)
					return (false);
				return (true);
			}

			/* TREE AND NODE DELETION FUNCTIONS */

			/* deletes a node by identifying it by its key */
			void	deleteNode(const Key &key, int tree = AVL) // to test
			{
				if (tree == AVL)
					this->_AVLtreeDelete(this->_root, key);
				else
					this->_treeDelete(this->_root, key);
			}

			/* to cover the full tree, elem must be equal to this->_root */
			void	postOrderTraversalDeletion(node *elem) // to test
			{
				if (elem != nullptr)
				{
					this->postOrderTraversalDeletion(elem->_left);
					this->postOrderTraversalDeletion(elem->_right);
					this->_deleteNode(elem);
				}
			}

			/* DEBUG PUBLIC FUNCTIONS */

			/* print the tree in 2D : the root value appears in the center of the vertical axis,
			in the left side of the terminal. Debug and visual function */
			void	printTree(void)
			{
				if (this->_root == nullptr)
					return ;
				this->_printTree(this->_root, 0);
			}

			/* print every node informations */
			void	printNodes(void)
			{
				node		*target;
				
				if (this->_root == nullptr)
					return ;
				target = this->_root->getTreeMin(this->_root);
				int			i = 1;
				while (target != nullptr)
				{				
					std::cout << "-----------------------------" << std::endl;
					std::cout << "node num " << i << std::endl;
					this->_print_node(target);
					std::cout << "-----------------------------" << std::endl;
					target = target->getTreeSucc(target);
					i++;
				}
			}


			/* debug functions used to test basic subops of AVL tree 
			!!! NOT TO USE OUTSIDE OF DEBUGGING TESTS !!!*/
			
			void	useRotateRight(node *target)
			{
				this->_AVL_right_rotation(target);				
			}

			void	useRotatateLeft(node *target)
			{
				this->_AVL_left_rotation(target);
			}

			void	useRotateRightLeft(node *target)
			{
				this->_AVL_right_left_rotation(target);				
			}

			void	useRotateLeftRight(node *target)
			{
				this->_AVL_left_right_rotation(target);
			}
			
		private:

			node					*_root;
			size_type				_size;
			allocator_type			_pair_alloc;
			std::allocator<node>	_node_alloc;

		private:

			/* HELPERS */

			/* allocate memory for a node creation, then create it */
			node	*_createNewNode(const value_type &val)
			{
				node		*newNode = this->_node_alloc.allocate(1); // alloc space for a node

				this->_pair_alloc.construct(&newNode->_val, val);
				newNode->_parent = nullptr;
				newNode->_right = nullptr;
				newNode->_left = nullptr;
				newNode->_bf = 0;
				return (newNode);
			}

			/* delete a node and free its memory */
			void	_deleteNode(node *target) // to test
			{
				this->_pair_alloc.destroy(&target->_val);
				this->_node_alloc.deallocate(target, 1);
				target = nullptr;
			}

			/*  space should be equal to 0, target to this->_root */
			void	_printTree(node *target, int space) // functionnal
			{
				const int	indent = 5;
				
				if (target ==  nullptr)
					return ;
				space += indent;
				this->_printTree(target->_right, space);
				std::cout << std::endl;
				for (int i = indent; i < space; i++)
        			std::cout << " ";
				std::cout << "[" << target->_val.first << "]" << std::endl;
				this->_printTree(target->_left, space);
			}

			/* create a copy of a node, but with another key,
			then replace links from other links from target to newNode */
			node	*_replace_key(node *target, value_type newPair) // to test
			{
				node	*newNode = this->_createNewNode(newPair);

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

			/* returns a copy of a dynamically allocated node (not shallow copy) */
			node	*_copyNode(node *target)
			{
				node	*cpy = this->_createNewNode(target->_val);
				
				cpy->_color = target->_color;
				cpy->_parent = target->_parent;
				cpy->_left = target->_left;
				cpy->_right = target->_right;
				return (cpy);
			}

			/* check whether a node is a left child of its parent.
			returns true if it is the case, false if it is the right child or has
			no parent */
			bool	_is_left_child(node *target) // to test
			{
				if (target->_parent == nullptr || target->_parent->_left != target)
					return (false);
				return (true);
			}

			/* check whether a node is a right child of its parent.
			returns true if it is the case, false if it is the left child or has
			no parent */
			bool	_is_right_child(node *target) // to test
			{
				if (target->_parent == nullptr || target->_parent->_right != target)
					return (false);
				return (true);
			}

			/*  change the root after root deletion */
			void	_change_root(node *target, int type)
			{
				if (type == LEAF)
					this->_root = nullptr;
				else if (type == RIGHT)
					this->_root = target->_right;
				else if (type == LEFT)
					this->_root = target->_left;
				else // case target has both children
					this->_root = target;
				this->_root->_parent = nullptr;
			}

			/* AVL Helpers */

			/* calc the distance to root by iterate through pointers to parent */
			int		_dist_to_root(node *start) // to test
			{
				int			res = 0;

				while (start)
				{
					res++;
					start = start->_parent;
				}
				return (res);
			}
			
			/* used to calculate the max depth of a subtree. Used to further calculate balanced factor */
			int		_calc_subtree_depth(node *subtree) // to test
			{
				node		*min = subtree->getTreeMin(subtree);
				node		*max = subtree->getTreeMax(subtree);
				int			res = 0;
				int			dist;
				
				if (subtree == nullptr)
					return (0);
				while (min->_val.first != max->_val.first)
				{
					dist = this->_dist_to_root(min);
					if (dist > res)
						res = dist;
					min = min->getTreeSucc(min);	
				}
				return (res);
			}

			/* update or calculate balance factor (int bf) of a given node
			bf formula equal to |   bf(node) = depth(RS(node)) - depth(LS(node))   |  
			where RS = right subtree ans LS = left subtree */
			int		_calc_balance_factor(node *start) // to test
			{
				int			right_depth = this->_calc_subtree_depth(start->_right);
				int			left_depth = this->_calc_subtree_depth(start->_left);
				
				return (right_depth - left_depth);
			}

			/* AVL HELPER MODIF FUNCTIONS */

			void	_AVL_left_rotation(node *a) // to test
			{
				node		*b = a->_right;
				node		*c = b->_right;
				node		*tmp;

				// b becomes the new subtree root
				b->_parent = a->_parent; // replace parent node of b by a
				if (this->_is_left_child(a)) // links parent of a to b
					a->_parent->_left = b;
				else if (this->_is_right_child(a)) // links parent of a to b 
					a->_parent->_right = b;
				tmp = b->_left;
				b->_left = a;
				b->_right = c;
				// a becomes left child of b
				a->_parent = b;
				a->_right = tmp;
				// if a  equal to root, we need to change this->_root
				if (a->_val.first == this->_root->_val.first)
					this->_root = b;
				/* update bf values:
				=> newBal(x) = oldBal(x) - 1 - max(0, oldBal(y))
				=> newBal(y) = oldBal(y) - 1 + min(0, newBal(x)) */
				a->_bf = a->_bf - 1 - std::max(0, b->_bf);
				b->_bf = b->_bf - 1 + std::min(0, a->_bf);
			}

			void	_AVL_right_rotation(node *a) // to test
			{
				node		*b = a->_left;
				node		*tmp;

				// b becomes the new subtree root
				b->_parent = a->_parent; // replace parent node b by c
				if (this->_is_left_child(a)) // links parent of c to b
					a->_parent->_left = b;
				else if (this->_is_right_child(a)) // links parent of c to b 
					a->_parent->_right = b;
				tmp = b->_right;
				b->_right = a;
				// c takes ownership of b’s right child, as its left child
				a->_parent = b;
				a->_left = tmp;	
				// if c is equal to root, we need to change this->_root
				if (a->_val.first == this->_root->_val.first)
					this->_root = b;
				/* update bf values:
				=> newBal(x) = oldBal(x) + 1 - max(0, oldBal(y))
				=> newBal(y) = oldBal(y) + 1 + max(0, newBal(x)) */
				a->_bf = a->_bf + 1 - std::max(0, b->_bf);
				b->_bf = b->_bf + 1 + std::max(0, a->_bf);
			}

			/* Perform the right rotation on the right subtree.
			Then, Perform the left rotation on the root node */
			void	_AVL_left_right_rotation(node *a) // to test
			{
				this->_AVL_right_rotation(a->_right);
				this->_AVL_left_rotation(a);
			}

			/* Perform the left rotation on the left subtree.
			Then, perform the right rotation on the root node. */
			void	_AVL_right_left_rotation(node *a) // to test
			{
				this->_AVL_left_rotation(a->_left);
				this->_AVL_right_rotation(a);
			}

			/* to check wether the tree is balanced, start should be equal to root */
			bool	_is_tree_balanced(node *start) // to test // probably not time efficient
			{
				node			*min = start->getTreeMin(start);
				node			*max = start->getTreeMax(start);

				while (min->_val.first == max->_val.first)
				{
					if (min->_bf != 0 && min->_bf != -1 && min->_bf != 1)
						return (false);
					min = min->getTreeSucc(min);
				}
				return (true);
			}

			/* rebalance the tree using rotations functions */
			void	_rebalanceTree(node *start) // to test
			{
				if (start->_bf > 0) 
				{
					if (start->_right->_bf < 0) 
						this->_AVL_right_left_rotation(start);
					else 
						this->_AVL_left_rotation(start);
				} 
				else if (start->_bf < 0) 
				{
					if (start->_left->_bf > 0)
						this->_AVL_left_right_rotation(start);
					else
						this->_AVL_right_rotation(start);
				}
			}

			/* AVL MODIFICATION FUNCTIONS */

			void	_AVLtreeInsert(node *z) // to test
			{
				this->_treeInsert(z); // standard BST insertion
				while (z)
				{
					z->_bf = this->_calc_balance_factor(z); // update balance factor
					if (z->_bf != 0 && z->_bf != -1 && z->_bf != 1)
						this->_rebalanceTree(z); // rebalance using rotations and use its bf recalculations functions
					z = z->_parent;
				}
			}

			void	_AVLtreeDelete(node *start, const Key& key) // to test
			{
				node		*z = start->getTreeSearch(start, key); // search for corresponding node with key
				
				z = z->_parent; // look for update parent
				this->_treeDelete(start, key); // standard bst deletion
				while (z)
				{
					z->_bf = this->_calc_balance_factor(z); // update balance factor
					if (z->_bf != 0 && z->_bf != -1 && z->_bf != 1)
						this->_rebalanceTree(z); // rebalance using rotations and use its bf recalculations functions
					z = z->_parent;
				}
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
				// add to the size of the binary search tree
				this->_size++;
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
				else // we reached the target node, now we have to make relevant ops
				{
					if (start->_left == nullptr && start->_right == nullptr) // case target got no child (leaf case)
					{
						if (this->_is_left_child(start))
							start->_parent->_left = nullptr;
						else if (this->_is_right_child(start))
							start->_parent->_right = nullptr;
						if (start == this->_root) // case target is root
							this->_change_root(start, LEAF);
						this->_deleteNode(start);
						start = nullptr;
					}
					else if (start->_left == nullptr) // case target got only right child
					{
						node	*tmp = start;
						
						start = start->_right;
						if (this->_is_left_child(tmp)) // links parent to start
							tmp->_parent->_left = start;
						else if (this->_is_right_child(tmp)) // links parent to start
							tmp->_parent->_right = start;
						if (tmp->_parent)
							start->_parent = tmp->_parent; // links start to its new parent
						if (tmp == this->_root)
							this->_change_root(tmp, RIGHT); // moving root to right child
						this->_deleteNode(tmp);
						tmp = nullptr;
					}
					else if (start->_right == nullptr) // case target got only left child
					{
						node	*tmp = start;
						
						start = start->_left;
						if (this->_is_left_child(tmp)) // links parent to start
							tmp->_parent->_left = start;
						else if (this->_is_right_child(tmp)) // links parent to start
							tmp->_parent->_right = start;
						if (tmp->_parent)
							start->_parent = tmp->_parent; // links start to its new parent 
						if (tmp == this->_root)
							this->_change_root(tmp, LEFT); // moving root to left child
						this->_deleteNode(tmp);
						tmp = nullptr;
					}
					else // case target has two children node left and right
					{
						node	*tmp = this->_root->getTreeMin(start->_right);
						node	*newNode = this->_replace_key(start, tmp->_val);
						
						if (start == this->_root)
							this->_change_root(newNode, BOTH);
						this->_deleteNode(start);
						start = newNode;
						start->_right = _treeDelete(start->_right, tmp->_val.first);
					}
				}
				// withdraw one to size of the binary search tree
				this->_size--;
				return (start);
			}
			
			/* DEBUGGING PRIVATE FUNCTIONS */

			/* this function is a debug one to print every feature of a node to check whether
			the connections between nodes are preserved after insertion/deletion procedures */
			void	_print_node(node *target)
			{
				if (target == nullptr)
					return ;
				std::cout << "key = " << target->_val.first << std::endl;
				if (target->_parent)
					std::cout << "parent = " << target->_parent->_val.first << std::endl;
				else
					std::cout << "parent = nullptr" << std::endl;
				if (target->_left)
					std::cout << "left child = " << target->_left->_val.first << std::endl;
				else
					std::cout << "left child = nullptr" << std::endl;
				if (target->_right)
					std::cout << "right child = " << target->_right->_val.first << std::endl;
				else
					std::cout << "right child = nullptr" << std::endl;
				std::cout << "bf = " << target->_bf << std::endl;
			}
	};
}

#endif
