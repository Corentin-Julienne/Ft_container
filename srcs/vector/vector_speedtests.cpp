/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_speedtests.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 16:35:05 by cjulienn          #+#    #+#             */
/*   Updated: 2022/12/12 16:28:41 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/test_includes.hpp"
#include <time.h>

/* includes some speedtests for basic operations in vector 
It would be better to use std::chrono but it is C++11 (so forbidden by the subject, unfortunately) 
use : the C style clock in the header <time.h> */

/* print the result of the test */
static void	speedtest_result(Colors &col, std::string feature, double duration)
{
	std::cout << col.bdYellow() << "The time necessary for the " << feature << " feature is " 
	<< duration << col.end() << std::endl;
}

/* helps calc where to suppress when in the middle */
static std::size_t	calc_middle(std::size_t	size)
{
	if (size == 1)
		return 0;
	else
		return (size / 2);
}

/* vector speedtest compares a large number of operations (using vector methods). 
check especifically the methods of vector modification :
=> push_back
=> pop_back
=> insert
=> erase
=> assign
=> clear
=> resize
=> reserve
*/
static void	vector_speedtest(Colors &col)
{
	std::cout << col.bdYellow() << "Starting speedtest for vectors..." << col.reset() << std::endl;
	
	std::vector<int>	stl_int; // inititate an empty int vector
	clock_t		t;	// init clock
	double		exec_time;
	
	/* SPEEDTEST FOR PUSH_BACK */
	std::cout << "testing push back method with 10.000.000 values..." << std::endl;
	t = clock();
	for (std::size_t i = 0; i < 10000000; i++) 
		stl_int.push_back(i);
	t = clock() - t;
	exec_time = ((double)t)/CLOCKS_PER_SEC;
	speedtest_result(col, "push_back", exec_time);
	separator(col);
	
	/* SPEEDTEST FOR POP_BACK */
	std::cout << "testing pop_back, suppressing the 10.000.000 values previously inserted..." << std::endl;
	t = clock();
	for (std::size_t i = 0; i < 10000000; i++)
		stl_int.pop_back();
	t = clock() - t;
	exec_time = ((double)t)/CLOCKS_PER_SEC;
	speedtest_result(col, "pop_back", exec_time);
	separator(col);
	
	/* SPEEDTEST FOR INSERT */
	stl_int.push_back(666);
	std::cout << "testing the two versions of insert method with multiple values" << std::endl;

	/* void insert (iterator position, size_type n, const value_type& val) */
	std::cout << "testing with void insert (iterator position, size_type n, const value_type& val)" << std::endl;
	t = clock();
	stl_int.insert(stl_int.begin(), 10000000, 42);
	t = clock() - t;
	exec_time = ((double)t)/CLOCKS_PER_SEC;
	speedtest_result(col, "void insert (iterator position, size_type n, const value_type& val)", exec_time);
	separator(col);

	/* testing with void insert (iterator position, InputIterator first, InputIterator last) */  
	std::cout << "testing with void insert (iterator position, InputIterator first, InputIterator last);" << std::endl;
	std::vector<int> 	other_vect(stl_int);
	t = clock();
	stl_int.insert(stl_int.end(), other_vect.begin(), other_vect.end()); // verify
	t = clock() - t;
	exec_time = ((double)t)/CLOCKS_PER_SEC;
	speedtest_result(col, "void insert (iterator position, InputIterator first, InputIterator last)", exec_time);
	separator(col);
	
	/* SPEEDTEST FOR CLEAR */
	std::cout << "testing with clear..." << std::endl;
	t = clock();
	stl_int.clear();
	t = clock() - t;
	exec_time = ((double)t)/CLOCKS_PER_SEC;
	speedtest_result(col, "clear", exec_time);
	separator(col);

	/* SPEEDTEST FOR ERASE */
	std::cout << "testing with the two versions of erase..." << std::endl;

	for (std::size_t i = 0; i < 10000000; i++) // add value to the now empty vector
		stl_int.push_back(i);

	/* iterator erase (iterator position) */
	std::cout << "testing iterator erase (iterator position), deleting values at the beginning" << std::endl;
	t = clock();
	for (std::size_t i = 0; i < stl_int.size(); i++)
		stl_int.erase(stl_int.begin());
	t = clock() - t;
	exec_time = ((double)t)/CLOCKS_PER_SEC;
	speedtest_result(col, "erase (iterator position), deleting vals at the beg", exec_time);
	separator(col);

	for (std::size_t i = 0; i < 10000000; i++) // add value to the now empty vector
		stl_int.push_back(i);
	std::cout << "testing iterator erase (iterator position), deleting values at the end" << std::endl;
	t = clock();
	for (std::size_t i = 0; i < stl_int.size(); i++)
		stl_int.erase(stl_int.end() - 1); // verify that
	t = clock() - t;
	exec_time = ((double)t)/CLOCKS_PER_SEC;
	speedtest_result(col, "erase (iterator position), deleting vals at the end", exec_time);
	separator(col);

	for (std::size_t i = 0; i < 10000000; i++) // add value to the now empty vector
		stl_int.push_back(i);
	std::cout << "testing iterator erase (iterator position), deleting values at the middle" << std::endl;
	t = clock();
	for (std::size_t i = 0; i < stl_int.size(); i++)
		stl_int.erase(stl_int.begin() + (calc_middle(stl_int.size()))); // verify that
	t = clock() - t;
	exec_time = ((double)t)/CLOCKS_PER_SEC;
	speedtest_result(col, "erase (iterator position), deleting vals at the middle", exec_time);
	separator(col);

	/* iterator erase (iterator first, iterator last) */
	for (std::size_t i = 0; i < 10000000; i++) // add value to the now empty vector
		stl_int.push_back(i);
	std::cout << "testing ...iterator erase (iterator first, iterator last)" << std::endl;
	t = clock();
	stl_int.erase(stl_int.begin(), stl_int.end()); // to test
	t = clock() - t;
	exec_time = ((double)t)/CLOCKS_PER_SEC;
	speedtest_result(col, "erase (iterator first, iterator last)", exec_time);
	separator(col);

	/* SPEEDTEST FOR ASSIGN */

	for (std::size_t i = 0; i < 10000000; i++) // add value to the now empty vector
		stl_int.push_back(i);
	std::vector<int>			other_vect2;
	for (std::size_t i = 0; i < 10000000; i++)
		other_vect2.push_back(i);
	/* void assign (InputIterator first, InputIterator last); */
	std::cout << "assign 10.000.000 times other_vect_2 to test vector" << std::endl;
	t = clock();
	for (std::size_t i = 0; i < 10000000; i++)
		stl_int.assign(other_vect2.begin(), other_vect2.end() - 1);
	t = clock() - t;
	exec_time = ((double)t)/CLOCKS_PER_SEC;
	speedtest_result(col, "assign (InputIterator first, InputIterator last)", exec_time);
	separator(col);
	
	/* void assign (size_type n, const value_type& val); */
	std::cout << "assign 10.000.000 times 5 values (666)" << std::endl;
	t = clock();
	for (std::size_t i = 0; i < 10000000; i++)
		stl_int.assign(5, 666);
	t = clock() - t;
	exec_time = ((double)t)/CLOCKS_PER_SEC;
	speedtest_result(col, "assign (size_type n, const value_type& val)", exec_time);
	separator(col);

	/* SPEEDTEST FOR RESERVE */
	/* void reserve (size_type n); */
	std::cout << "reserve 10.000.000 times memory" << std::endl;
	t = clock();
	for (std::size_t i = 0; i < 10000000; i++)
		stl_int.reserve(666 + i);
	t = clock() - t;
	exec_time = ((double)t)/CLOCKS_PER_SEC;
	speedtest_result(col, "reserve", exec_time);
	separator(col);
	
	/* SPEEDTEST FOR RESIZE */
	/* void resize (size_type n, value_type val = value_type()); */
	std::cout << "resize 10.000.000 times" << std::endl;
	t = clock();
	for (std::size_t i = 0; i < 10000000; i++)
		stl_int.resize(666 + i, 42);
	t = clock() - t;
	exec_time = ((double)t)/CLOCKS_PER_SEC;
	speedtest_result(col, "resize", exec_time);
	separator(col);

	// ---------------------------------------------------------------------------------------- //
	std::cout << col.bdYellow() << "End of speedtests for vectors" << col.reset() << std::endl;
	std::cout << col.bdYellow() << "Please do not forget to compare the results with" 
	<< " either ft or stl vector" << col.reset() << std::endl;
}
