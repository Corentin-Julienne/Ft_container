/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_tests.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:42:21 by cjulienn          #+#    #+#             */
/*   Updated: 2022/12/08 16:07:15 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/test_includes.hpp"

/* These test are meant to compare the behaviour of the original std::vector and compares it to its ft::vector
counterpart.

The tests cover (written in that order) :

I) Constructors

=> basic constructors, advanced constructors

II) Iterators

=> testing basic iterators and their arithmetics [ static void test_iterator(Colors &col) ]
=> testing reverse iterators and their arithmetics [ static void test_reverse_iterator(Colors &col) ]
=> testing const iterators (including const reverse iterators) [ static void test_const_iterator(Colors &col) ]

III) Capacity

=> size
=> max_size
=> resize
=> capacity
=> empty
=> reserve

IV) Element Access

=> operator[]
=> at
=> front
=> back
=> data

V) Modifiers

=> assign
=> push_back
=> pop_back
=> insert
=> erase
=> swap
=> clear

VI) Non-member function overloads

Does not check for performance. Checks the relevant speedtests to check performance with a large number of data */

/* I - CONSTRUCTORS */

/* test all constructors and operator = overload */
static void	test_constructors(Colors &col) // to test
{
	separator(col);
	std::cout << col.bdYellow() << "Testing constructors..." << col.reset()
	<< std::endl << std::endl;
	separator(col);

	std::cout << "Testing basic constructors (empty vector)" << std::endl;
	
	std::cout << "Trying with an int vector..." << std::endl;
	std::vector<int>			test_int;
	for (std::size_t i = 0; i < test_int.size(); i++)
		std::cout << "test[" << i << "] = " << test_int[i] << std::endl;
	std::cout << "test size = " << test_int.size() << " and test capacity is " << test_int.capacity()
	<< std::endl << std::endl;
	
	std::cout << "Trying with a std::string vector..." << std::endl;
	std::vector<std::string>	test_str;
	for (std::size_t i = 0; i < test_str.size(); i++)
		std::cout << "test[" << i << "] = " << test_str[i] << std::endl;
	std::cout << "test size = " << test_str.size() << " and test capacity is " << test_str.capacity()
	<< std::endl << std::endl;

	std::cout << "Testing the following adavanced constructor : " << std::endl <<
	"explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());"
	<< std::endl;
	
	std::cout << "testing with an int vector" << std::endl;
	std::vector<int>		fill_int(42, 42);
	for (std::size_t i = 0; i < fill_int.size(); i++)
		std::cout << "test[" << i << "] = " << fill_int[i] << std::endl;
	std::cout << "test size = " << fill_int.size() << " and test capacity is " << fill_int.capacity()
	<< std::endl << std::endl;

	std::cout << "testing with a std::string vector" << std::endl;
	std::vector<std::string>	fill_str(42, "test");
	for (std::size_t i = 0; i < fill_str.size(); i++)
		std::cout << "test[" << i << "] = " << fill_str[i] << std::endl;
	std::cout << "test size = " << fill_str.size() << " and test capacity is " << fill_str.capacity()
	<< std::endl << std::endl;
	
	std::cout << "Testing with an int but filling o times the val 42" << std::endl;
	std::vector<int>	empty_int(0, 42);
	for (std::size_t i = 0; i < empty_int.size(); i++)
		std::cout << "test[" << i << "] = " << empty_int[i] << std::endl;
	std::cout << "test size = " << empty_int.size() << " and test capacity is " << empty_int.capacity()
	<< std::endl << std::endl;

	std::cout << "Testing with the following adavanced constructor :" << std::endl
	<< "template <class InputIterator>" << std::endl <<
	"vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());" << std::endl;

	std::cout << "Testing with a vector of int" << std::endl;
	std::vector<int> 	transfer_int;

	transfer_int.push_back(42);
	transfer_int.push_back(21);

	std::vector<int>	range_int(transfer_int.begin(), transfer_int.end());
	for (std::size_t i = 0; i < range_int.size(); i++)
		std::cout << "test[" << i << "] = " << range_int[i] << std::endl;
	std::cout << "test size = " << range_int.size() << " and test capacity is " << range_int.capacity()
	<< std::endl << std::endl;

	std::cout << "Testing with a vector of std::string" << std::endl;
	std::vector<std::string>	transfer_str;

	transfer_str.push_back("this is a ");
	transfer_str.push_back(" bloody test");
	
	std::vector<std::string>	range_str(transfer_str.begin(), transfer_str.end());
	for (std::size_t i = 0; i < range_str.size(); i++)
		std::cout << "test[" << i << "] = " << range_str[i] << std::endl;
	std::cout << "test size = " << range_str.size() << " and test capacity is " << range_str.capacity()
	<< std::endl << std::endl;

	std::cout << "Testing with copy constructor" << std::endl;
	std::vector<int>		copy_test;

	copy_test.push_back(21);
	copy_test.push_back(42);

	std::vector<int>		copy(copy_test);
	for (std::size_t i = 0; i < copy.size(); i++)
		std::cout << "test[" << i << "] = " << copy[i] << std::endl;
	std::cout << "test size = " << copy.size() << " and test capacity is " << copy.capacity()
	<< std::endl << std::endl;
	
	std::cout << "testing if modify one modify the other one" << std::endl;
	copy.push_back(666);
	for (std::size_t i = 0; i < 3; i++)
	{
		std::cout << "copy[" << i << "] = " << copy.at(i) << std::endl;
		std::cout << "copy_test[" << i << "] = " << copy_test.at(i) << std::endl;
	}
	
	std::cout << std::endl << "Testing with overloaded operator =" << std::endl;
	std::vector<int>	copy_equal = copy_test;
	for (std::size_t i = 0; i < copy_equal.size(); i++)
		std::cout << "test[" << i << "] = " << copy_equal[i] << std::endl;
	std::cout << "test size = " << copy_equal.size() << " and test capacity is " << copy_equal.capacity()
	<< std::endl << std::endl;

	std::cout << "testing if modify one modify the other one" << std::endl;
	copy_equal.push_back(666);
	for (std::size_t i = 0; i < 3; i++)
	{
		std::cout << "copy_equal[" << i << "] = " << copy_equal.at(i) << std::endl;
		std::cout << "copy_test[" << i << "] = " << copy_test.at(i) << std::endl;
	}	

	separator(col);
	std::cout << std::endl << col.bdYellow() << "Constructors tests over" << col.reset() << std::endl;
	separator(col);
}

/* II - ITERATORS */

/*  should test the iterators functionnality and their behaviour */
static void	test_iterator(Colors &col) // to test
{
	separator(col);
	std::cout << col.bdYellow() << "Testing iterators method..." << col.reset()
	<< std::endl << std::endl;
	separator(col);
	
	std::vector<int>		test;

	std::cout << "Creating a vector with ints..." << std::endl;
	
	test.push_back(5);
	test.push_back(76);
	test.push_back(-4567);
	test.push_back(0);
	test.push_back(-1);

	std::vector<int>::iterator		first = test.begin();
	std::vector<int>::iterator		last = test.end();

	std::cout << "Check if we can print first and last (test.begin() and test.last() - 1)" << std::endl;
	std::cout << "first is " << *first << " and last is " << (*last - 1) << std::endl;
	
	std::cout << "Try to display all vector values with iterators..." << std::endl;
	while (first != last)
	{
		std::size_t	i = 0;
		
		std::cout << "test[" << i << "] = " << *first << std::endl;
		i++;
		first++;
	}
	
	std::cout << "Testing iterator arithmetic..." << std::endl;
	
	std::cout << "Testing -- operator..." << std::endl;
	std::vector<int>::iterator		op_minmin = test.end();
	op_minmin--;
	std::cout << "The iterator, one deferenced, should print the last value of the vector..." << std::endl;
	std::cout << "The value printed is " << *op_minmin << std::endl << std::endl;

	std::cout << "Testing ++ operator..."<< std::endl;
	std::vector<int>::iterator		op_plusplus = test.begin();
	std::cout << "The iterator, once dereference, should print the second value of the vector..." << std::endl;
	std::cout << "the value printed is " << *(++op_plusplus) << std::endl << std::endl;		

	std::cout << "Testing --(int) operator" << std::endl;
	std::vector<int>::iterator		op_minint = test.begin() + 1;
	std::cout << "The iterator, once dereferenced, should print the first value of vector"
	<< "then display the second value when printing a second time..." << std::endl;
	std::cout << "dereferncing once = " << *(op_minint--) << " ,then dereferencing again = "
	<< *op_minint << std::endl << std::endl;

	std::cout << "Testing ++(int) operator..."<< std::endl;
	std::vector<int>::iterator		op_plusint = test.begin();
	std::cout << "The iterator, once dereferenced, should print the first value of vector"
	<< "then display the second value when printing a second time..." << std::endl;
	std::cout << "dereferncing once = " << *(op_plusint++) << ", then dereferencing again = " << *op_plusint
	<< std::endl << std::endl;

	std::cout << "Testing - operator..." << std::endl;
	std::vector<int>::iterator		op_min = test.end();
	std::cout << "Should print the last int stored in the vector" << std::endl;
	std::cout << "Value printed is : " << *op_min - 1 << std::endl << std::endl;

	std::cout << "Testing + operator..." << std::endl;
	std::vector<int>::iterator		op_plus = test.begin();
	std::cout << "Should print the second int stored in the vector" << std::endl;
	std::cout << "Value printed is : " << *op_plus + 1 << std::endl << std::endl;

	std::cout << "Testing += operator..." << std::endl;
	std::vector<int>::iterator		op_plusequal = test.begin();
	op_plusequal += test.size() - 1;
	std::cout << "Once dereferenced, value printed should be the last value of the vector..." << std::endl;
	std::cout << "Value printed is " << *op_plusequal << std::endl << std::endl;

	std::cout << "Testing -= operator..." << std::endl;
	std::vector<int>::iterator		op_minequal = test.end();
	op_plusequal -= test.size() - 1;
	std::cout << "Once dereferenced, value printed should be the first value of the vector..." << std::endl;
	std::cout << "Value printed is " << *op_minequal << std::endl << std::endl;

	std::cout << "Testing a mix of iterator arithmetics..." << std::endl;
	std::vector<int>::iterator		op_arit1 = test.begin();
	std::vector<int>::iterator		op_arit2 = test.end();
	op_arit1 += 3;
	op_arit1 -= 2;
	std::cout << "test.begin += 3, -=2, -1, +2 = " << *(op_arit1 - 1 + 2) << std::endl;
	op_arit2 -= 3;
	op_arit2 += 0;
	++op_arit2;
	std::cout << "test.end -= 3, +=0, ++1, 1++" << *(op_arit2--) << std::endl << std::endl;

	std::cout << "Testing -> operator (* operator has already being tested a lot)" << std::endl;
	// TO IMPLEMENT

	std::cout << "Testing relationnal operators..." << std::endl;

	std::cout << "Testing == and !=" << std::endl;
	std::vector<int>::iterator		it1 = test.begin();
	std::vector<int>::iterator		it2 = test.begin();
	std::vector<int>::iterator		it3 = test.end();

	std::cout << "it1 and it2 should be equals..." << std::endl;
	std::cout << "it1 == it2 = " << std::boolalpha << (it1 == it2) << std::endl;
	std::cout << "it1 != it2 = " << std::boolalpha << (it1 != it2) << std::endl;
	std::cout << "it1 and it3 should be different..."<< std::endl;
	std::cout << "it1 != it3 = " << std::boolalpha << (it1 != it3) << std::endl; 
	std::cout << "it1 == it3 = " << std::boolalpha << (it1 == it3) << std::endl << std::endl;
	
	std::cout << "Testing < and > operators..." << std::endl;
	std::cout << "it1 should be superior to it3" << std::endl;
	std::cout << "it1 < it3 = " << std::boolalpha << (it1 < it3) << std::endl;
	std::cout << "it1 > it3 = " << std::boolalpha << (it1 > it3) << std::endl << std::endl;

	std::cout << "Testing <= and >= operators..." << std::endl;
	std::cout << "it1 <= it3 = " << std::boolalpha << (it1 <= it3) << std::endl;
	std::cout << "it1 >= it3 = " << std::boolalpha << (it1 >= it3) << std::endl;
	std::cout << "Incrementing it1..." << std::endl;
	it1++;
	std::cout << "it1 <= it3 = " << std::boolalpha << (it1 <= it3) << std::endl;
	std::cout << "it1 >= it3 = " << std::boolalpha << (it1 >= it3) << std::endl<< std::endl;
	
	separator(col);
	std::cout << std::endl << col.bdYellow() << "iterator tests over" << col.reset() << std::endl;
	separator(col);
}

/*  should test reverse iterators functionnality and their behaviours */
static void	test_reverse_iterator(Colors &col) // to test
{
	separator(col);
	std::cout << col.bdYellow() << "Testing reverse iterators..." << col.reset()
	<< std::endl << std::endl;
	separator(col);

	std::vector<int>		test;

	std::cout << "Creating a vector with ints..." << std::endl;
	
	test.push_back(5);
	test.push_back(76);
	test.push_back(-4567);
	test.push_back(0);
	test.push_back(-1);

	std::vector<int>::reverse_iterator		first = test.rbegin();
	std::vector<int>::reverse_iterator		last = test.rend();

	std::cout << "Check if we can print first and last (test.begin() and test.last() - 1)" << std::endl;
	std::cout << "first is " << *first << " and last is " << (*last - 1) << std::endl;
	
	std::cout << "Try to display all vector values with iterators (reverse order)..." << std::endl;
	while (first != last)
	{
		std::size_t	i = 0;
		
		std::cout << "test[" << i << "] = " << *first << std::endl;
		i++;
		first++;
	}
	
	std::cout << "Testing reverse_iterator arithmetic..." << std::endl;

	std::cout << "Testing -- operator..." << std::endl;
	std::vector<int>::reverse_iterator		op_minmin = test.rend();
	op_minmin--;
	std::cout << "The iterator, one deferenced, should print the first value of the vector..." << std::endl;
	std::cout << "The value printed is " << *op_minmin << std::endl << std::endl;

	std::cout << "Testing ++ operator..."<< std::endl;
	std::vector<int>::reverse_iterator		op_plusplus = test.rbegin();
	std::cout << "The iterator, once dereference, should print the penultimate value of the vector..." << std::endl;
	std::cout << "the value printed is " << *(++op_plusplus) << std::endl << std::endl;		

	std::cout << "Testing --(int) operator" << std::endl;
	std::vector<int>::reverse_iterator		op_minint = test.rbegin() + 1;
	std::cout << "The iterator, once dereferenced, should print the last value of vector"
	<< "then display the penultimate value when printing a second time..." << std::endl;
	std::cout << "dereferncing once = " << *(op_minint--) << " ,then dereferencing again = "
	<< *op_minint << std::endl << std::endl;

	std::cout << "Testing ++(int) operator..."<< std::endl;
	std::vector<int>::reverse_iterator		op_plusint = test.rbegin();
	std::cout << "The iterator, once dereferenced, should print the last value of vector"
	<< "then display the penultimate value when printing a second time..." << std::endl;
	std::cout << "dereferncing once = " << *(op_plusint++) << ", then dereferencing again = " << *op_plusint
	<< std::endl << std::endl;

	std::cout << "Testing - operator..." << std::endl;
	std::vector<int>::reverse_iterator		op_min = test.rend();
	std::cout << "Should print the first int stored in the vector" << std::endl;
	std::cout << "Value printed is : " << *op_min - 1 << std::endl << std::endl;

	std::cout << "Testing + operator..." << std::endl;
	std::vector<int>::reverse_iterator		op_plus = test.rbegin();
	std::cout << "Should print the penultimate int stored in the vector" << std::endl;
	std::cout << "Value printed is : " << *op_plus + 1 << std::endl << std::endl;

	std::cout << "Testing += operator..." << std::endl;
	std::vector<int>::reverse_iterator		op_plusequal = test.rbegin();
	op_plusequal += test.size() - 1;
	std::cout << "Once dereferenced, value printed should be the first value of the vector..." << std::endl;
	std::cout << "Value printed is " << *op_plusequal << std::endl << std::endl;

	std::cout << "Testing -= operator..." << std::endl;
	std::vector<int>::reverse_iterator		op_minequal = test.rend();
	op_plusequal -= test.size() - 1;
	std::cout << "Once dereferenced, value printed should be the last value of the vector..." << std::endl;
	std::cout << "Value printed is " << *op_minequal << std::endl << std::endl;

	std::cout << "Testing a mix of iterator arithmetics..." << std::endl;
	std::vector<int>::reverse_iterator		op_arit1 = test.rbegin();
	std::vector<int>::reverse_iterator		op_arit2 = test.rend();
	op_arit1 += 3;
	op_arit1 -= 2;
	std::cout << "test.begin += 3, -=2, -1, +2 = " << *(op_arit1 - 1 + 2) << std::endl;
	op_arit2 -= 3;
	op_arit2 += 0;
	++op_arit2;
	std::cout << "test.end -= 3, +=0, ++1, 1++" << *(op_arit2--) << std::endl << std::endl;

	std::cout << "Testing -> operator (* operator has already being tested a lot)" << std::endl;
	// TO IMPLEMENT

	std::cout << "Testing relationnal operators..." << std::endl;

	std::cout << "Testing == and !=" << std::endl;
	std::vector<int>::reverse_iterator		it1 = test.rbegin();
	std::vector<int>::reverse_iterator		it2 = test.rbegin();
	std::vector<int>::reverse_iterator		it3 = test.rend();

	std::cout << "it1 and it2 should be differents..." << std::endl;
	std::cout << "it1 == it2 = " << std::boolalpha << (it1 == it2) << std::endl;
	std::cout << "it1 != it2 = " << std::boolalpha << (it1 != it2) << std::endl;
	std::cout << "it1 and it3 should be equals..."<< std::endl;
	std::cout << "it1 != it3 = " << std::boolalpha << (it1 != it3) << std::endl; 
	std::cout << "it1 == it3 = " << std::boolalpha << (it1 == it3) << std::endl << std::endl;
	
	std::cout << "Testing < and > operators..." << std::endl;
	std::cout << "it1 should be inferior to it3" << std::endl;
	std::cout << "it1 < it3 = " << std::boolalpha << (it1 < it3) << std::endl;
	std::cout << "it1 > it3 = " << std::boolalpha << (it1 > it3) << std::endl << std::endl;

	std::cout << "Testing <= and >= operators..." << std::endl;
	std::cout << "it1 <= it3 = " << std::boolalpha << (it1 <= it3) << std::endl;
	std::cout << "it1 >= it3 = " << std::boolalpha << (it1 >= it3) << std::endl;
	std::cout << "Incrementing it1..." << std::endl;
	it1++;
	std::cout << "it1 <= it3 = " << std::boolalpha << (it1 <= it3) << std::endl;
	std::cout << "it1 >= it3 = " << std::boolalpha << (it1 >= it3) << std::endl<< std::endl;
	
	separator(col);
	std::cout << std::endl << col.bdYellow() << "iterator tests over" << col.reset() << std::endl;
	separator(col);
}

/* check const iterators : const_reverse_iterator AND reverse_iterator */
static void	test_const_iterator(Colors & col) // WIP
{
	separator(col);
	std::cout << col.bdYellow() << "Testing const iterators..." << col.reset()
	<< std::endl << std::endl;
	separator(col);

	std::vector<int>		test;
	
	std::vector<int>::const_iterator	const_it_beg = ;

	separator(col);
	std::cout << std::endl << col.bdYellow() << "const iterators tests over" << col.reset() << std::endl;
	separator(col);
}

/* III - CAPACITY */

/* test the capacity methods of vector. Contains : 
=> size
=> max_size
=> resize
=> capacity
=> empty
=> reserve */
static void	test_capacity_methods(Colors &col) // to test
{
	separator(col);
	std::cout << col.bdYellow() << "Testing capacity methods..." << col.reset()
	<< std::endl << std::endl;
	separator(col);

	std::vector<std::string>		test;
	
	std::cout << "Creating an empty array" << std::endl;
	std::cout << "size should be equal to 0 and empty to false..." << std::endl;
	std::cout << "test.size = " << test.size() << " and test.empty = " << std::boolalpha << test.empty() << std::endl;

	std::cout << "pushing back some values to test..." << std::endl;
	
	test.push_back("salut");
	test.push_back("");
	test.push_back("je");
	test.push_back("s appelle");
	test.push_back("Groot");

	std::cout << "test.empty = " << std::boolalpha << test.empty() << " and test.size = " << test.size() << std::endl;
	
	/* MAX SIZE */
	std::cout << "Testing max_size method..." << std::endl;
	std::cout << "test.max_size = " << test.max_size() << std::endl << std::endl;

	/* RESIZE */

	std::cout << "Testing resize method" << std::endl;

	/* If n is smaller than the current container size,
	the content is reduced to its first n elements, removing those beyond (and destroying them). */
	std::cout << "resize with n smaller to current container size" << std::endl;
	std::cout << "removing the last element" << std::endl;
	test.resize(4); // should remove the last element
	std::cout << "display the updated vector" << std::endl;
	for (std::size_t i = 0; i < test.size(); i++)
		std::cout << "test[" << i << "] = " << test[i] << std::endl;
	std::cout << "test capacity = " << test.capacity() << " and its size is equal to " << test.size() << std::endl;

	/* If n is greater than the current container size, the content is expanded by inserting at the end 
	as many elements as needed to reach a size of n. If val is specified, the new elements are initialized as copies of val,
	otherwise, they are value-initialized. */
	std::cout << "resize with n greater than the vector size" << std::endl;
	std::cout << "adding an element to the vector, with value 42" << std::endl;
	test.resize(5, "42");
	std::cout << "display the updated vector" << std::endl;
	for (std::size_t i = 0; i < test.size(); i++)
		std::cout << "test[" << i << "] = " << test[i] << std::endl;
	std::cout << "test capacity = " << test.capacity() << " and its size is equal to " << test.size() << std::endl;

	std::cout << "adding an element to the vector but without initializing it" << std::endl;
	test.resize(6);
	std::cout << "display the updated vector" << std::endl;
	for (std::size_t i = 0; i < test.size(); i++)
		std::cout << "test[" << i << "] = " << test[i] << std::endl;
	std::cout << "test capacity = " << test.capacity() << " and its size is equal to " << test.size() << std::endl;

	std::cout << "resize with n == test.size()" << std::endl;
	test.resize(6);
	std::cout << "display the updated vector" << std::endl;
	for (std::size_t i = 0; i < test.size(); i++)
		std::cout << "test[" << i << "] = " << test[i] << std::endl;
	std::cout << "test capacity = " << test.capacity() << " and its size is equal to " << test.size() << std::endl;

	/* CAPACITY */
	std::cout << "Testing capacity method..." << std::endl;
	std::cout << "test.capacity = " << test.capacity() << std::endl;

	/* insert some values to check the changes in capacity */
	std::cout << "Checking changes in capacity related to augmentations in size..." << std::endl;
	test.push_back("Check"); 
	test.push_back("changes ");
	test.push_back("in");
	test.push_back("vector");
	test.push_back("capacity");
	
	std::cout << "test.capacity = " << test.capacity() << std::endl;

	std::cout << "Checking changes in capacity related to diminutions in size..." << std::endl;
	test.pop_back();
	test.pop_back();
	test.pop_back();
	test.pop_back();

	std::cout << "test.capacity = " << test.capacity() << std::endl;

	/* RESERVE */
	std::cout << "testing reserve"  << std::endl;
	std::cout << "base test.capacity = " << std::endl;
	std::cout << "reserving a capacity of at least 67" << std::endl;
	test.reserve(67);
	std::cout << "new capacity = " << test.capacity() << std::endl;
	
	std::cout << "reserving a capacity of 0 (should change nothing)" << std::endl;
	test.reserve(0);
	std::cout << "new capacity = " << test.capacity() << std::endl;
	
	std::cout << "reserving a capacity superior to max_size() : should throw an error" << std::endl;
	test.reserve(test.max_size() + 1);
	std::cout << "new capacity = " << test.capacity() << std::endl; 

	separator(col);
	std::cout << std::endl << col.bdYellow() << "capacity tests over" << col.reset() << std::endl;
	separator(col);
}

/* IV - ELEMENT ACCESS */

static void	test_access_elems(Colors &col) // to test
{
	separator(col);
	std::cout << col.bdYellow() << "Testing methods to access elements in the vector..." << col.reset()
	<< std::endl << std::endl;
	separator(col);

	std::vector<int>			test;
	
	test.push_back(5);
	test.push_back(76);
	test.push_back(-4567);
	test.push_back(0);
	test.push_back(-1);

	std::cout << "A test vector with 5 values has been created [5, 76, -4567, 0, -1]" << std::endl;
	std::cout << "Verifying the behaviour of operator []" << std::endl;
	for (std::size_t i = 0; i < test.size(); i++)
		std::cout << "test[" << i << "] = " << test[i] << std::endl;
	
	std::cout << "Testing test.at with valid indexes" << std::endl;
	for (std::size_t i = 0; i < test.size(); i++)
		std::cout << "test.at(" << i << ") = " << test.at(i) << std::endl;
	std::cout << "Testing test.a with invalid index" << std::endl;
		std::cout << test.at(test.size()) << std::endl;

	/* data is C+11 BUT has been declared C++98 retroactively for conveniance */
	std::cout << "Testing with test.data" << std::endl;
	
	int	*ptn = test.data();
	
	std::cout << "iterating with an int pointer (should produce the same result as iterating with " 
	<< "a for loop and at or [])" << std::endl;
	for (std::size_t i = 0;  i < test.size(); i++) // to test
	{
		std::cout << *ptn << std::endl;
		ptn++;
	}
	
	/* front and back on empty vector got undefined behaviour !!! */
	std::cout << "Testing test.front and test.back" << std::endl;
	std::cout << "test.front() = " << test.front() << std::endl;
	std::cout << "test.back() = " << test.back() << std::endl;

	std::cout << "Testing front and back with another vector with one value" << std::endl;
	
	std::vector<int>		test_2;

	test_2.push_back(42);
	std::cout << "front and back should have the same value (42)" << std::endl;
	std::cout << "test_2.front() = " << test_2.front() << " and test_2.back = " << test_2.back() << std::endl;
		
	separator(col);
	std::cout << std::endl << col.bdYellow() << "Access tests over" << col.reset() << std::endl;
	separator(col);
}

/* V - MODIFIERS */

/* test all the assign version */
static void test_assign(Colors &col) // to test
{
	separator(col);
	std::cout << col.bdYellow() << "Testing assign..." << col.reset()
	<< std::endl << std::endl;
	separator(col);

	std::cout << "Testing this assign version : template <class InputIterator>"
	<< "void assign (InputIterator first, InputIterator last);" << std::endl;

	std::vector<int>			test;

	test.push_back(5);
	test.push_back(76);
	test.push_back(-4567);
	test.push_back(0);
	test.push_back(-1);

	std::cout << "Create an empty vector and adding some values in it..." << std::endl;
	std::cout << "display vector content : " << std::endl;
	for (std::size_t i = 0; i < test.size(); i++)
		std::cout << "test[" << i << "] = " << test[i] << std::endl;
	std::cout << "test size = " << test.size() << " and test capacity is " << test.capacity()
	<< std::endl << std::endl;

	std::vector<int>			other_vect;

	test.push_back(42);
	test.push_back(21);
	test.push_back(17);
	
	std::vector<int>::iterator	it_beg = other_vect.begin();
	std::vector<int>::iterator	it_end = other_vect.end();

	std::cout << "Create another vector and its iterators begin and end..." << std::endl;
	std::cout << "Displaying this other vector" << std::endl;
	for (std::size_t i = 0; i< other_vect.size(); i++)
		std::cout << "other_vect[" << i << "] = " << other_vect[i] << std::endl;
	std::cout << "other_vect size = " << other_vect.size() << " and other_vect capacity is "
	<< other_vect.capacity() << std::endl << std::endl;

	std::cout << "using insert to replace the content of test vector by other_vect" << std::endl;
	test.assign(it_beg, it_end);
	std::cout << "Displaying the test vector after modifs" << std::endl;
	for (std::size_t i = 0; i< test.size(); i++)
		std::cout << "test[" << i << "] = " << test[i] << std::endl;
	std::cout << "test size = " << test.size() << " and test capacity is "
	<< test.capacity() << std::endl << std::endl;

	std::cout << "Testing assign with iterators from the same container" << std::endl;
	test.assign(test.begin(), test.end());
	std::cout << "Displaying the test vector after modifs" << std::endl;
	for (std::size_t i = 0; i< test.size(); i++)
		std::cout << "test[" << i << "] = " << test[i] << std::endl;
	std::cout << "test size = " << test.size() << " and test capacity is "
	<< test.capacity() << std::endl << std::endl;

	std::cout << "Testing assign with iterators from the same container again" << std::endl;
	test.assign(test.begin() + 1, test.end());
	std::cout << "Displaying the test vector after modifs" << std::endl;
	for (std::size_t i = 0; i< test.size(); i++)
		std::cout << "test[" << i << "] = " << test[i] << std::endl;
	std::cout << "test size = " << test.size() << " and test capacity is "
	<< test.capacity() << std::endl << std::endl;

	std::cout << "Testing with iterators from another container of size 1" << std::endl;
	std::vector<int>		test2;
	test2.push_back(42);
	test.assign(test2.begin(), test2.end());
	std::cout << "Displaying the test vector after modifs" << std::endl;
	for (std::size_t i = 0; i< test.size(); i++)
		std::cout << "test[" << i << "] = " << test[i] << std::endl;
	std::cout << "test size = " << test.size() << " and test capacity is "
	<< test.capacity() << std::endl << std::endl;

	std::cout << "Testing reallocation with a bigger vector" << std::endl;
	std::vector<int>		test3;
	test3.push_back(47);
	test3.push_back(3456);
	test.assign(test3.begin(), test3.end());
	std::cout << "Displaying the test vector after modifs" << std::endl;
	for (std::size_t i = 0; i< test.size(); i++)
		std::cout << "test[" << i << "] = " << test[i] << std::endl;
	std::cout << "test size = " << test.size() << " and test capacity is "
	<< test.capacity() << std::endl << std::endl;
	
	// ------------------------------------------------------------------------------------------------------//
	std::cout << "Testing this assign version : void assign (size_type n, const value_type& val);" << std::endl;
	
	std::cout << "assigning 42 times copies of values 42 to the test vector" << std::endl;
	test.assign(42, 42);
	std::cout << "Displaying the test vector after modifs" << std::endl;
	for (std::size_t i = 0; i< test.size(); i++)
		std::cout << "test[" << i << "] = " << test[i] << std::endl;
	std::cout << "test size = " << test.size() << " and test capacity is "
	<< test.capacity() << std::endl << std::endl;

	std::cout << "assigning 0 times copies of values 42 to the test vector" << std::endl;
	test.assign(42, 42);
	std::cout << "Displaying the test vector after modifs" << std::endl;
	for (std::size_t i = 0; i< test.size(); i++)
		std::cout << "test[" << i << "] = " << test[i] << std::endl;
	std::cout << "test size = " << test.size() << " and test capacity is "
	<< test.capacity() << std::endl << std::endl;

	separator(col);
	std::cout << std::endl << col.bdYellow() << "Assign tests over" << col.reset() << std::endl;
	separator(col);
}

/* testing the push back methods of vector */
static void	test_push_back(Colors &col) // to test
{
	separator(col);
	std::cout << col.bdYellow() << "Testing push_back method..." << col.reset()
	<< std::endl << std::endl;
	separator(col);
	
	std::vector<int>			test;
	
	std::cout << "Testing push back" << std::endl;
	
	std::cout << "test.empty = " << std::boolalpha << test.empty() << std::endl;
	std::cout << "test.size = " << test.size() << std::endl;
	std::cout << "test.capacity = " << test.capacity() << std::endl;
	std::cout << "Inserting 5 values one by one using push_back" << std::endl;
	test.push_back(5);
	test.push_back(76);
	test.push_back(-4567);
	test.push_back(0);
	test.push_back(-1);
	std::cout << "test.empty = " << std::boolalpha << test.empty() << std::endl;
	std::cout << "test.size = " << test.size() << std::endl;
	std::cout << "Printing the 5 values" << std::endl;
	for (std::size_t i = 0; i < test.size(); i++)
		std::cout << "index [" << i << "] = " << test[i] << std::endl;
	std::cout << "test.capacity = " << test.capacity() << std::endl;

	separator(col);
	std::cout << std::endl << col.bdYellow() << "Push_back tests over" << col.reset() << std::endl;
	separator(col);
}

/* pop_back test battery 
!!! if used on empty container it causes undefined behaviour !!! */
static void test_pop_back(Colors &col) // to test
{
	separator(col);
	std::cout << col.bdYellow() << "Testing pop_back method..." << col.reset()
	<< std::endl << std::endl;
	separator(col);

	std::vector<int>		test;

	std::cout << "Inserting 5 values to an empty vector" << std::endl;
	
	test.push_back(5);
	test.push_back(76);
	test.push_back(-4567);
	test.push_back(0);
	test.push_back(-1);

	/* printing vector content (without using pop back) */
	std::cout << "printing vector..." << std::endl;
	for (std::size_t i; i < test.size(); i++)
		std::cout << "Index [" << i << "] = " << test[i] << std::endl;
	std::cout << "size of vector is " << test.size() << std::endl;
	std::cout << "capacity of vector is : " << test.capacity() << std::endl;
	
	/* decrease the vector size one by one using pop back and checks at every deletion
	the relevant infos */
	
	// first deletion
	std::cout << "trying pop_back method" << std::endl;
	std::cout << "erase one value" << std::endl;
	test.pop_back();
	std::cout << "printing updated vector content" << std::endl;
	for (std::size_t i; i < test.size(); i++)
		std::cout << "Index [" << i << "] = " << test[i] << std::endl;
	std::cout << "size of the updated vector is : " << test.size() << std::endl;
	std::cout << "capacity of the updated vector is : " << test.capacity() << std::endl << std::endl;
	
	// second deletion
	std::cout << "erase one value" << std::endl;
	test.pop_back();
	std::cout << "printing updated vector content" << std::endl;
	for (std::size_t i; i < test.size(); i++)
		std::cout << "Index [" << i << "] = " << test[i] << std::endl;
	std::cout << "size of the updated vector is : " << test.size() << std::endl;
	std::cout << "capacity of the updated vector is : " << test.capacity() << std::endl << std::endl;

	// third deletion
	std::cout << "erase one value" << std::endl;
	test.pop_back();
	std::cout << "printing updated vector content" << std::endl;
	for (std::size_t i; i < test.size(); i++)
		std::cout << "Index [" << i << "] = " << test[i] << std::endl;
	std::cout << "size of the updated vector is : " << test.size() << std::endl;
	std::cout << "capacity of the updated vector is : " << test.capacity() << std::endl << std::endl;

	// fourth deletion
	std::cout << "erase one value" << std::endl;
	test.pop_back();
	std::cout << "printing updated vector content" << std::endl;
	for (std::size_t i; i < test.size(); i++)
		std::cout << "Index [" << i << "] = " << test[i] << std::endl;
	std::cout << "size of the updated vector is : " << test.size() << std::endl;
	std::cout << "capacity of the updated vector is : " << test.capacity() << std::endl << std::endl;

	// fifth deletion
	std::cout << "erase one value" << std::endl;
	test.pop_back();
	std::cout << "printing updated vector content" << std::endl;
	for (std::size_t i; i < test.size(); i++)
		std::cout << "Index [" << i << "] = " << test[i] << std::endl;
	std::cout << "size of the updated vector is : " << test.size() << std::endl;
	std::cout << "capacity of the updated vector is : " << test.capacity() << std::endl << std::endl;
	// PD : not trying a sixth deletion because vector is empty (would cause undefined behaviour)
	
	separator(col);
	std::cout << std::endl << col.bdYellow() << "pop_back tests over" << col.reset() << std::endl;
	separator(col);
}

/* test all the insert versions */
static void test_insertion(Colors &col) // to test
{
	separator(col);
	std::cout << col.bdYellow() << "Testing insertion..." << col.reset()
	<< std::endl << std::endl;
	separator(col);
	
	std::vector<int> 				test;

	std::cout << "Creating an empty int vector and fill it with 5 values..." << std::endl;

	test.push_back(5);
	test.push_back(76);
	test.push_back(-4567);
	test.push_back(0);
	test.push_back(-1);

	/* single element insertion */
	std::cout << "Testing this insert version : iterator insert(iterator position, const value_type &val);" << std::endl;

	std::vector<int>::iterator		it_pos = test.end();
	std::cout << "Insert a value (42) at the end" << std::endl;
	test.insert(it_pos, 42);
	std::cout << "Diplaying the entire vector..." << std::endl;
	for (std::size_t i; i < test.size(); i++)
		std::cout << "index [" << i << "] = " << test[i] << std::endl;
	std::cout << "checking changes in capacity and size" << std::endl;
	std::cout << "test size = " << test.size() << " and test capacity = " << test.capacity() << std::endl;

	std::vector<int>::iterator		it_pos = test.begin();
	std::cout << "Insert a value (21) at the beginning" << std::endl;
	test.insert(it_pos, 21);
	std::cout << "Diplaying the entire vector..." << std::endl;
	for (std::size_t i; i < test.size(); i++)
		std::cout << "index [" << i << "] = " << test[i] << std::endl;
	std::cout << "checking changes in capacity and size" << std::endl;
	std::cout << "test size = " << test.size() << " and test capacity = " << test.capacity() << std::endl << std::endl;
	
	/* fill the vector with one value */
	std::cout << "testing with this insert version : void insert(iterator position, size_type n, const value_type &val);"
	<< std::endl;

	std::vector<int>::iterator		it_pos = test.end();
	std::cout << "Inserting 5 values 72 at the end of the test vector" << std::endl;
	test.insert(it_pos, 5, 72);
	std::cout << "Diplaying the entire vector..." << std::endl;
	for (std::size_t i; i < test.size(); i++)
		std::cout << "index [" << i << "] = " << test[i] << std::endl;
	std::cout << "checking changes in capacity and size" << std::endl;
	std::cout << "test size = " << test.size() << " and test capacity = " << test.capacity() << std::endl << std::endl;
	
	std::vector<int>::iterator		it_pos = test.begin();
	std::cout << "Inserting 5 values 47 at the beginning of the test vector" << std::endl;
	test.insert(it_pos, 5 ,47);
	std::cout << "Diplaying the entire vector..." << std::endl;
	for (std::size_t i; i < test.size(); i++)
		std::cout << "index [" << i << "] = " << test[i] << std::endl;
	std::cout << "checking changes in capacity and size" << std::endl;
	std::cout << "test size = " << test.size() << " and test capacity = " << test.capacity() << std::endl << std::endl;
	
	/* insert a range of iterators */
	std::cout << "testing with this insert version : template <class InputIterator>" << std::endl
	<< "void insert(iterator position, InputIterator first, InputIterator last);" << std::endl;

	std::vector<int>			new_vect;

	new_vect.push_back(747);
	new_vect.push_back(666);
	new_vect.push_back(-7);

	std::vector<int>::iterator	it_beg = new_vect.begin();
	std::vector<int>::iterator	it_end = new_vect.end();

	std::cout << "Add a range of values at the beginning of test" << std::endl;
	test.insert(test.begin(), it_beg, it_end);
	std::cout << "Diplaying the entire vector..." << std::endl;
	for (std::size_t i; i < test.size(); i++)
		std::cout << "index [" << i << "] = " << test[i] << std::endl;
	std::cout << "checking changes in capacity and size" << std::endl;
	std::cout << "test size = " << test.size() << " and test capacity = " << test.capacity() << std::endl << std::endl;
	
	std::cout << "Add a range of values at the end of test " << std::endl;
	test.insert(test.end(), it_beg, it_end);
	std::cout << "Diplaying the entire vector..." << std::endl;
	for (std::size_t i; i < test.size(); i++)
		std::cout << "index [" << i << "] = " << test[i] << std::endl;
	std::cout << "checking changes in capacity and size" << std::endl;
	std::cout << "test size = " << test.size() << " and test capacity = " << test.capacity() << std::endl << std::endl;

	std::cout << "Add a range of values at the end of test" << std::endl;
	test.insert(test.begin() + 2, it_beg, it_end);
	std::cout << "Diplaying the entire vector..." << std::endl;
	for (std::size_t i; i < test.size(); i++)
		std::cout << "index [" << i << "] = " << test[i] << std::endl;
	std::cout << "checking changes in capacity and size" << std::endl;
	std::cout << "test size = " << test.size() << " and test capacity = " << test.capacity() << std::endl << std::endl;
	
	separator(col);
	std::cout << std::endl << col.bdYellow() << "insertion tests over" << col.reset() << std::endl;
	separator(col);
}

/* !!! an invalid position or range causes undefined behaviour !!! */
static void	test_erase(Colors &col) // to test
{
	separator(col);
	std::cout << col.bdYellow() << "Testing erase..." << col.reset()
	<< std::endl << std::endl;
	separator(col);

	std::cout << "Testing this erase version : iterator erase (iterator position);" << std::endl;
	
	std::vector<int>		test;

	test.push_back(5);
	test.push_back(76);
	test.push_back(-4567);
	test.push_back(0);
	test.push_back(-1);
	
	std::cout << "Creates a test vector and push_back 5 values..." << std::endl;

	std::cout << "Remove the first value using iterator begin" << std::endl;
	test.erase(test.begin());
	for (std::size_t i = 0; i < test.size(); i++)
		std::cout << "test[" << i << "] = " << test[i] << std::endl;
	std::cout << "test size = " << test.size() << " and test capacity is " << test.capacity()
	<< std::endl << std::endl;

	std::cout << "Remove the second value of test vector" << std::endl;
	test.erase(test.begin() + 1);
	for (std::size_t i = 0; i < test.size(); i++)
		std::cout << "test[" << i << "] = " << test[i] << std::endl;
	std::cout << "test size = " << test.size() << " and test capacity is " << test.capacity()
	<< std::endl << std::endl;

	std::cout << "Remove the last value of test vector" << std::endl;
	test.erase(test.end() - 1);
	for (std::size_t i = 0; i < test.size(); i++)
		std::cout << "test[" << i << "] = " << test[i] << std::endl;
	std::cout << "test size = " << test.size() << " and test capacity is " << test.capacity()
	<< std::endl << std::endl;
	
	std::cout << "Trying to use remove using the iterator test.end()" << std::endl;
	test.erase(test.end());
	for (std::size_t i = 0; i < test.size(); i++)
		std::cout << "test[" << i << "] = " << test[i] << std::endl;
	std::cout << "test size = " << test.size() << " and test capacity is " << test.capacity()
	<< std::endl << std::endl;

	// ---------------------------------------------------------------------------------------------------- //
	std::cout << "Testing this erase version : iterator erase (iterator first, iterator last);" << std::endl;

	std::cout << "push back some new value to the test vector" << std::endl;
	
	test.push_back(42);
	test.push_back(21);
	test.push_back(456);
	test.push_back(43);
	
	std::cout << "displaying the updated vector.." << std::endl;
	for (std::size_t i = 0; i < test.size(); i++)
		std::cout << "test[" << i << "] = " << test[i] << std::endl;
	std::cout << "test size = " << test.size() << " and test capacity is " << test.capacity()
	<< std::endl << std::endl;

	std::cout << "remove the first and second values" << std::endl;
	test.erase(test.begin(), test.begin() + 1);
	for (std::size_t i = 0; i < test.size(); i++)
		std::cout << "test[" << i << "] = " << test[i] << std::endl;
	std::cout << "test size = " << test.size() << " and test capacity is " << test.capacity()
	<< std::endl << std::endl;

	std::cout << "remove using the same iterator (i.e. begin)" << std::endl;
	test.erase(test.begin(), test.begin());
	for (std::size_t i = 0; i < test.size(); i++)
		std::cout << "test[" << i << "] = " << test[i] << std::endl;
	std::cout << "test size = " << test.size() << " and test capacity is " << test.capacity()
	<< std::endl << std::endl;
	
	std::cout << "Add some values to test" << std::endl;
	test.push_back(42);
	test.push_back(21);
	test.push_back(456);
	test.push_back(43);

	std::cout << "displaying the updated vector.." << std::endl;
	for (std::size_t i = 0; i < test.size(); i++)
		std::cout << "test[" << i << "] = " << test[i] << std::endl;
	std::cout << "test size = " << test.size() << " and test capacity is " << test.capacity()
	<< std::endl << std::endl;

	std::cout << "remove using the same iterator (i.e. end)" << std::endl;
	test.erase(test.end(), test.end());
	for (std::size_t i = 0; i < test.size(); i++)
		std::cout << "test[" << i << "] = " << test[i] << std::endl;
	std::cout << "test size = " << test.size() << " and test capacity is " << test.capacity()
	<< std::endl << std::endl;

	std::cout << "removing all values using both begin and end iterators" << std::endl;
	test.erase(test.begin(), test.end());
	for (std::size_t i = 0; i < test.size(); i++)
		std::cout << "test[" << i << "] = " << test[i] << std::endl;
	std::cout << "test size = " << test.size() << " and test capacity is " << test.capacity()
	<< std::endl << std::endl;

	separator(col);
	std::cout << std::endl << col.bdYellow() << "Erase tests over" << col.reset() << std::endl;
	separator(col);
}

/* VI - NON MEMBER OVERLOADING OPS */

static void	test_equivalency_ops(Colors &col) // wip
{
	separator(col);
	std::cout << col.bdYellow() << "Testing equivalency operators..." << col.reset()
	<< std::endl << std::endl;
	separator(col);

	std::vector<int>		comp1;

	comp1.push_back(42);
	comp1.push_back(17);

	std::vector<int>		comp2(comp1.begin(), comp1.end());

	std::cout << "compare two equivalent int vectors" << std::endl;
	std::cout << "(comp1 == comp2) = " << std::boolalpha << (comp1 == comp2) << std::endl;
	std::cout << "(comp1 != comp2) = " << std::boolalpha << (comp1 != comp2) << std::endl;
	
	std::cout << "compare two vectors with int vectors of different size" << std::endl;
	std::vector<int>		comp3;
	comp3.push_back(3);
	comp3.push_back(434343);
	std::vector<int>		comp4;
	comp4.push_back(2);
	comp4.push_back(3);
	comp4.push_back(434343);
	std::cout << "(comp3 == comp4) = " << std::boolalpha << (comp3 == comp4) << std::endl;
	std::cout << "(comp3 != comp4) = " << std::boolalpha << (comp3 != comp4) << std::endl;

	
	/* use lexicographical compare */
	std::cout << "testing < and > operators" << std::endl;
	std::cout << "testing with vectors of different size" << std::endl;

	std::vector<int>		comp5;
	comp5.push_back(8);
	comp5.push_back(9);
	comp5.push_back(10);
	std::vector<int>		comp6(comp5.begin(), comp5.end());
	comp5.push_back(0);
	
	std::cout << "(comp5 < comp6) = " << std::boolalpha << (comp5 < comp6) << std::endl;
	std::cout << "(comp5 > comp6) = " << std::boolalpha << (comp5 > comp6) << std::endl;
	
	std::cout << "compare two vectors of same size and with a diff of 1" << std::endl;
	comp5.pop_back()
	comp5.pop_back();
	comp5.push_back(8);

	std::cout << "(comp5 < comp6) = " << std::boolalpha << (comp5 < comp6) << std::endl;
	std::cout << "(comp5 > comp6) = " << std::boolalpha << (comp5 > comp6) << std::endl;
	
	/* uses also lexicographical compare */
	std::cout << "testing <= and >= operators" << std::endl;
	std::cout << "testing with precedent vectors" << std::endl;
	
	// to finish
	

	separator(col);
	std::cout << std::endl << col.bdYellow() << "End of equivalency operators tests" << col.reset() << std::endl;
	separator(col);
}

/* all the tests to assess the viability of ft::vector */
void	vector_verif_procedure(Colors &col) // wip
{
	separator(col);
	std::cout << col.bdYellow() << "Testing vector..." << col.reset()
	<< std::endl << std::endl;
	separator(col);
	
	// TO IMPLEMENT

	separator(col);
	std::cout << std::endl << col.bdYellow() << "End of vector tests" << col.reset() << std::endl;
	separator(col);
}
