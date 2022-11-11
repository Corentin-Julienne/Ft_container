/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RedBlackTree.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:39:30 by cjulienn          #+#    #+#             */
/*   Updated: 2022/10/26 18:17:22 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RED_BLACK_TREE_CLASS_HPP
# define RED_BLACK_TREE_CLASS_HPP

#include <iostream>

/* a red-black tree (RBT) is an algorithm to sort efficiently values [UPDATE THIS] */

/* A RBT  */


/* MACROS FOR RBT */
#define BLACK					1
#define RED						2

#define RIGHT					1
#define LEFT					2

/* struct for RBT */

struct Node
{
	int				val;
	int				color;
	Node			*parent;
	Node			*right;
	Node			*left;
};

class RedBlackTree
{
	public:

		/* constructors */
		RedBlackTree(void);
		RedBlackTree(int val_root);
		/* destructors */
		~RedBlackTree();
		/* constructor by copy */
		RedBlackTree(const RedBlackTree& original);
		
		/* overloading operator = */

		/* getters and setters */

		/* methods for RBT initialization */
		void	printBST(void);
		void	insertValBST(int val);
		void	delValBST(int val);

	private:

		/* utils for nodes creation and deletion */
		Node	*createNewNode(int val);
		void	deleteTree(Node **node);
		/* standard BST ops */
		Node	*findNode(Node *node, int val);
		Node	*findMin(Node *node);
		Node	*findMax(Node *node);
		Node	*findPredecessor(Node *node);
		Node	*findSuccessor(Node *node);
		void	binaryTreeInsertion(Node *newNode);
		Node	*binaryTreeDeletion(Node *node, int val);
		/* special RBT ops */
		void	redBlackTreeInsertion(Node *newNode);
		Node	*redBlackTreeDeletion(Node *node, int val);
		
		
		/* data */
		Node			*_root;	
};

#endif
