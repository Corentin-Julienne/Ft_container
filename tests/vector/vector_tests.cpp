/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_tests.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:42:21 by cjulienn          #+#    #+#             */
/*   Updated: 2022/12/01 16:24:55 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/test_includes.hpp"

/* all the tests to assess the viability of ft::vector */
void	vector_verif_procedure(Colors &col)
{
	std::cout << "Vector verification procedure" << std::endl;
	separator(col);
	/* TEST WITH BASIC CONSTRUCTOR*/
	std::cout << "Testing basic constructors" << std::endl;
	
	std::vector<int>	stl_vect;
	ft::vector<int>		ft_vect;

	/* TEST OF SIZE */
	std::cout << "Verifying that the size of vector is 0" << std::endl;
	std::cout << "STL vector size is " << stl_vect.size() << std::endl;
	std::cout << "FT vector size is  " << ft_vect.size() << std::endl;
	separator(col);

	/* TEST OF MAX SIZE */
	/* max_size is the max number of elems that can be stored inside a vector. 
	It does not guarantee the actual possibility to store that much (possible mem problems) */
	std::cout << "Verifying the max_size method of vectors" << std::endl;
	std::cout << "stl_vect max_size = " << stl_vect.max_size() << std::endl;
	std::cout << "ft_vect max_size = " << ft_vect.max_size() << std::endl;
	separator(col);

	/* TEST OF CAPACITY */
	/* capacity is the size of allocated storage currently allocated */
	std::cout << "Verifying the capacity method of vectors" << std::endl;
	std::cout << "stl_vect capacity = " << stl_vect.capacity() << std::endl;
	std::cout << "ft_vect capacity = " << stl_vect.capacity() << std::endl;
	separator(col);

	/* TEST OF EMPTY */
	std::cout << "Verifying that empty is functionnal" << std::endl;
	std::cout << "stl_vect empty = " << stl_vect.empty() << std::endl;
	std::cout << "ft_vect empty = " << ft_vect.empty() << std::endl;
	separator(col);
	std::cout << "Printing the vectors (should be empty)" << std::endl;
	std::cout << "Printing STL vector" <<std::endl;
	for (int i = 0; i < stl_vect.size(); i++)
		std::cout << stl_vect[i] << std::endl;
	std::cout << "Printing FT vector" << std::endl;
	for (int i = 0; i < ft_vect.size(); i++)
		std::cout << ft_vect[i] << std::endl;
	separator(col);
	std::cout << "Testing insert method" << std::endl << std::endl;

	/* TEST OF INSERT WITH SINGLE VALUE*/
	std::cout << "Insert a single value" << std::endl;

	std::vector<int>::iterator		stl_it = stl_vect.begin(); // check wether it is useful when vector empty
	ft::vector<int>::iterator		ft_it = ft_vect.begin();

	std::cout << "Insert int of value 4 in stl vect..." << std::endl;
	stl_vect.insert(stl_it, 4);
	std::cout << "Insert int of value 4 in stl vect..." << std::endl;
	ft_vect.insert(ft_vect, 4);
	separator(col);

	/* TEST OF EMPTY (with values inside) */
	std::cout << "Checking that empty method now return false" << std::endl;
	std::cout << "stl_vect empty = " << stl_vect.empty() << std::endl;
	std::cout << "ft_vect empty = " << ft_vect.empty() << std::endl;
	separator(col);

	/* TEST OF OPERATOR []*/
	/* using operator[] to display the value */
	std::cout << "Verifying operator [] to display the vectors" << std::endl;
	std::cout << "stl_vect[0] = " << stl_vect[0] << std::endl;
	std::cout << "ft_vect[0] = " << ft_vect[0] << std::endl << std::endl;

	/* TEST OF AT */
	std::cout << "Verifying at() to display the vectors" << std::endl;
	std::cout << "stl_vect.at(0) = " << stl_vect.at(0) << std::endl;
	std::cout << "ft_vect.at(0) = " << ft_vect.at(0) << std::endl << std::endl;
	
	std::cout << "Checking if the size where incremented" << std::endl;
	std::cout << "The new size of stl_vect is " << stl_vect.size() << std::endl;
	std::cout << "The new size of ft_vect is" << ft_vect.size() << std::endl << std::endl;

	std::cout << "Checking if at with wrong index (e.g) 4 throw out-of-range exception" << std::endl;
	std::cout << "stl_vect.at(1) = " << stl_vect.at(1) << std::endl;
	std::cout << "ft_vect.at(1) = " << ft_vect.at(1) << std::endl;
	separator(col);
	std::cout << "Checking " << std::endl;
	
	
	separator(col);
	
	/* CHECKING ITERATORS */

	/* ITERATOR */ 
	std::cout << "Checking iterators" << std::endl;
	/* checking standard iterators */
	std::cout << "Starting to create a stl_vector and ft_vector with push_back mnethod..." << std::endl;

	std::vector<int>		stl_vector;
	ft::vector<int>			ft_vector;

	stl_vector.push_back(5);
	stl_vector.push_back(4);
	stl_vector.push_back(6);
	stl_vector.push_back(434);
	stl_vector.push_back(-63433434);

	/* push the same nums to ft_vector */
	ft_vector.push_back(5);
	ft_vector.push_back(4);
	ft_vector.push_back(6);
	ft_vector.push_back(434);
	ft_vector.push_back(-63433434);
	
	std::cout << "Verifying stl_vector content"<< std::endl;
	for (int i = 0; i < stl_vector.size(); i++)
		std::cout << "stl_vector[i] = " << stl_vector[i] << std::endl;
	std::cout << "Verifying ft_vector content" << std::endl;
	for (int i = 0; i < stl_vector.size(); i++)
		std::cout << "ft_vector[i] = " << ft_vector[i] << std::endl;
	
	std::cout << "Verifying the functionning of iterators begin and end" << std::endl;

	std::vector<int>::iterator	stl_itbeg =	stl_vector.begin();
	ft::vector<int>::iterator	ft_itbeg = ft_vector.begin();

	std::vector<int>::iterator	stl_itend = stl_vector.end();
	ft::vector<int>::iterator	ft_itend = ft_vector.end();

	std::cout << "Print stl_vector using iterators" << std::endl;
	while (stl_itbeg != stl_itend)
	{
		std::cout << *stl_itbeg << std::endl;
		stl_itbeg++;
	}
	std::cout << "Print ft_vector using iterators" << std::endl;
	while (ft_itbeg != ft_itend)
	{
		std::cout << *ft_itbeg << std::endl;
		ft_itbeg++;
	}	
	separator(col);

	/* TEST WITH CONST ITERATORS */
	std::cout << "Check with const iterators" << std::endl;
	
	std::vector<int>::const_iterator	const_stl_itbeg = stl_vector.cbegin();
	ft::vector<int>::const_iterator		const_ft_itbeg = ft_vector.cbegin(); // implement

	std::vector<int>::const_iterator	const_stl_itend = stl_vector.cend();
	ft::vector<int>::const_iterator		const_ft_itend = ft_vector.cend(); // implement

	std::cout << "Try to print stl_vector using const iterators (should fail)" << std::endl;
	while (const_stl_itbeg != const_stl_itend)
	{
		std::cout << *const_stl_itbeg << std::endl;
		const_stl_itbeg++;
	}
	std::cout << "Try to print ft_vector using const iterators (should fail)" << std::endl;
	while (const_ft_itbeg != const_ft_itend)
	{
		std::cout << *const_ft_itbeg << std::endl;
		const_ft_itbeg++;
	}
	separator(col);

	/* TEST WITH REVERSE ITERATOR */
	std::cout << "Check with reverse iterators" << std::endl;

	std::vector<int>::reverse_iterator	reverse_stl_itbeg = stl_vector.rbegin();
	std::vector<int>::reverse_iterator	reverse_stl_itend = stl_vector.rend();

	ft::vector<int>::reverse_iterator	reverse_ft_itbeg = ft_vector.rbegin();
	ft::vector<int>::reverse_iterator	reverse_ft_itend = ft_vector.rend();

	std::cout << "Try to print stl_vector using reverse iterators" << std::endl;
	while (reverse_stl_itbeg != reverse_stl_itend)
	{
		std::cout << *reverse_stl_itbeg << std::endl;
		reverse_stl_itbeg++;
	}
	std::cout << "Try to print ft_vector using reverse iterators" << std::endl;
	while (reverse_ft_itbeg != reverse_ft_itend)
	{
		std::cout << *reverse_ft_itbeg << std::endl;
		reverse_ft_itbeg++;
	}
	separator(col);

	/* TEST WITH CONST REVERSE ITERATOR */
	std::cout << "Check with const reverse iterators" << std::endl;
	
	std::vector<int>::const_reverse_iterator	const_reverse_stl_itbeg = stl_vector.crbegin();
	std::vector<int>::const_reverse_iterator	const_reverse_stl_itend = stl_vector.crend();

	ft::vector<int>::const_reverse_iterator		const_reverse_ft_itbeg = ft_vector.crbegin(); // implement
	ft::vector<int>::const_reverse_iterator		const_reverse_ft_itend = ft_vector.crend(); // implement

	std::cout << "Try to print stl_vector using const reverse iterators (should fail)" << std::endl;
	while (const_reverse_stl_itbeg != const_reverse_stl_itend)
	{
		std::cout << *const_reverse_stl_itbeg << std::endl;
		const_reverse_stl_itend++;
	}
	std::cout << "Try to print ft_vector using const reverse iterators (should fail)" << std::endl;
	while (const_reverse_ft_itbeg != const_reverse_ft_itend)
	{
		std::cout << *const_reverse_ft_itbeg << std::endl;
		const_reverse_ft_itbeg++;
	}
	separator(col);

	/* TEST OF FRONT AND BACK */
	std::cout << "Check the behaviour of vector methods front and back" << std::endl << std::endl;
	/* PD : when vector is empty, methods front and back have undefined behaviour */
	std::cout << "Check the behaviour of front" << std::endl;
	std::cout << "The result of stl_vector.front() = " << stl_vector.front() << std::endl;
	std::cout << "The result of ft_vector.front() = " << ft_vector.front() << std::endl << std::endl;
	std::cout << "Check the behaviour of back" << std::endl;
	std::cout << "The result of stl_vector.back() = " << stl_vector.back() << std::endl;
	std::cout << "The result of ft_vector.back() = " << ft_vector.back() << std::endl;
	separator(col);
	std::cout << "Testing vector clear methods" << std::endl;
	stl_vector.clear();
	ft_vector.clear();
	std::cout << "check the size of cleared vectors" << std::endl;
	std::cout << "size of stl_vector = " << stl_vector.size() << std::endl;
	std::cout << "size of ft_vector = " << ft_vector.size() << std::endl << std::endl;

	std::cout << "use clear again to check if it does not provoke bugs" << std::endl;
	stl_vector.clear();
	ft_vector.clear();
	std::cout << "size of stl_vector = " << stl_vector.size() << std::endl;
	std::cout << "size of ft_vector = " << ft_vector.size() << std::endl;
	separator(col);

	/* TEST OF GET ALLOCATOR */ 
	/* checking the behaviour of get_allocator*/
	std::cout << "check the get_allocator method" << std::endl; // << not overloaded
	std::cout << "get_allocator method of stl_vector = " << stl_vect.get_allocator() << std::endl;
	std::cout << "get_allocator method of ft_vector = " << ft_vector.get_allocator() << std::endl;
	
	separator(col);
	//---------------------------------------------------------------------------------------//
	std::cout << col.bdYellow() << "-----------------------------" << col.reset() << std::endl;
	std::cout << col.bdYellow() << "End of verification procedure" << col.reset() << std::endl;
	std::cout << col.bdYellow() << "-----------------------------" << col.reset() << std::endl;
}
