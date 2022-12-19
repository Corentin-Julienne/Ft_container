/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_tests.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:54:59 by cjulienn          #+#    #+#             */
/*   Updated: 2022/12/16 15:20:55 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/test_includes.hpp"

/* tree test should assess the tree solution used by map to 
implement its internal functionning */

/* BST verifs. contains : */
static void	binary_search_tree_verification(Colors &col)
{
	separator(col);
	std::cout << col.bdYellow() << "Testing binary search tree..." << col.reset() << std::endl;
	separator(col);

	ft::binarySearchTree<int, std::string>			tree; // example tree

	std::cout << "print the empty tree" << std::endl;
	tree.printTree();

	std::cout << "lets add 5 pairs to the tree" << std::endl;
	tree.binarySearchTreeInsertion(std::make_pair<int, std::string>(5, "this"));
	tree.binarySearchTreeInsertion(std::make_pair<int, std::string>(-6666, "is"));
	tree.binarySearchTreeInsertion(std::make_pair<int, std::string>(54, "a"));
	tree.binarySearchTreeInsertion(std::make_pair<int, std::string>(5232, "bloody"));
	tree.binarySearchTreeInsertion(std::make_pair<int, std::string>(0, "test"));

	std::cout << "print the tree" << std::endl;
	tree.printTree();

	std::cout << "print max and min" << std::endl;
	std::cout << tree.getMin() << "|" << tree.getMax() << std::endl;

	separator(col);
	std::cout << std::endl << col.bdYellow() << "BST tests over" << col.reset() << std::endl;
	separator(col);
}


/* check the map red black tree to check whether there are errors within it */
void	tree_verification(Colors &col)
{
	binary_search_tree_verification(col);
}
