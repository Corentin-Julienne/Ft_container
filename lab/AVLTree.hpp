/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AVLTree.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 18:54:49 by cjulienn          #+#    #+#             */
/*   Updated: 2022/12/21 17:55:48 by cjulienn         ###   ########.fr       */
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

/*

	SYNOPSIS : AVL tree is used by map to store and iterate over values (pairs) that are embedded within the map object.

	Important Note : in case of trying to insert or delete a non existing key, the AVL tree produces undefined behaviour.
	Those cases should be handled directly by map methods.

	Contains the following prototypes (public functions only) :

	1] Coplien form (basic constructor, destructor, copy constructor, operator = overload)
	
	=>  AVLTree() : _root(nullptr), _size(0), _pair_alloc(Alloc());
	=>	~AVLTree() 
	=>	AVLTree(const AVLTree &original) : _root(original._root), _size(original._size),
		_pair_alloc(original._pair_alloc), _node_alloc(original._node_alloc) {};
	=>	AVLTree&	operator=(const AVLTree &original);

	2] Getters

	=>	size_type	getSize(void);
	=>	node*		getRoot(void);		
	=>	node*		getMinNode(void);	
	=>	node*		getMaxNode(void);	
	=>	key_type	getMinKey(void);
	=>	key_type	getMaxKey(void);
	=>	mapped_type	getMinVal(void);
	=>	mapped_type	getMaxVal(void);

	3] Public Methods
	
	=>	void	treeInsertion(const value_type &val, int tree = AVL);
	=>	bool	IsKeyAlreadyExisting(const Key &key);
	=>	void	deleteNode(const Key &key, int tree = AVL);
	=>	void	postOrderTraversalDeletion(node *elem);

	4] Public Debug Methods

	=>	void	printTree(void);
	=>	void	printNodes(void);
*/

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

			/* create a node and insert it using a standard BST methodology */
			void	treeInsertion(const value_type &val, int tree = AVL)
			{
				node		*newNode = this->_createNewNode(val);
				
				if (tree == AVL)
					this->_AVLtreeInsert(newNode);
				else
					this->_treeInsert(newNode);
			}

			/* check whether a key exists or not */
			bool	IsKeyAlreadyExisting(const Key &key)
			{
				node 	*target = this->_root->getTreeSearch(this->_root, key);
				
				if (target == nullptr)
					return (false);
				return (true);
			}

			/* deletes a node by identifying it by its key */
			void	deleteNode(const Key &key, int tree = AVL)
			{
				if (tree == AVL)
					this->_AVLtreeDelete(this->_root, key);
				else
					this->_treeDelete(this->_root, key);
			}

			/* to cover the full tree, elem must be equal to this->_root */
			void	postOrderTraversalDeletion(node *elem)
			{
				if (elem != nullptr)
				{
					this->postOrderTraversalDeletion(elem->_left);
					this->postOrderTraversalDeletion(elem->_right);
					this->_deleteNode(elem);
				}
			}

		/* DEBUG PUBLIC METHODS */

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
			
		private:

			node					*_root;
			size_type				_size;
			allocator_type			_pair_alloc;
			std::allocator<node>	_node_alloc;

		private:

		/* GENERAL HELPERS */

			/* allocate memory for a node creation, then create it */
			node	*_createNewNode(const value_type &val)
			{
				node		*newNode = this->_node_alloc.allocate(1);

				this->_pair_alloc.construct(&newNode->_val, val);
				newNode->_parent = nullptr;
				newNode->_right = nullptr;
				newNode->_left = nullptr;
				newNode->_bf = 0;
				return (newNode);
			}

			/* delete a node and free its memory */
			void	_deleteNode(node *target)
			{
				this->_pair_alloc.destroy(&target->_val);
				this->_node_alloc.deallocate(target, 1);
				target = nullptr;
			}

			/*  space should be equal to 0, target to this->_root */
			void	_printTree(node *target, int space)
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
			node	*_replace_key(node *target, value_type newPair)
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

			/*  change the root after root deletion */
			void	_change_root(node *target, int type)
			{
				std::cout << "go there and key = " << target->_val.first << std::endl;
				if (type == LEAF)
				{
					this->_root = nullptr;
					return ;
				}
				else if (type == RIGHT)
					this->_root = target->_right;
				else if (type == LEFT)
					this->_root = target->_left;
				else // case target has both children
					this->_root = target;
				this->_root->_parent = nullptr;
			}

			/* check whether a node is a left child of its parent.
			returns true if it is the case, false if it is the right child or has
			no parent */
			bool	_is_left_child(node *target)
			{
				if (target->_parent == nullptr || target->_parent->_left != target)
					return (false);
				return (true);
			}

			/* check whether a node is a right child of its parent.
			returns true if it is the case, false if it is the left child or has
			no parent */
			bool	_is_right_child(node *target)
			{
				if (target->_parent == nullptr || target->_parent->_right != target)
					return (false);
				return (true);
			}

		/* HELPERS SPECIFIC TO AVL TREES */

			/* update or calculate balance factor (int bf) of a given node
			bf formula equal to |   bf(node) = depth(RS(node)) - depth(LS(node))   |  
			where RS = right subtree ans LS = left subtree */
			void	_update_balance_factor(node *target)
			{				
				if (target->_bf < -1 || target->_bf > 1) // if tree unbalanced, trigger algo triggering relevant rotations
				{
					this->_rebalanceTree(target); // never triggered by newly inserted value
					return ;
				}
				if (target->_parent != nullptr)
				{
					if (this->_is_left_child(target))
						target->_parent->_bf -= 1;
					else if (this->_is_right_child(target))
						target->_parent->_bf += 1;
					if (target->_parent->_bf != 0)
						this->_update_balance_factor(target->_parent); // update balance factor of parent
				}
			}

			/* perform a left rotation on node a. Basically,
			in a configuration when b is the right child of a and c a right child of b,
			we proceed in 3 steps :
			1] b becomes the new root (or subroot case a was not the root of the tree)
			2] a takes ownership of b’s child as its right child (or nullptr if b's child is equal to nullptr)
			3] b takes ownership of a as its left child */
			void	_AVL_left_rotation(node *a)
			{	
				node		*b = a->_right;

				/* transfer ownership from b left child to a right child */
				a->_right = b->_left; 
				if (b->_left != nullptr)
					b->_left->_parent = a;
				/* change parent relationship from a to b */
				b->_parent = a->_parent;
				if (a->_parent == nullptr)
					this->_root = b;
				else if (this->_is_left_child(a))
					a->_parent->_left = b;
				else
					a->_parent->_right = b;
				/* establish new relation between a and b */
				b->_left = a;
				a->_parent = b;
				/* update bf values:
				=> newBal(x) = oldBal(x) - 1 - max(0, oldBal(y))
				=> newBal(y) = oldBal(y) - 1 + min(0, newBal(x)) */
				a->_bf = a->_bf - 1 - std::max(0, b->_bf);
				b->_bf = b->_bf - 1 + std::min(0, a->_bf);
			}

			/* perform a right rotation on node a. Basically,
			in a configuration when b is the left child of a and c a left child of b,
			we proceed in 3 steps : 
			1] b becomes the new root (or subroot case a was not the root of the tree)
			2] c takes ownership of b’s right child, as its left child 
			(or nullptr if b's right child is equal to nullptr).
			3] b takes ownership of c, as its right child */
			void	_AVL_right_rotation(node *a)
			{	
				node		*b = a->_left;

				/* transfer ownership from b right child to a left child */
				a->_left = b->_right;
				if (b->_right != nullptr)
					b->_right->_parent = a;
				/* change parent relationship from a to b */
				b->_parent = a->_parent;
				if (a->_parent == nullptr)
					this->_root = b;
				else if (this->_is_right_child(a))
					a->_parent->_right = b;
				else
					a->_parent->_left = b;
				/* establish new relation between a and b */
				b->_right = a;
				a->_parent = b;
				/* update bf values:
				=> newBal(x) = oldBal(x) + 1 - max(0, oldBal(y))
				=> newBal(y) = oldBal(y) + 1 + max(0, newBal(x)) */
				a->_bf = a->_bf + 1 - std::max(0, b->_bf);
				b->_bf = b->_bf + 1 + std::max(0, a->_bf);
			}


			/* Perform the left rotation on the left subtree.
			Then, perform the right rotation on the root node. */
			void	_AVL_right_left_rotation(node *a)
			{
				this->_AVL_right_rotation(a->_right);
				this->_AVL_left_rotation(a);
			}
			
			/* Perform the right rotation on the right subtree.
			Then, Perform the left rotation on the root node */
			void	_AVL_left_right_rotation(node *a)
			{
				this->_AVL_left_rotation(a->_left);
				this->_AVL_right_rotation(a);
			}

			/* rebalance the tree using rotations functions */
			void	_rebalanceTree(node *start)
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

			/* performs a standard BST insertion. Then, update balance factor of z and its parents,
			and performs rotations if necessary */
			void	_AVLtreeInsert(node *z)
			{
				this->_treeInsert(z);
				this->_update_balance_factor(z);
			}

			/* search for the parent node corresponding to the node corresponding to key, 
			then performs standard BST deletion with key, then update balance factor of node parent and its parent,
			and finally performs rotations if necessary */
			void	_AVLtreeDelete(node *start, const Key& key)
			{
				node		*z = start->getTreeSearch(start, key);
				
				this->_treeDelete(start, key);
				this->_size--;
				if (this->_size > 0)
					this->_update_balance_factor(z);
			}
			
		/* STANDARD BST MODIFCATION FUNCTIONS */

			/* inserts a value in a tree, without caring to the 
			equilibrium of the tree (standard BST insertion) */
			void	_treeInsert(node *z)
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
				this->_size++;
			}

			/* should be used with start == this->_root */
			node	*_treeDelete(node *start, const Key key)
			{
				if (start == nullptr)
					return (nullptr);
				else if (key < start->_val.first)
					start->_left = this->_treeDelete(start->_left, key);
				else if (key > start->_val.first)
					start->_right = this->_treeDelete(start->_right, key);
				else // we reached the target node, now we have to make relevant ops
				{
					if (start->_left == nullptr && start->_right == nullptr) // case target got no child (leaf case)
					{
						if (this->_is_left_child(start))
							start->_parent->_left = nullptr;
						else if (this->_is_right_child(start))
							start->_parent->_right = nullptr;
						if (start == this->_root)
							this->_change_root(start, LEAF);
						this->_deleteNode(start);
						start = nullptr;
					}
					else if (start->_left == nullptr) // case target got only right child
					{
						node	*tmp = start;
						
						start = start->_right;
						if (this->_is_left_child(tmp))
							tmp->_parent->_left = start;
						else if (this->_is_right_child(tmp))
							tmp->_parent->_right = start;
						if (tmp->_parent)
							start->_parent = tmp->_parent;
						if (tmp == this->_root)
							this->_change_root(tmp, RIGHT);
						this->_deleteNode(tmp);
						tmp = nullptr;
					}
					else if (start->_right == nullptr) // case target got only left child
					{
						node	*tmp = start;
						
						start = start->_left;
						if (this->_is_left_child(tmp))
							tmp->_parent->_left = start;
						else if (this->_is_right_child(tmp))
							tmp->_parent->_right = start;
						if (tmp->_parent)
							start->_parent = tmp->_parent;
						if (tmp == this->_root)
							this->_change_root(tmp, LEFT);
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
				if (target->_right)
					std::cout << "right child = " << target->_right->_val.first << std::endl;
				else
					std::cout << "right child = nullptr" << std::endl;
				if (target->_left)
					std::cout << "left child = " << target->_left->_val.first << std::endl;
				else
					std::cout << "left child = nullptr" << std::endl;
				std::cout << "bf = " << target->_bf << std::endl;
			}
	};
}

#endif
