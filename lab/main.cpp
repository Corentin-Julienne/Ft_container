/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:35:08 by cjulienn          #+#    #+#             */
/*   Updated: 2022/11/24 12:48:01 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <functional>
#include <iostream>
#include <memory>
#include <algorithm>

#include "redBlackTree.hpp"

void	leaks_tracking(void)
{
	system("leaks Lab");
}

int main(void)
{
	atexit(leaks_tracking);
	
	lab::redBlackTree<int, std::string>	 tree;

	// std::pairs
	std::pair<int, std::string>	data1 = std::make_pair<int, std::string>(10, "truc");
	std::pair<int, std::string>	data2 = std::make_pair<int, std::string>(5, "rob");
	std::pair<int, std::string>	data3 = std::make_pair<int, std::string>(15, "jason");  

	/* testing procedure */
	tree.addAndInsert(data1);
	tree.addAndInsert(data2);
	tree.addAndInsert(data3);

	tree.deleteNode(5);
	/* printing results */
	tree.printTree();

	return (0);
}
