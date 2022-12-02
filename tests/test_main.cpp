/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:24:34 by cjulienn          #+#    #+#             */
/*   Updated: 2022/12/01 17:16:18 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/test_includes.hpp"

/* case wrong instructions, to explain to user how to use it */
void	print_usage(void)
{
	std::cout << "Add only one arg when launching the program" << std::endl;
	std::cout << "Choose one of those : " << std::endl;
	std::cout << "map : triggers maps tests" << std::endl;
	std::cout << "tree : triggers binary search tree (red black tree) tests" << std::endl;
	std::cout << "vector : triggers vectors tests" << std::endl;
}

/* trigger for a test */
int main(int argc, char **argv) // to test
{
	Colors			col;
	std::string		arg(argv[1]);
	
	if (argc != 2)
	{
		std::cout << col.bdRed() << "Wrong number of arguments !!!" << col.reset() << std::endl;
		print_usage();
		return (0);
	}
	if (arg.compare("map"))
	{
		map_verif_procedure(col);
		// add map speedtest procedure
	}
	else if (arg.compare("tree"))
	{
		// add tree verif procedure
	}
	else if (arg.compare("vector")) 
	{
		vector_verif_procedure(col);
		// add vector speedtest procedure
	}
	else
		std::cout << col.bdRed() << "Wrong type of argument" << col.reset() << std::endl;
	std::cout << col.bdGreen() << "Testing procedure complete" << col.end() << std::endl;
	return (0);
}
