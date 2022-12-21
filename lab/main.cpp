/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:35:08 by cjulienn          #+#    #+#             */
/*   Updated: 2022/12/20 17:06:47 by cjulienn         ###   ########.fr       */
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

	/* TESTING THE AVL TREE METHODS */

	std::cout << "Testing the AVL tree methods" << std::endl;
	
	ft::AVLTree<int, std::string>					avl;

	// std::cout << "testing tree insertion" << std::endl;

	// std::cout << "testing insertion of a single value" << std::endl;
	avl.treeInsertion(std::make_pair<int, std::string>(5, "this"));
	// avl.printTree();
	// avl.printNodes();

	// std::cout << "testing insertion with multiple values" << std::endl;
	avl.treeInsertion(std::make_pair<int, std::string>(-66, "this"));
	avl.treeInsertion(std::make_pair<int, std::string>(566, "this"));
	avl.treeInsertion(std::make_pair<int, std::string>(0, "this"));
	avl.treeInsertion(std::make_pair<int, std::string>(-1, "this"));

	avl.printTree();
	avl.printNodes();
	
	// avl.treeInsertion(std::make_pair<int, std::string>(54, "this"));
	// avl.treeInsertion(std::make_pair<int, std::string>(-666, "this"));
	// avl.treeInsertion(std::make_pair<int, std::string>(42, "this"));
	// avl.printTree();
	// avl.printNodes();
	return (0);
}
