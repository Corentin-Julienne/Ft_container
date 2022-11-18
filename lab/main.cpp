/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:35:08 by cjulienn          #+#    #+#             */
/*   Updated: 2022/11/18 15:53:28 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <functional>
#include <iostream>
#include <memory>
#include <algorithm>

#include "binarySearchTree.hpp"
#include "Node.hpp"


int main(void)
{
	lab::binarySearchTree<std::string, int>	 tree;

	// std::pairs
	std::pair<std::string, int>	data1 = std::make_pair<std::string, int>("truc", 4);
	std::pair<std::string, int>	data2 = std::make_pair<std::string, int>("bob", 8);
	std::pair<std::string, int>	data3 = std::make_pair<std::string, int>("jason", 123);  

	/* testing procedure */
	tree.add_and_insert(data1);
	tree.add_and_insert(data2);
	tree.add_and_insert(data3);
	
	/* printing results */
	tree.printTree();
	
	return (0);
}
