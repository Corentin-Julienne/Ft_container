/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:35:08 by cjulienn          #+#    #+#             */
/*   Updated: 2022/12/19 15:07:08 by cjulienn         ###   ########.fr       */
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
#include "./binarySearchTree.hpp"
#include "./AVLTree.hpp"

static void	leaks_tracking(void)
{
	system("leaks Lab");
}

int main(void)
{	
	atexit(leaks_tracking);

	ft::binarySearchTree<int, std::string>			tree; // example tree
	ft::AVLTree<int, std::string>					avl_tree;

	std::cout << "print the empty tree" << std::endl;
	tree.printTree();

	std::cout << "lets add 5 pairs to the tree" << std::endl;
	tree.binarySearchTreeInsertion(std::make_pair<int, std::string>(5, "this"));
	tree.binarySearchTreeInsertion(std::make_pair<int, std::string>(7, "this"));
	tree.binarySearchTreeInsertion(std::make_pair<int, std::string>(6, "this"));
	tree.binarySearchTreeInsertion(std::make_pair<int, std::string>(9, "this"));
	tree.binarySearchTreeInsertion(std::make_pair<int, std::string>(-4, "this"));
	tree.binarySearchTreeInsertion(std::make_pair<int, std::string>(-1, "this"));
	tree.binarySearchTreeInsertion(std::make_pair<int, std::string>(-666, "this"));
	
	// tree.binarySearchTreeInsertion(std::make_pair<int, std::string>(-6, "is"));
	// tree.binarySearchTreeInsertion(std::make_pair<int, std::string>(-666, "a"));
	// tree.binarySearchTreeInsertion(std::make_pair<int, std::string>(-4, "a"));
	// tree.binarySearchTreeInsertion(std::make_pair<int, std::string>(50, "bloody"));
	// tree.binarySearchTreeInsertion(std::make_pair<int, std::string>(45, "bloody"));
	// tree.binarySearchTreeInsertion(std::make_pair<int, std::string>(65, "test"));
	// tree.binarySearchTreeInsertion(std::make_pair<int, std::string>(64, "other test"));
	// tree.binarySearchTreeInsertion(std::make_pair<int, std::string>(60, "other test"));
	// tree.binarySearchTreeInsertion(std::make_pair<int, std::string>(666, "other test"));
	
	std::cout << "print the tree" << std::endl;
	tree.printTree();
	std::cout << "print the node infos" << std::endl;
	tree.printNodes();

	tree.deleteNode(5);
	tree.printTree();
	tree.printNodes();	
	
	if (tree.getRoot() == nullptr)
		std::cout << "tree root is == nulltpr" << std::endl;
	else
		std::cout << tree.getRoot() << std::endl;
	std::cout << "print max and min" << std::endl;
	std::cout << tree.getMinKey() << " | " << tree.getMaxKey() << std::endl;
	
	return (0);
}
