/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:35:08 by cjulienn          #+#    #+#             */
/*   Updated: 2022/12/21 18:08:12 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <functional>
#include <iostream>
#include <memory>
#include <algorithm>
#include <vector>
#include <map>
#include <iterator>
#include <ctime>
#include <time.h>
#include <string>

#include "./node.hpp"
#include "./AVLTree.hpp"

static void	leaks_tracking(void)
{
	system("leaks Lab");
}

int main(void)
{	
	atexit(leaks_tracking);

	// ft::AVLTree<int, std::string>				tree;

	// /* TESTING WITH STANDARD BINARY SEARCH TREE*/
	
	// std::cout << "create and print an empty tree (should display nothing)" << std::endl;
	// tree.printTree();

	// std::cout << "lets add 7 pairs to the tree..." << std::endl;
	// tree.treeInsertion(std::make_pair<int, std::string>(5, "this"), STD);
	// tree.treeInsertion(std::make_pair<int, std::string>(7, "this"), STD);
	// tree.treeInsertion(std::make_pair<int, std::string>(6, "this"), STD);
	// tree.treeInsertion(std::make_pair<int, std::string>(9, "this"), STD);
	// tree.treeInsertion(std::make_pair<int, std::string>(-4, "this"), STD);
	// tree.treeInsertion(std::make_pair<int, std::string>(-1, "this"), STD);
	// tree.treeInsertion(std::make_pair<int, std::string>(-666, "this"), STD);
	
	// std::cout << "print the tree" << std::endl;
	// tree.printTree();
	// std::cout << "print the node infos" << std::endl;
	// //tree.printNodes();

	// std::cout << "delete the node (key : 5)" << std::endl;
	// tree.deleteNode(5, STD);
	// std::cout << "print the upgraded tree and node infos..." << std::endl;
	// tree.printTree();
	// //tree.printNodes();
	
	// std::cout << "perform some other deletions (first key : -666, max key : 9)" << std::endl;
	// tree.deleteNode(-666, STD);
	// tree.deleteNode(9, STD);
	// std::cout << "displaying the upgraded tree" << std::endl;
	// tree.printTree();
	// //tree.printNodes();

	// std::cout << "adding some values to the tree (5, -666, 9), then display it..." << std::endl;
	// tree.treeInsertion(std::make_pair<int, std::string>(5, "this"), STD);
	// tree.treeInsertion(std::make_pair<int, std::string>(-666, "this"), STD);
	// tree.treeInsertion(std::make_pair<int, std::string>(9, "this"), STD);	
	// tree.printTree();
	// //tree.printNodes();

	// std::cout << "perform deletion for - 4 (case target node have two children left and right)" << std::endl;
	// tree.deleteNode(-4, STD);
	// tree.printTree();
	// //tree.printNodes();
	
	// std::cout << "perform deletion for 7 (case target node have only a right child)" << std::endl;
	// tree.deleteNode(7, STD);
	// tree.printTree();
	// //tree.printNodes();

	// std::cout << "add 7 another time (to be able to test next case...)" << std::endl;
	// tree.treeInsertion(std::make_pair<int, std::string>(7, "this"), STD);
	// tree.printTree();
	// //tree.printNodes();

	// std::cout << "perform deletion for 9 (case target have only a left child)" << std::endl;
	// tree.deleteNode(9, STD);
	// tree.printTree();
	// //tree.printNodes();

	// /* TESTING NODES METHODS */

	// std::cout << "testing nodes methods" << std::endl;
	// std::cout << "Add some keys to the tree" << std::endl;
	// tree.treeInsertion(std::make_pair<int, std::string>(9, "this"), STD);
	// tree.treeInsertion(std::make_pair<int, std::string>(-4, "this"), STD);
	// tree.printTree();
	// //tree.printNodes();

	// std::cout << "check if the node functions can retrieve max and min" << std::endl;
	// std::cout << "tree min = " << tree.getMinKey() << " and tree max = " << tree.getMaxKey() << std::endl;

	// std::cout << "iterate over the tree using getTreeSucc" << std::endl;
	// ft::Node<int, std::string>		*node = tree.getMinNode();
	
	// int			i = 0;
	// while (node)
	// {
	// 	std::cout << "node num " << i << " = " << node->_val.first << std::endl;
	// 	node = node->getTreeSucc(node);
	// 	i++;
	// }

	// std::cout << "iterate over the tree (reverse) using getTreePred" << std::endl;
	// node = tree.getMaxNode();
	// i = 0;
	// while (node)
	// {
	// 	std::cout << "node num " << i << " = " << node->_val.first << std::endl;
	// 	node = node->getTreePred(node);
	// 	i++;
	// }

	// /* TESTING THE AVL TREE METHODS */

	// std::cout << "Testing the AVL tree methods" << std::endl;
	
	// ft::AVLTree<int, std::string>					avl;

	// std::cout << "testing tree insertion" << std::endl;

	// std::cout << "testing insertion of a single value" << std::endl;
	// avl.treeInsertion(std::make_pair<int, std::string>(5, "this"));
	// avl.printTree();
	// avl.printNodes();

	// std::cout << "testing insertion with multiple values" << std::endl;
	// avl.treeInsertion(std::make_pair<int, std::string>(-66, "this"));
	// avl.treeInsertion(std::make_pair<int, std::string>(566, "this"));
	// avl.treeInsertion(std::make_pair<int, std::string>(0, "this"));
	// avl.treeInsertion(std::make_pair<int, std::string>(-1, "this"));
	// avl.treeInsertion(std::make_pair<int, std::string>(54, "this"));
	// avl.treeInsertion(std::make_pair<int, std::string>(-666, "this"));
	// avl.treeInsertion(std::make_pair<int, std::string>(42, "this"));
	// avl.printTree();
	// avl.printNodes();

	// /* TEST WITH RIGHT HEAVY AVL TREE */

	// ft::AVLTree<int, std::string>			avl_right_heavy;

	// std::cout << "testing with a right heavy AVL tree" << std::endl;	
	// std::cout << "inserting values 0, 1, 2, 3, 4, 5, 6, 7, 8, 9" << std::endl;

	// avl_right_heavy.treeInsertion(std::make_pair<int, std::string>(0, "truc"));
	// avl_right_heavy.treeInsertion(std::make_pair<int, std::string>(1, "truc"));
	// avl_right_heavy.treeInsertion(std::make_pair<int, std::string>(2, "truc"));
	// avl_right_heavy.treeInsertion(std::make_pair<int, std::string>(3, "truc"));
	// avl_right_heavy.treeInsertion(std::make_pair<int, std::string>(4, "truc"));
	// avl_right_heavy.treeInsertion(std::make_pair<int, std::string>(5, "truc"));
	// avl_right_heavy.treeInsertion(std::make_pair<int, std::string>(6, "truc"));
	// avl_right_heavy.treeInsertion(std::make_pair<int, std::string>(7, "truc"));
	// avl_right_heavy.treeInsertion(std::make_pair<int, std::string>(8, "truc"));
	// avl_right_heavy.treeInsertion(std::make_pair<int, std::string>(9, "truc"));
	// avl_right_heavy.printTree();
	// avl_right_heavy.printNodes();

	// /* TEST WITH LEFT HEAVY TREE */

	// ft::AVLTree<int, std::string>			avl_left_heavy;

	// std::cout << "testing with a left heavy AVL tree" << std::endl;
	// std::cout << "inserting values 0, -1, -2, -3, -4, -5, -6, -7, -8, -9" << std::endl;

	// avl_left_heavy.treeInsertion(std::make_pair<int, std::string>(-1, "truc"));
	// avl_left_heavy.treeInsertion(std::make_pair<int, std::string>(-2, "truc"));
	// avl_left_heavy.treeInsertion(std::make_pair<int, std::string>(-3, "truc"));
	// avl_left_heavy.treeInsertion(std::make_pair<int, std::string>(-4, "truc"));
	// avl_left_heavy.treeInsertion(std::make_pair<int, std::string>(-5, "truc"));
	// avl_left_heavy.treeInsertion(std::make_pair<int, std::string>(-6, "truc"));
	// avl_left_heavy.treeInsertion(std::make_pair<int, std::string>(-7, "truc"));
	// avl_left_heavy.treeInsertion(std::make_pair<int, std::string>(-8, "truc"));
	// avl_left_heavy.treeInsertion(std::make_pair<int, std::string>(-9, "truc"));
	// avl_left_heavy.printTree();
	// avl_left_heavy.printNodes();

	// /* TESTING DELETION IN AVL TREE */

	// std::cout << "testing deletion method in AVL tree" << std::endl;
	// std::cout << "supressing a single value (-8) with two children" << std::endl;
	// avl_left_heavy.deleteNode(-8);
	// avl_left_heavy.printTree();

	// std::cout << "supressing the node (-6)" << std::endl;
	// avl_left_heavy.deleteNode(-6);
	// avl_left_heavy.printTree();

	// std::cout << "suppressing a leaf value (-1)" << std::endl;
	// avl_left_heavy.deleteNode(-1);
	// avl_left_heavy.printTree();

	// std::cout << "suppressing a node with only a left child (-9)" << std::endl;
	// avl_left_heavy.deleteNode(-9);
	// avl_left_heavy.printTree();
	
	// std::cout << "suppressing a node with only a right child ()" << std::endl;
	// avl_left_heavy.deleteNode();
	// avl_left_heavy.printTree();

	/* TESTING A MIX OF OPERATIONS */

	ft::AVLTree<int, std::string>		avl_mix;

	std::cout << "testing a mix of operations of insertion and deletion..." << std::endl;
	std::cout << "add 5 values (0, -666, 777, 8, -4321), then delete 2nd and 3rd values (-666, 777)" << std::endl;

	avl_mix.treeInsertion(std::make_pair<int, std::string>(0, "truc"));
	avl_mix.treeInsertion(std::make_pair<int, std::string>(-666, "truc"));
	avl_mix.treeInsertion(std::make_pair<int, std::string>(777, "truc"));
	avl_mix.treeInsertion(std::make_pair<int, std::string>(8, "truc"));
	avl_mix.treeInsertion(std::make_pair<int, std::string>(-4321, "truc"));
	avl_mix.deleteNode(-666);
	avl_mix.deleteNode(777);
	avl_mix.printTree();

	std::cout << "inserting a value, then deleted it right away (42), then insert it again" << std::endl;
	avl_mix.treeInsertion(std::make_pair<int, std::string>(42, "truc"));
	avl_mix.deleteNode(42);
	avl_mix.treeInsertion(std::make_pair<int, std::string>(42, "truc"));
	std::cout << "size should be 4 and is " << avl_mix.getSize() << std::endl;
	avl_mix.printTree();
	avl_mix.printNodes();

	std::cout << "deleting the entire tree" << std::endl;
	avl_mix.deleteNode(42);
	avl_mix.deleteNode(8);
	avl_mix.deleteNode(0);
	avl_mix.deleteNode(-4321);
	avl_mix.printTree();
	avl_mix.printNodes();

	std::cout << "should display nothing" << std::endl;
	
	std::cout << "insert some values after deleting all values..." << std::endl;
	avl_mix.treeInsertion(std::make_pair<int, std::string>(8, "truc"));
	avl_mix.treeInsertion(std::make_pair<int, std::string>(-42, "truc"));
	avl_mix.treeInsertion(std::make_pair<int, std::string>(666, "truc"));
	avl_mix.printTree();
	avl_mix.printNodes();

	return (0);
}
