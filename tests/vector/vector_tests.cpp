/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_tests.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:42:21 by cjulienn          #+#    #+#             */
/*   Updated: 2022/12/02 16:54:32 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/test_includes.hpp"

/* tests all constructors and operator = */
static void	test_constructors(Colors &col)
{
	// TO IMPLEMENT
}

/* test all the insert versions */
static void test_insertion(Colors &col) // WIP
{
	std::vector<int> 				test;
	std::vector<int>::iterator		it = test.begin();

	std::cout << "Creating an empty int vector..." << std::endl;
	std::cout << "Insert a single value" << std::endl;

	std::cout << "Insert int of value 4 in vector..." << std::endl;
	test.insert(it, 4);
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

/* test the capacity methods of vector. Contains : 
=> size
=> max_size
=> resize
=> capacity
=> empty
=> reserve */
static void	test_capacity_methods(Colors &col)
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
	std::cout << "test.max_size = " << test.max_size() << std::endl;

	/* RESIZE */
	std::cout << "Testing resize method" << std::endl;
	

	

	/* CAPACITY */
	std::cout << "Testing capacity method..." << std::endl;
	std::cout << "test.capacity = " << test.capacity() << std::endl;

	/* insert some values to check the changes in capacity */
	std::cout << "Checking changes in capacity related to changes in size..." << std::endl; // to improve
	test.push_back("Check"); 
	test.push_back("changes ");
	test.push_back("in");
	test.push_back("vector");
	test.push_back("capcity");
	
	std::cout << "test.capacity = " << test.capacity() << std::endl;

	separator(col);
	std::cout << std::endl << col.bdYellow() << "capacity tests over" << col.reset() << std::endl;
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

/* testing the method assign of vector */
static void	test_assign(Colors &col)
{
	separator(col);
	std::cout << col.bdYellow() << "Testing assign method..." << col.reset()
	<< std::endl << std::endl;
	separator(col);

	std::vector<int>		test;

	test.push_back(5);
	test.push_back(76);
	test.push_back(-4567);
	test.push_back(0);
	test.push_back(-1);
	
	std::cout << "Creates a vector and push back 5 values..." << std::endl;
	std::cout << "vector size = " << test.size() << std::endl;
	std::cout << "vector capacity = " << test.capacity() << std::endl;
	for (std::size_t i; i < test.size(); i++)
		std::cout << "index [" << i << "] = " << test[i] << std::endl;
	
	/* assign with single value, without iterators */
	std::cout << "replace content with assign" << std::endl;
	test.assign(6, 42);
	std::cout << "vector size = " << test.size() << std::endl;
	std::cout << "vector capacity = " << test.capacity() << std::endl;
	for (std::size_t i; i < test.size(); i++)
		std::cout << "index [" << i << "] = " << test[i] << std::endl;
	
	/* assign with iterators */
	std::vector<int>					other;
	std::vector<int>::iterator			itb = other.begin();
	std::vector<int>::iterator			ite = other.end();

	other.push_back(21);
	other.push_back(42);
	other.push_back(72);

	std::cout << "replace content with a range of iterators" << std::endl;
	test.assign(itb, ite); // should work, but test
	
	
	
	separator(col);
	std::cout << std::endl << col.bdYellow() << "Assign tests over" << col.reset() << std::endl;
	separator(col);
}






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

	separator(col);
	//---------------------------------------------------------------------------------------//
	std::cout << col.bdYellow() << "-----------------------------" << col.reset() << std::endl;
	std::cout << col.bdYellow() << "End of verification procedure" << col.reset() << std::endl;
	std::cout << col.bdYellow() << "-----------------------------" << col.reset() << std::endl;
}
