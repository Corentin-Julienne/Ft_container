/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_main.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:24:34 by cjulienn          #+#    #+#             */
/*   Updated: 2022/11/14 13:24:03 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* includes for namespace ft */
//#include "./srcs/vector/Vector.hpp"
#include "./tests/Colors.hpp"

/* includes form STD and STL */
#include <vector>
#include <iostream>
#include <string>

/* the goal of this file is to compare the behaviour of the STL containers and my "homemade" containers */

void	vector_verif_procedure(Colors &col) // change the warnings
{
	std::cout << col.red() << "This is a test" << col.end() << "  default part not colorized" << std::endl;
	std::cout << col.bdBlue() << "This is a test" << col.end() << " default part not colorized" << std::endl;

	
}

int main(void)
{
	Colors		col;
	
	vector_verif_procedure(col);
	//map_verif_procedure();
	std::cout << "Testing procedure complete" << std::endl;
	return (0);
}
