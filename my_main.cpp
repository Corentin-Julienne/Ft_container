/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_main.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:24:34 by cjulienn          #+#    #+#             */
/*   Updated: 2022/11/14 16:15:51 by cjulienn         ###   ########.fr       */
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

void	vector_verif_procedure(Colors &col)
{
	std::vector<int>	stl_vect;
	
	std::cout << col.undYellow() << "Testing procedure with a std::vector<int>" << col.reset() << std::endl << std::endl;
	std::cout << "---------------------------------" << std::endl;
	// assign in vector
	std::cout << col.bdYellow() << "Trying to use assign(4, 5) in a vector" << col.end() << std::endl; 
	stl_vect.assign(4, 5);
	// checking the content
	for (int i = 0; i < 4; i++)
		std::cout << stl_vect[i] << std::endl;
	std::cout << "---------------------------------" << std::endl;
	for (int i = 0; i < 5; i++) // should trigger exception at the end
	{
		try
		{
			std::cout << stl_vect.at(i) << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	std::cout << "---------------------------------" << std::endl;
	std::cout << "testing the clear public method clear()" << std::endl;
	stl_vect.clear();
	std::cout << "After using clear, the size of the vector is " << stl_vect.size() << std::endl;
	std::cout << "populating the vector with push_back()" << std::endl;
	stl_vect.push_back(7);
	stl_vect.push_back(8);
	std::cout << "Vector values are now " << stl_vect[0] << " and " << stl_vect[1] << std::endl;
	std::cout << "Clearing the vector using pop back" << std::endl;
	stl_vect.pop_back();
	stl_vect.pop_back();
	std::cout << "The size of the vector is now : " << stl_vect.size() << std::endl;
	std::cout << "---------------------------------" << std::endl;
	std::cout << "Trying vectors with iterators" << std::endl;

	std::vector<int>					vect_2(4, 6);
	std::vector<int>::iterator			itb = vect_2.begin();
	std::vector<int>::iterator			ite = vect_2.end();

	stl_vect.assign(itb, ite); // actually functionnal
	for (int i = 0; i < 4; i++)
		std::cout << "Val " << i << " of the vector is " << stl_vect[i] << std::endl;
	std::cout << "size of the vector is " << stl_vect.size() << std::endl;

	std::cout << "---------------------------------" << std::endl;
	std::cout << "removing the vector values with iterators" << std::endl;

	std::vector<int>::iterator			it_beg = stl_vect.begin();
	std::vector<int>::iterator			it_end = stl_vect.end();
	stl_vect.erase(it_beg, it_end);
	std::cout << "the new size of the vector is " << stl_vect.size() << std::endl;
	
	std::cout << "---------------------------------" << std::endl;
	std::cout << "adding new data to the vector using insert " << std::endl;
	stl_vect.insert(it_beg, itb, ite);
	std::cout << "stl_vect size is now " << stl_vect.size() << std::endl;
	for (int i = 0; i < 4; i++)
		std::cout << stl_vect[i] << std::endl;
	
	
}

int main(void)
{
	Colors		col;
	
	vector_verif_procedure(col);
	//map_verif_procedure(col);
	std::cout << col.bdGreen() << "Testing procedure complete" << col.end() << std::endl;
	return (0);
}
