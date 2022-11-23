/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:35:08 by cjulienn          #+#    #+#             */
/*   Updated: 2022/11/23 16:31:36 by cjulienn         ###   ########.fr       */
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
	std::pair<int, std::string>	data1 = std::make_pair<int, std::string>(123, "truc");
	std::pair<int, std::string>	data2 = std::make_pair<int, std::string>(8, "rob");
	std::pair<int, std::string>	data3 = std::make_pair<int, std::string>(12, "jason");  

	/* testing procedure */
	tree.add_and_insert(data1);
	tree.add_and_insert(data2);
	tree.add_and_insert(data3);
	
	/* printing results */
	tree.printTree();
	
	return (0);
}
