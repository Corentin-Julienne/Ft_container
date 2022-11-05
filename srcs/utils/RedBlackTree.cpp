/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RedBlackTree.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:39:28 by cjulienn          #+#    #+#             */
/*   Updated: 2022/10/26 18:17:16 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RedBlackTree.hpp"

/* constructor with args */
RedBlackTree::RedBlackTree(int val) : _root(nullptr)
{
	this->_root = createNewNode(val);
}

/* basic destructor */
RedBlackTree::~RedBlackTree()
{
	this->deleteTree(&this->_root);
}

/* constructor by copy */

/* overloading operator = */

/* METHODS */

/* utils for nodes creation and deletion */

/* create a new node by allocating memory */
Node	*RedBlackTree::createNewNode(int val)
{
	Node		*newNode = nullptr;
	
	newNode = new Node;
	newNode->val = val;
	newNode->color = RED;
	newNode->parent = nullptr;
	newNode->right = nullptr;
	newNode->left = nullptr;
	return (newNode);
}

/* destroy and deallocate the entire tree (put &this->_root as argument to do so) */
void	RedBlackTree::deleteTree(Node **node)
{
	Node		*current_node;	
	
	current_node = *node;
	if (current_node != nullptr)
	{
		deleteTree(&current_node->left);
		deleteTree(&current_node->right);
		std::cout << "node value is " << current_node->val << std::endl; // debug
		delete current_node;
		*node = nullptr;
	}
}

/* standard BST ops  */

/* find node allow to find a value in a BST. Return the node of the value if inside the tree,
nullptr otherwise */
Node	*RedBlackTree::findNode(Node *node, int val)
{
	if (node == nullptr)
		return (nullptr);
	if (node->val == val)
		return (node);
	else if (val < node->val)
		this->findNode(node->left, val);
	else
		this->findNode(node->right, val);
}

/* return the minimun value of a tree or a subtree. Give this->_root
value to node to find the minimum value of the entire binary tree */
Node	*RedBlackTree::findMin(Node *node)
{
	Node		*tmp;

	tmp = node;
	while (tmp->left != nullptr)
		tmp = tmp->left;
	return (tmp);
}

/* return the maximum value of a tree or a subtree. Give this->_root
value to node to find the maximum value of the entire binary tree */
Node	*RedBlackTree::findMax(Node *node)
{
	Node		*tmp;

	tmp = node;
	while (tmp->right != nullptr)
		tmp = tmp->right;
	return (tmp);
}

/* find the successor of a node, based on value. return the relevant node
or nullptr if there is no successor node */
Node	*RedBlackTree::findSuccessor(Node *node)
{
	Node		*successor;
	
	if (node->right != nullptr)
		return (this->findMin(node->right));
	successor = node->parent;
	while (successor != nullptr && node == successor->right)
	{
		node = successor;
		successor = successor->parent;
	}
	return (successor);
}

/* find the predecessor of a node, based on value. return the relevant node
or nullptr if there is no predecessor node */
Node	*RedBlackTree::findPredecessor(Node *node)
{
	Node		*predecessor;

	if (node->left != nullptr)
		return (this->findMax(node->left));
	predecessor = node->parent;
	while (predecessor != nullptr && node == predecessor->left)
	{
		node = predecessor;
		predecessor = predecessor->parent;
	}
	return (predecessor);
}

/* insert a new node into the BST, respecting the rules of BSTs */
void	RedBlackTree::binaryTreeInsertion(Node *newNode)
{
	Node		*prev;
	Node		*root;

	prev = nullptr;
	root = this->_root;
	while (root != nullptr)
	{
		prev = root;
		if (newNode->val < root->val)
			root = root->left;
		else
			root = root->right;
	}
	newNode->parent = prev;
	if (prev == nullptr)
		this->_root = newNode;
	else if (newNode->val < prev->val)
		prev->left = newNode;
	else
		prev->right = newNode;
}

/* delete a specific node present in the BST by selecting the one with node->val = val
can be used to delete a specific value in the entire tree (node should be equal to this->_root)
or within a subtree (provide a node equal to any node in the entire tree) */
Node	*RedBlackTree::binaryTreeDeletion(Node *node, int val)
{
	Node			*tmp;
	
	if (node == nullptr) // node is NULL
		return (nullptr);
	else if (val < node->val) // val is inf to node->val 
		node->left = this->binaryTreeDeletion(node->left, val);
	else if (val > node->val) // val is sup to node->val
		node->right = this->binaryTreeDeletion(node->right, val);
	else // val is equal to node->val
	{
		if (node->left == nullptr && node->right == nullptr) // case node is a leaf
		{
			delete node;
			node = nullptr;
		}
		else if (node->left == nullptr) // case node has only one child
		{
			tmp = node;
			node = node->right;
			delete tmp;
		}
		else if (node->right == nullptr) // case node has only one child
		{
			tmp = node;
			node = node->left;
			delete tmp;
		}
		else // case node has two children
		{
			tmp = this->findMin(node->right);
			node->val = tmp->val;
			node->right = this->binaryTreeDeletion(node->right, tmp->val);
		}
	}
	return (node);
}

// RB-INSERT(T, k)
//      BST-INSERT(T, k) //normal BST insertion
//      while k.parent.color == RED
//          if k.parent == k.parent.parent.right
//             u = k.parent.parent.left //uncle
//              if u.color == RED // case 3.1
//                 u.color = BLACK
//                 k.parent.color = BLACK
//                 k.parent.parent.color = RED
//                 k = k.parent.parent
//              else if k == k.parent.left // case 3.3.1 and 3.3.2
//                 k = k.parent
//                 LEFT-ROTATE(T, k)
//                 k.parent.color = BLACK
//                 k.parent.parent.color = RED
//                 RIGHT-ROTATE(T, k.parent.parent)
//         else (same as then clause with “left” and “right” exchanged)
//      T.root.color = BLACK

void	RedBlackTree::redBlackTreeInsertion(Node *newNode)
{
	Node		*uncle;
	
	this->binaryTreeInsertion(newNode); // standard BST insertion
	while (newNode->parent && newNode->parent->color == RED)
	{
		if (newNode->parent == newNode->parent->right)
		{
			uncle = newNode->parent->parent->left;
			if (uncle->color == RED)
			{
				uncle->color = BLACK;
				newNode->parent->color = BLACK;
				newNode->parent->parent->color = RED;
				newNode = newNode->parent->parent;
			}
			else if (newNode == newNode->parent->left)
			{
				newNode = newNode->parent;
				this->redBlackTreeLeftRotate();
				newNode->parent->color = BLACK;
				newNode->parent->parent->color = RED;
				this->redBlackTreeRightRotate();
			}
		}
		else // newNode->parent == newNode->parent->left
		{
			// TODO
		}
	}
	this->_root->color = BLACK; // root node is always black
}

Node	*RedBlackTree::redBlackTreeDeletion(Node *node, int val)
{
	//TODO
}
