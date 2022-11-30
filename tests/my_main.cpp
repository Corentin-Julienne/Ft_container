/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_main.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:24:34 by cjulienn          #+#    #+#             */
/*   Updated: 2022/11/30 13:48:08 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* includes for namespace ft */
//#include "./srcs/vector/Vector.hpp"
#include "./Colors.hpp"

/* includes form STD and STL */
#include <vector>
#include <iostream>
#include <string>
#include <map>

#include <functional>

/* include ft_containers */
#include "../srcs/map/redBlackTree.hpp" // to check BST and RBT
#include "../srcs/map/Map.hpp"
#include "../srcs/utils/pair.hpp"

/* the goal of this file is to compare the behaviour of the STL containers and my "homemade" containers */

// void	vector_verif_procedure(Colors &col)
// {
// 	std::vector<int>	stl_vect;
	
// 	std::cout << col.undYellow() << "Testing procedure with a std::vector<int>" << col.reset() << std::endl << std::endl;
// 	std::cout << "---------------------------------" << std::endl;
// 	// assign in vector
// 	std::cout << col.bdYellow() << "Trying to use assign(4, 5) in a vector" << col.end() << std::endl; 
// 	stl_vect.assign(4, 5);
// 	// checking the content
// 	for (int i = 0; i < 4; i++)
// 		std::cout << stl_vect[i] << std::endl;
// 	std::cout << "---------------------------------" << std::endl;
// 	for (int i = 0; i < 5; i++) // should trigger exception at the end
// 	{
// 		try
// 		{
// 			std::cout << stl_vect.at(i) << std::endl;
// 		}
// 		catch(const std::exception& e)
// 		{
// 			std::cerr << e.what() << '\n';
// 		}
// 	}
// 	std::cout << "---------------------------------" << std::endl;
// 	std::cout << "testing the clear public method clear()" << std::endl;
// 	stl_vect.clear();
// 	std::cout << "After using clear, the size of the vector is " << stl_vect.size() << std::endl;
// 	std::cout << "populating the vector with push_back()" << std::endl;
// 	stl_vect.push_back(7);
// 	stl_vect.push_back(8);
// 	std::cout << "Vector values are now " << stl_vect[0] << " and " << stl_vect[1] << std::endl;
// 	std::cout << "Clearing the vector using pop back" << std::endl;
// 	stl_vect.pop_back();
// 	stl_vect.pop_back();
// 	std::cout << "The size of the vector is now : " << stl_vect.size() << std::endl;
// 	std::cout << "---------------------------------" << std::endl;
// 	std::cout << "Trying vectors with iterators" << std::endl;

// 	std::vector<int>					vect_2(4, 6);
// 	std::vector<int>::iterator			itb = vect_2.begin();
// 	std::vector<int>::iterator			ite = vect_2.end();

// 	stl_vect.assign(itb, ite); // actually functionnal
// 	for (int i = 0; i < 4; i++)
// 		std::cout << "Val " << i << " of the vector is " << stl_vect[i] << std::endl;
// 	std::cout << "size of the vector is " << stl_vect.size() << std::endl;

// 	std::cout << "---------------------------------" << std::endl;
// 	std::cout << "removing the vector values with iterators" << std::endl;

// 	std::vector<int>::iterator			it_beg = stl_vect.begin();
// 	std::vector<int>::iterator			it_end = stl_vect.end();
// 	stl_vect.erase(it_beg, it_end);
// 	std::cout << "the new size of the vector is " << stl_vect.size() << std::endl;
	
// 	std::cout << "---------------------------------" << std::endl;
// 	std::cout << "adding new data to the vector using insert " << std::endl;
// 	stl_vect.insert(it_beg, itb, ite);
// 	std::cout << "stl_vect size is now " << stl_vect.size() << std::endl;
// 	for (int i = 0; i < 4; i++)
// 		std::cout << stl_vect[i] << std::endl;
// }

/* check the map binary tree to check wether there are error within it */
void	binary_tree_verification(Colors &col)
{
	std::cout << col.bdYellow() << "-------------------------------------" << col.reset() << std::endl;
	std::cout << col.bdYellow() << "Verification of binary tree functions" << col.reset() << std::endl;
	std::cout << col.bdYellow() << "-------------------------------------" << col.reset() << std::endl;

	ft::redBlackTree<int, std::string>	 tree;

	// std::pairs
	std::pair<int, std::string>	data1 = std::make_pair<int, std::string>(10, "truc");
	std::pair<int, std::string>	data2 = std::make_pair<int, std::string>(5, "rob");
	std::pair<int, std::string>	data3 = std::make_pair<int, std::string>(15, "jason");
	
	tree.BinarySearchTreeInsertion(data1);
	tree.BinarySearchTreeInsertion(data2);
	tree.BinarySearchTreeInsertion(data3);

	tree.printTree(); // should print 3 keys
	tree.deleteNode(5); // should remove the key
	tree.printTree(); // print tree again

	tree.postOrderTraversalDeletion(tree->_root); // ?
	system("leaks Containers"); // check for leaks

	std::cout << col.bdYellow() << "-----------------------------" << col.reset() << std::endl;
	std::cout << col.bdYellow() << "End of verification procedure" << col.reset() << std::endl;
	std::cout << col.bdYellow() << "-----------------------------" << col.reset() << std::endl;
}

/* check the map red black tree to check wether there are errors within it */
void	red_black_tree_verification(Colors &col)
{
	std::cout << "yet to implement" << std::endl;
}

void	separator(Colors &col)
{
	std::cout << col.bdYellow() << "----------------------------------------------------------" << col.reset() << std::endl;
}

/* will verif all map features and function */
void	map_verif_procedure(Colors &col)
{
	/* Binary Search Tree and Red Black Tree verifications */
	binary_tree_verification(col);
	red_black_tree_verification(col);

	
	/* Verification of map methods, comparing STL and FT namespaces */
	std::map<int, std::string>		stl_map;
	ft::map<int, std::string>		ft_map;

	std::cout << "Basic constructors activated" << std::endl; // checking basic constructors
	std::cout << "Checking the size method is functionnal and returns 0"<< std::endl;
	std::cout << "for the STL map the return value of size is " << stl_map.size() << std::endl;
	std::cout << "for the FT map the return value of size is " << ft_map.size() << std::endl;
	separator(col);
	std::cout << "checking the max_size method" << std::endl; // checking max_size
	std::cout << "for the STL map the return value of max_size is " << stl_map.max_size() << std::endl;
	std::cout << "for the FT map the return value of max_size is " << ft_map.max_size() << std::endl;
	separator(col);
	std::cout << "checking for the empty method when there is no pair inside map" << std::endl; // checking empty when empty
	std::cout << "P.D : should be equal to 0" << std::endl;
	std::cout << "for the STL map the return value of empty is " << stl_map.empty() << std::endl;
	std::cout << "for the FT map the return value of empty is " << ft_map.empty() << std::endl;
	separator(col);
	/* testing insertion */
	std::cout << "Testing the Insertion Method" << std::endl;
	// testing with single value insertion
	std::cout << "Testing insertion with a single value" << std::endl;

	std::string													example("truc");
	std::pair<std::map<int, std::string>::iterator, bool>		insert_res;			
	
	insert_res = stl_map.insert(std::make_pair<int, std::string>(4, example));
	
	std::cout << "Testing the return value of STL map function insert (with a single value)" << std::endl;
	std::cout << "key is " << insert_res.first << "and value is " << insert_res.second << std::endl; // to correct
	// check wether the size has been correctly incremented
	std::cout << "the new size of the map is " << stl_map.size() << " and should be equal to 1 (single value added)" 
	<< std::endl; // WIP


	separator(col);
	/* testing insert with a range of iterators */
	std::cout << "Testing insertion with a range of iterators" << std::endl;
	// STL MAP
	std::cout << "create a STL map and insert 5 pairs" << std::endl;
	std::map<int, std::string>					stl_full_map;
	stl_full_map.insert(std::make_pair<int, std::string>(65, "alpha"));
	stl_full_map.insert(std::make_pair<int, std::string>(84, "bravo"));
	stl_full_map.insert(std::make_pair<int, std::string>(4, "charlie"));
	stl_full_map.insert(std::make_pair<int, std::string>(844, "delta"));
	stl_full_map.insert(std::make_pair<int, std::string>(1084, "echo"));
	std::cout << "then add two iterators first and last" << std::endl;
	std::map<int, std::string>::iterator		stl_first = stl_full_map.begin();
	std::map<int, std::string>::iterator		stl_last = stl_full_map.end();
	std::cout << "insert this range of iterators into the empty STL map" << std::endl;
	stl_map.insert(stl_first, stl_last);
	// => print the stl_map content there
	separator(col);
	// FT MAP
	std::cout << "create a FT map and insert the same 5 pairs" << std::endl;
	ft::map<int, std::string>					ft_full_map;
	ft_full_map.insert(ft::make_pair<int, std::string>(65, "alpha"));
	ft_full_map.insert(ft::make_pair<int, std::string>(84, "bravo"));
	ft_full_map.insert(ft::make_pair<int, std::string>(4, "charlie"));
	ft_full_map.insert(ft::make_pair<int, std::string>(844, "delta"));
	ft_full_map.insert(ft::make_pair<int, std::string>(1084, "echo"));
	std::cout << "then add two iterators first and last" << std::endl;
	ft::map<int, std::string>::iterator		ft_first = ft_full_map.begin();
	ft::map<int, std::string>::iterator		ft_last = ft_full_map.end();
	std::cout << "insert this range of iterators into the empty FT map" << std::endl;
	ft_map.insert(ft_first, ft_last);
	// => verify the second insert function there
	separator(col);

	/* verifiying erase function */
	std::cout << "Verifying erase function" << std::endl;
	std::cout << "Verifying erase with a single value" << std::endl;
	// STL MAP
	std::cout << "Retrieving the first and last values of STL map" << std::endl;
	stl_map.erase(stl_first);
	stl_map.erase(stl_last);
	// => display new map values
	// FT MAP
	std::cout << "Retrieving the first and last values of FT map" << std::endl;
	ft_map.erase(ft_first);
	ft_map.erase(ft_last);
	// => display new map values
	separator(col);
	std::cout << "Verifying erase with a range of iterators" << std::endl;
	// STL MAP
	

	// FT MAP



	
	
	


	// testing some iterators
	
	
	// testing insert functions


	// testing erase function


	
	

	
	
}

int main(void)
{
	Colors		col;
	
	//vector_verif_procedure(col);
	map_verif_procedure(col);
	std::cout << col.bdGreen() << "Testing procedure complete" << col.end() << std::endl;
	return (0);
}
