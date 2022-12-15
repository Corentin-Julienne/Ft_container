/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tests.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:45:02 by cjulienn          #+#    #+#             */
/*   Updated: 2022/12/15 17:18:44 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/test_includes.hpp"

/* this file include all the map tests. Performance are not tested there but rather
in map_speedtest. Test covers (in that order): 
I)		Constructors

=> basic constructor
=> advanced constructors
=> copy constructor
=> operator=()

II)		Iterators

=> basic iterators
=> reverse iterators
=> const iterators (reverse and standard)

III)	Capacity

=> empty
=> size
=> max_size

IV)		Elements Access

=> operator[]
=> at

V)		Modifiers

=> insert
=> erase
=> swap 
=> clear

VI)		Observers

=> key_comp
=> value_comp
 
VII)	Operations

=> find
=> count
=> lower_bound
=> upper_bound
=> equal_range */

/* I - Constructors */

/* testing basic and advanced constructors + operator=() */
void	test_constructors(Colors &col) // to test
{
	separator(col);
	std::cout << col.bdYellow() << "Testing constructors..." << col.reset() << std::endl;
	separator(col);

	/* explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()); */

	std::map<int, std::string>			test;

	std::cout << "Trying to create an empty map..." << std::endl;
	std::cout << "test.size = " << test.size() << std::endl;

	/* template <class InputIterator>
	map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), 
	const allocator_type& alloc = allocator_type()); */

	std::cout << "Tring to create a map with a range of iterators" << std::endl;

	std::map<int, std::string>			other_map;

	other_map.insert(std::make_pair<int, std::string>(4, "this"));
	other_map.insert(std::make_pair<int, std::string>(-65, "is"));
	other_map.insert(std::make_pair<int, std::string>(47, "a"));
	other_map.insert(std::make_pair<int, std::string>(21, " "));
	other_map.insert(std::make_pair<int, std::string>(34, "test"));

	std::map<int, std::string>::iterator	it_beg = other_map.begin();
	std::map<int, std::string>::iterator	it_end = other_map.end();

	std::map<int, std::string>				test2(it_beg, it_end);
	std::cout << "displaying the map : " << std::endl;
	while (it_beg != it_end)
	{
		std::cout << "test2[" << (*it_beg).first << "] = " << (*it_beg).second << std::endl;
		it_beg++;
	}
	std::cout << "test2.size = " << test2.size() << std::endl;

	/* map (const map& x); */

	std::cout << "Testing the copy constructor of map..." << std::endl;
	std::cout << "Copying test2..." << std::endl;
	std::map<int, std::string>				test3(test2);
	std::cout << "displaying test3..." << std::endl;
	
	it_beg = test3.begin();
	it_end = test3.end();

	while (it_beg != it_end)
	{
		std::cout << "test3[" << (*it_beg).first << "] = " << (*it_beg).second << std::endl;
		it_beg++;
	}
	std::cout << "test3.size = " << test3.size() << std::endl;

	std::cout << "displaying test 2 to verify it is not a shallow copy" << std::endl;
	it_beg = test2.begin();
	it_end = test2.end();
	
	while (it_beg != it_end)
	{
		std::cout << "test2[" << (*it_beg).first << "] = " << (*it_beg).second << std::endl;
		it_beg++;
	}
	std::cout << "test2.size = " << test3.size() << std::endl;

	/* operator = */

	std::cout << "Trying overload operator = " << std::endl;
	std::map<int, std::string>			test4 = test3;

	std::cout << "displaying test4..." << std::endl;
	
	it_beg = test4.begin();
	it_end = test4.end();

	while (it_beg != it_end)
	{
		std::cout << "test4[" << (*it_beg).first << "] = " << (*it_beg).second << std::endl;
		it_beg++;
	}
	std::cout << "test4.size = " << test4.size() << std::endl;

	std::cout << "displaying test 3 to verify it is not a shallow copy" << std::endl;
	it_beg = test3.begin();
	it_end = test3.end();
	
	while (it_beg != it_end)
	{
		std::cout << "test3[" << (*it_beg).first << "] = " << (*it_beg).second << std::endl;
		it_beg++;
	}
	std::cout << "test3.size = " << test3.size() << std::endl;

	separator(col);
	std::cout << std::endl << col.bdYellow() << "constructor tests over" << col.reset() << std::endl;
	separator(col);
}

/* II - Iterators */

/* test standard iterators and iterator arithmetics */
void	test_iterator(Colors &col) // to test
{
	separator(col);
	std::cout << col.bdYellow() << "Testing iterators method..." << col.reset() << std::endl;
	separator(col);

	std::map<int, std::string>		test;

	std::cout << "Creating a map with ints as keys and std::string as values..." << std::endl;
	
	test.insert(std::make_pair<int, std::string>(4, "this"));
	test.insert(std::make_pair<int, std::string>(-65, "is"));
	test.insert(std::make_pair<int, std::string>(47, "a"));
	test.insert(std::make_pair<int, std::string>(21, " "));
	test.insert(std::make_pair<int, std::string>(34, "test"));

	std::map<int, std::string>::iterator	first = test.begin();
	std::map<int, std::string>::iterator	last = test.end();
	
	std::cout << "Check if we can print first and last (test.begin() and test.last() - 1)" << std::endl;
	std::cout << "first is " << (*first).first << " and last is " << (*(--last)).first << std::endl;
	
	std::cout << "Try to display all map keys with iterators..." << std::endl;
	while (first != last)
	{
		std::size_t	i = 0;
		
		std::cout << "test[" << i << "] = " << (*first).first << std::endl;
		i++;
		first++;
	}
	
	std::cout << "Testing iterator arithmetic..." << std::endl;

	std::cout << "Testing -- operator..." << std::endl;
	std::map<int, std::string>::iterator		op_minmin = test.end();
	op_minmin--;
	std::cout << "The iterator, one deferenced, should print the last key of the map..." << std::endl;
	std::cout << "The value printed is " << (*op_minmin).first << std::endl << std::endl;

	std::cout << "Testing ++ operator..."<< std::endl;
	std::map<int, std::string>::iterator		op_plusplus = test.begin();
	std::cout << "The iterator, once dereference, should print the second key of the map..." << std::endl;
	std::cout << "the value printed is " << (*(++op_plusplus)).first << std::endl << std::endl;		

	std::cout << "Testing --(int) operator" << std::endl;
	std::map<int, std::string>::iterator		op_minint = (++test.begin());
	std::cout << "The iterator, once dereferenced, should print the first key of the map"
	<< "then display the second key when printing a second time..." << std::endl;
	std::cout << "dereferncing once = " << (*(--op_minint)).first << " ,then dereferencing again = "
	<< (*op_minint).first << std::endl << std::endl;

	std::cout << "Testing ++(int) operator..."<< std::endl;
	std::map<int, std::string>::iterator		op_plusint = test.begin();
	std::cout << "The iterator, once dereferenced, should print the first value of vector"
	<< "then display the second value when printing a second time..." << std::endl;
	std::cout << "dereferncing once = " << (*(++op_plusint)).first << ", then dereferencing again = " 
	<< (*op_plusint).first << std::endl << std::endl;

	std::cout << "Testing a mix of iterator arithmetics..." << std::endl;
	std::map<int, std::string>::iterator		op_arit1 = test.begin();
	
	++op_arit1;
	--op_arit1;
	std::cout << "test.begin ++it, --it, it++ = " << (*(op_arit1++)).first << std::endl;
	
	std::cout << "Testing -> operator (* operator has already being tested a lot)" << std::endl;
	// TO IMPLEMENT

	std::cout << "Testing relationnal operators..." << std::endl;

	std::cout << "Testing == and !=" << std::endl;
	std::map<int, std::string>::iterator		it1 = test.begin();
	std::map<int, std::string>::iterator		it2 = test.begin();
	std::map<int, std::string>::iterator		it3 = test.end();

	std::cout << "it1 and it2 should be equals..." << std::endl;
	std::cout << "it1 == it2 = " << std::boolalpha << (it1 == it2) << std::endl;
	std::cout << "it1 != it2 = " << std::boolalpha << (it1 != it2) << std::endl;
	std::cout << "it1 and it3 should be different..."<< std::endl;
	std::cout << "it1 != it3 = " << std::boolalpha << (it1 != it3) << std::endl; 
	std::cout << "it1 == it3 = " << std::boolalpha << (it1 == it3) << std::endl << std::endl;

	separator(col);
	std::cout << std::endl << col.bdYellow() << "iterator tests over" << col.reset() << std::endl;
	separator(col);
}

/* test non const reverse_iterator and reverse_iterator arithmetics */
void	test_reverse_iterator(Colors &col) // to test
{
	separator(col);
	std::cout << col.bdYellow() << "Testing reverse_iterators method..." << col.reset() << std::endl;
	separator(col);

	std::map<int, std::string>		test;

	std::cout << "Creating a map with ints as keys and std::string as values..." << std::endl;
	
	test.insert(std::make_pair<int, std::string>(4, "this"));
	test.insert(std::make_pair<int, std::string>(-65, "is"));
	test.insert(std::make_pair<int, std::string>(47, "a"));
	test.insert(std::make_pair<int, std::string>(21, " "));
	test.insert(std::make_pair<int, std::string>(34, "test"));

	std::map<int, std::string>::reverse_iterator	first = test.rbegin();
	std::map<int, std::string>::reverse_iterator	last = test.rend();
	
	std::cout << "Check if we can print first and last (test.begin() and test.last() - 1)" << std::endl;
	std::cout << "first is " << (*first).first << " and last is " << (*(--last)).first << std::endl;

	std::cout << "Try to display all map keys with reverse_iterators..." << std::endl;
	while (first != last)
	{
		std::size_t	i = 0;
		
		std::cout << "test[" << i << "] = " << (*first).first << std::endl;
		i++;
		first++;
	}
	
	std::cout << "Testing reverse_iterator arithmetic..." << std::endl;

	std::cout << "Testing -- operator..." << std::endl;
	std::map<int, std::string>::reverse_iterator		op_minmin = test.rend();
	op_minmin--;
	std::cout << "The iterator, one deferenced, should print the last key of the map..." << std::endl;
	std::cout << "The value printed is " << (*op_minmin).first << std::endl << std::endl;

	std::cout << "Testing ++ operator..."<< std::endl;
	std::map<int, std::string>::reverse_iterator		op_plusplus = test.rbegin();
	std::cout << "The iterator, once dereference, should print the second key of the map..." << std::endl;
	std::cout << "the value printed is " << (*(++op_plusplus)).first << std::endl << std::endl;		

	std::cout << "Testing --(int) operator" << std::endl;
	std::map<int, std::string>::reverse_iterator		op_minint = (++test.rbegin());
	std::cout << "The iterator, once dereferenced, should print the first key of the map"
	<< "then display the second key when printing a second time..." << std::endl;
	std::cout << "dereferncing once = " << (*(--op_minint)).first << " ,then dereferencing again = "
	<< (*op_minint).first << std::endl << std::endl;

	std::cout << "Testing ++(int) operator..."<< std::endl;
	std::map<int, std::string>::reverse_iterator		op_plusint = test.rbegin();
	std::cout << "The iterator, once dereferenced, should print the first value of vector"
	<< "then display the second value when printing a second time..." << std::endl;
	std::cout << "dereferncing once = " << (*(++op_plusint)).first << ", then dereferencing again = " 
	<< (*op_plusint).first << std::endl << std::endl;

	std::cout << "Testing a mix of iterator arithmetics..." << std::endl;
	std::map<int, std::string>::reverse_iterator		op_arit1 = test.rbegin();
	
	++op_arit1;
	--op_arit1;
	std::cout << "test.begin ++it, --it, it++ = " << (*(op_arit1++)).first << std::endl;
	
	std::cout << "Testing -> operator (* operator has already being tested a lot)" << std::endl;
	// TO IMPLEMENT

	std::cout << "Testing relationnal operators..." << std::endl;

	std::cout << "Testing == and !=" << std::endl;
	std::map<int, std::string>::reverse_iterator		it1 = test.rbegin();
	std::map<int, std::string>::reverse_iterator		it2 = test.rbegin();
	std::map<int, std::string>::reverse_iterator		it3 = test.rend();

	std::cout << "it1 and it2 should be equals..." << std::endl;
	std::cout << "it1 == it2 = " << std::boolalpha << (it1 == it2) << std::endl;
	std::cout << "it1 != it2 = " << std::boolalpha << (it1 != it2) << std::endl;
	std::cout << "it1 and it3 should be different..."<< std::endl;
	std::cout << "it1 != it3 = " << std::boolalpha << (it1 != it3) << std::endl; 
	std::cout << "it1 == it3 = " << std::boolalpha << (it1 == it3) << std::endl << std::endl;

	separator(col);
	std::cout << std::endl << col.bdYellow() << "reverse_iterator tests over" << col.reset() << std::endl;
	separator(col);
}

/* III - Capacity */

/* test capacity methods : empty, size, max_size */
void	test_capacity(Colors &col) // to test
{
	separator(col);
	std::cout << col.bdYellow() << "Testing capacity methods..." << col.reset() << std::endl;
	separator(col);

	std::map<int, std::string>		test;
	std::cout << "Creating an empty map..." << std::endl;
	std::cout << "test.empty() = " << std::boolalpha << test.empty() << std::endl;
	std::cout << "test.size() =  " << test.size() << std::endl;

	std::cout << "adding some pairs to the map" << std::endl;

	test.insert(std::make_pair<int, std::string>(4, "this"));
	test.insert(std::make_pair<int, std::string>(-65, "is"));
	test.insert(std::make_pair<int, std::string>(47, "a"));
	test.insert(std::make_pair<int, std::string>(21, " "));
	test.insert(std::make_pair<int, std::string>(34, "test"));

	std::cout << "test.empty() = " << std::boolalpha << test.empty() << " and test.size() = "
	<< test.size() << std::endl;

	std::cout << "Testing max_size method..." << std::endl;
	std::cout << "test.max_size() = " << test.max_size() << std::endl;

	separator(col);
	std::cout << std::endl << col.bdYellow() << "Capacity methods tests over" << col.reset() << std::endl;
	separator(col);
}

/* IV - ELEMENT ACCESS */

/* test access methods : at and [] */
void	test_access(Colors &col) // to test
{
	separator(col);
	std::cout << col.bdYellow() << "Testing access methods..." << col.reset() << std::endl;
	separator(col);

	std::map<int, std::string>		test;

	std::cout << "Creating a map with ints as keys and std::string as values..." << std::endl;
	
	test.insert(std::make_pair<int, std::string>(4, "this"));
	test.insert(std::make_pair<int, std::string>(-65, "is"));
	test.insert(std::make_pair<int, std::string>(47, "a"));
	test.insert(std::make_pair<int, std::string>(21, " "));
	test.insert(std::make_pair<int, std::string>(34, "test"));

	std::cout << "A test map with 5 keys has been created [4, -65, 47, 21, 34]" << std::endl;
	std::cout << "Verifying the behaviour of operator []" << std::endl;
	std::cout << "test[4]   = " << test[4]   << std::endl;
	std::cout << "test[-65] = " << test[-65] << std::endl;
	std::cout << "test[47]  = " << test[47]  << std::endl;
	std::cout << "test[21]  = " << test[21]  << std::endl;
	std::cout << "test[34]  = " << test[34]  << std::endl << std::endl;

	std::cout << "trying to change a key that already exist, to see the behaviour" << std::endl;
	test[34] = "change str content";

	std::cout << "Testing with a non existing key" << std::endl;
	test[55] = "Testing";
	std::cout << "display new added pair key" << std::endl;
	std::cout << "test[55] = " << test[55] << std::endl << std::endl;
	
	std::cout << "Testing test.at with valid indexes" << std::endl;
	std::cout << "test.at(4)   = " << test.at(4)   << std::endl;
	std::cout << "test.at(-65) = " << test.at(-65) << std::endl;
	std::cout << "test.at(47)  = " << test.at(47)  << std::endl;
	std::cout << "test.at(21)  = " << test.at(21)  << std::endl;
	std::cout << "test.at(34)  = " << test.at(34)  << std::endl;
	std::cout << "test.at(55)  = " << test.at(55)  << std::endl;

	std::cout << "Testing test at with invalid key value" << std::endl;
		std::cout << test.at(666) << std::endl;

	separator(col);
	std::cout << std::endl << col.bdYellow() << "access methods tests over" << col.reset() << std::endl;
	separator(col);
}

/* V - MODIFIERS */

/* test all the versions of map::insert */
void	test_insert(Colors &col) // to test
{
	separator(col);
	std::cout << col.bdYellow() << "Testing insert method..." << col.reset() << std::endl;
	separator(col);

	std::map<int, std::string>		test;
	
	/* pair<iterator,bool> insert (const value_type& val); */
	std::cout << "Testing pair<iterator, bool> insert(const value_type &val) ;" << std::endl;

	std::cout << "adding a value using insert (4, \"one val\")" << std::endl;
	std::pair<std::map<int, std::string>::iterator, bool>		feedback;
	feedback = test.insert(std::make_pair<int, std::string>(4, "one val"));
	std::cout << "printing iterator position and check whether the insertion was successful" << std::endl;
	std::cout << "verif bool = " << std::boolalpha << feedback.second << ", *iterator = " << *feedback.first  // check this
	<< std::endl;
	std::cout << "test.size() = " << test.size() << "and key added = " << test[4] << std::endl << std::endl;

	std::cout << "adding another value..." << std::endl;
	std::cout << "adding a value using insert (65, \"2nd val\")" << std::endl;
	std::pair<std::map<int, std::string>::iterator, bool>		feedback2;
	feedback2 = test.insert(std::make_pair<int, std::string>(65, "2nd val"));
	std::cout << "printing iterator position and check whether the insertion was successful" << std::endl;
	std::cout << "verif bool = " << std::boolalpha << feedback2.second << ", *iterator = " << *feedback2.first  // check this
	<< std::endl;
	std::cout << "test.size() = " << test.size() << "and key added = " << test[65] << std::endl << std::endl;

	std::cout << "adding the smae value (should trigger exception msg)" << std::endl;
	std::cout << "adding a value using insert (65, \"2nd val\")" << std::endl;
	std::pair<std::map<int, std::string>::iterator, bool>		feedback3;
	feedback3 = test.insert(std::make_pair<int, std::string>(65, "2nd val"));
	std::cout << "printing iterator position and check whether the insertion was successful" << std::endl;
	std::cout << "verif bool = " << std::boolalpha << feedback2.second << ", *iterator = " << *feedback2.first  // check this
	<< std::endl;
	std::cout << "test.size() = " << test.size() << "and key added = " << test[65] << std::endl << std::endl;
	
	/* iterator insert (iterator position, const value_type& val); */
	std::cout << "Testing iterator insert (iterator position, const value_type& val) ;" << std::endl;
	
	std::cout << "adding an element at the end of the map" << std::endl;
	std::cout << "insert (test.end(), pair<int, std::string>(42, \"at the end\"))" << std::endl;
	std::map<int, std::string>::iterator	it_feedback;
	it_feedback = test.insert(test.end(), std::make_pair<int, std::string>(42, "at the end"));
	std::cout << "test.size() = " << test.size() << " and *iterator = " << (*it_feedback).first << std::endl;
	
	std::cout << "adding an element at the beginning of the map" << std::endl;
	std::cout << "insert (test.begin(), pair<int, std::string>(72, \"at the beginning\"))" << std::endl;
	std::map<int, std::string>::iterator	it_feedback2;
	it_feedback2 = test.insert(test.begin(), std::make_pair<int, std::string>(72, "at the beginning"));
	std::cout << "test.size() = " << test.size() << " and *iterator = " << (*it_feedback2).first << std::endl;
	
	std::cout << "add an already existing key" << std::endl;
	std::cout << "insert (test.begin(), pair<int, std::string>(72, \"at the beginning\"))" << std::endl;
	std::map<int, std::string>::iterator	it_feedback3;
	it_feedback3 = test.insert(test.begin(), std::make_pair<int, std::string>(72, "at the beginning"));
	std::cout << "test.size() = " << test.size() << " and *iterator = " << (*it_feedback2).first << std::endl;

	/* template <class InputIterator>  void insert (InputIterator first, InputIterator last); */
	std::cout << "Testing template <class InputIterator>  void insert (InputIterator first, InputIterator last);" 
	<< std::endl;

	std::cout << "add a range of pairs from another map..." << std::endl;
	std::map<int, std::string>			other_map;
	other_map.insert(std::make_pair<int, std::string>(767, "new map 1"));
	other_map.insert(std::make_pair<int, std::string>(999, "new_map 2"));
	test.insert(other_map.begin(), other_map.end());
	std::cout << "test.size() = " << test.size() << std::endl;

	std::cout << "displaying the entire map" << std::endl;
	std::map<int, std::string>::iterator		it_display = test.begin();
	std::map<int, std::string>::iterator		it_ending = test.end();
	while (it_display != it_ending)
	{
		std::cout << "test[" << (*it_display).first << "] = " << (*it_display).second << std::endl;
		it_display++;
	}

	separator(col);
	std::cout << std::endl << col.bdYellow() << "insert method tests over" << col.reset() << std::endl;
	separator(col);
}

/* test all the erase versions of map::insert */
void	test_erase(Colors &col) // to test
{
	separator(col);
	std::cout << col.bdYellow() << "Testing erase method..." << col.reset() << std::endl;
	separator(col);

	std::cout << "creating a map with 8 pairs inside..." << std::endl;
	std::map<int, std::string>		test;

	test.insert(std::make_pair<int, std::string>(4, "this"));
	test.insert(std::make_pair<int, std::string>(-65, "is"));
	test.insert(std::make_pair<int, std::string>(47, "a"));
	test.insert(std::make_pair<int, std::string>(21, " "));
	test.insert(std::make_pair<int, std::string>(34, "test"));
	test.insert(std::make_pair<int, std::string>(35, "with"));
	test.insert(std::make_pair<int, std::string>(36, "some"));
	test.insert(std::make_pair<int, std::string>(37, "values"));

	/* void erase (iterator position); */
	std::cout << "testing with this version : void erase (iterator position); " << std::endl << std::endl;
	
	std::cout << "erase the first value" << std::endl;
	test.erase(test.begin());
	std::cout << "diplaying the updated map" << std::endl;
	std::map<int, std::string>::iterator	it = test.begin();
	while (it != test.end())
	{
		std::cout << (*it).first << " : " << (*it).second << std::endl;
		it++;
	}
	std::cout << "map size = " << test.size() << std::endl;
	std::cout << std::endl;
	
	std::cout << "erase the last value" << std::endl;
	test.erase(test.end());
	std::cout << "displaying the updated map" << std::endl;
	it = test.begin();
	while (it != test.end())
	{
		std::cout << (*it).first << " : " << (*it).second << std::endl;
		it++;
	}
	std::cout << "map size = " << test.size() << std::endl;
	std::cout << std::endl;
	
	/* size_type erase (const key_type& k); */
	std::cout << "testing with this version : size_type erase (const key_type& k);" << std::endl << std::endl;
	
	std::cout << "erase the pair identificated by the 35" << std::endl;
	test.erase(35);
	std::cout << "Displaying the updated map" << std::endl;
	it = test.begin();
	while (it != test.end())
	{
		std::cout << (*it).first << " : " << (*it).second << std::endl;
		it++;
	}
	std::cout << "map size = " << test.size() << std::endl;
	std::cout << std::endl;
	
	std::cout << "trying to erase a non existant value..." << std::endl;
	test.erase(6666666);
	std::cout << "Displaying the updated map" << std::endl;
	it = test.begin();
	while (it != test.end())
	{
		std::cout << (*it).first << " : " << (*it).second << std::endl;
		it++;
	}
	std::cout << "map size = " << test.size() << std::endl;
	std::cout << std::endl;

	/* void erase (iterator first, iterator last); */
	std::cout << "testing with this version : void erase (iterator first, iterator last);" << std::endl << std::endl;

	std::cout << "erasing the all map content" << std::endl;
	test.erase(test.begin(), test.end());
	std::cout << "map size = " << test.size() << std::endl;

	separator(col);
	std::cout << std::endl << col.bdYellow() << "erase method tests over" << col.reset() << std::endl;
	separator(col);
}

/* test the swap version of map and clear method */
void	test_swap_clear(Colors &col) // to test
{
	separator(col);
	std::cout << col.bdYellow() << "Testing swap and clear methods..." << col.reset() << std::endl;
	separator(col);

	std::cout << "creating two maps with some pairs each" << std::endl;
	std::map<int, std::string>			test1;
	std::map<int, std::string>			test2;

	test1.insert(std::make_pair<int, std::string>(4, "this"));
	test1.insert(std::make_pair<int, std::string>(-65, "is"));
	test1.insert(std::make_pair<int, std::string>(47, "a"));
	test1.insert(std::make_pair<int, std::string>(21, " "));
	test1.insert(std::make_pair<int, std::string>(34, "test"));

	std::cout << "displaying the first map" << std::endl;
	std::map<int, std::string>::iterator		it1 = test1.begin();
	while (it1 != test1.end())
	{
		std::cout << "test1[" << (*it1).first << "] = " << (*it1).second << std::endl;
		it1++;
	}
	std::cout << "test1.size = " << test1.size() << std::endl;

	test2.insert(std::make_pair<int, std::string>(34, "test"));
	test2.insert(std::make_pair<int, std::string>(35, "with"));
	test2.insert(std::make_pair<int, std::string>(36, "some"));
	test2.insert(std::make_pair<int, std::string>(37, "values"));

	std::cout << "displaying the second map" << std::endl;
	std::map<int, std::string>::iterator		it2 = test2.begin();
	while (it2 != test2.end())
	{
		std::cout << "test2[" << (*it2).first << "] = " << (*it2).second << std::endl;
		it2++;
	}
	
	std::cout << std::endl << "swapping the maps" << std::endl << std::endl;
	test1.swap(test2);
	
	std::cout << "diplaying test1 (should output like test2)" << std::endl;
	it1 = test1.begin();
	while (it1 != test1.end())
	{
		std::cout << "test1[" << (*it1).first << "] = " << (*it1).second << std::endl;
		it1++;
	}
	std::cout << "test1.size = " << test1.size() << std::endl;

	std::cout << "displaying the second map (should output like the first)" << std::endl;
	it2 = test2.begin();
	while (it2 != test2.end())
	{
		std::cout << "test2[" << (*it2).first << "] = " << (*it2).second << std::endl;
		it2++;
	}
	std::cout << "test2.size = " << test2.size() << std::endl;

	std::cout << "Testing the clear function..." << std::endl << std::endl;

	test1.clear();
	std::cout << "test1.size = " << test1.size() << std::endl;
	test2.clear();
	std::cout << "test2.size = " << test2.size() << std::endl;

	std::cout << "trying to clear an already empty vector..." << std::endl;
	test1.clear();
	std::cout << "test1.size = " << test1.size() << std::endl;

	separator(col);
	std::cout << std::endl << col.bdYellow() << "swap and clear method tests over" << col.reset() << std::endl;
	separator(col);
}

/* VI - OBSERVERS */

/* assess key_comp and value_comp methods */
void	test_comparators(Colors &col)
{
	separator(col);
	std::cout << col.bdYellow() << "Testing key_comp and value_comp..." << col.reset() << std::endl;
	separator(col);

	// TO IMPLEMENT

	separator(col);
	std::cout << std::endl << col.bdYellow() << "key_comp and value_comp tests over" 
	<< col.reset() << std::endl;
	separator(col);
}

/* VII - OPERATIONS */

/* test find and count method */
void	test_find_count(Colors &col) // to test
{
	separator(col);
	std::cout << col.bdYellow() << "Testing find and count..." << col.reset() << std::endl;
	separator(col);

	std::cout << "Create a map to test on it" << std::endl;
	std::map<int, std::string>							test;

	test.insert(std::make_pair<int, std::string>(4, "this"));
	test.insert(std::make_pair<int, std::string>(-65, "is"));
	test.insert(std::make_pair<int, std::string>(47, "a"));
	test.insert(std::make_pair<int, std::string>(21, " "));
	test.insert(std::make_pair<int, std::string>(34, "test"));

	std::cout << "Testing find method" << std::endl << std::endl;
	/* return an iterator to the corresponding key if key exists. Otherwise, return end() */
	std::map<int, std::string>::iterator		it;
	
	/* case 1 : key exists */
	std::cout << "trying with existing key" << std::endl;

	it = test.find(47);
	if (it != test.end())
		std::cout << "test.find(47) = " << (*it).first << std::endl;
	else
		std::cout << "end reached" << std::endl;

	/*  case 2 : key does not exist */
	std::cout << std::endl << "trying with non existing key" << std::endl;
	
	it = test.find(999999);
	if (it != test.end())
		std::cout << "test.find(999999) = " << (*it).first << std::endl;
	else
		std::cout << "end reached" << std::endl;
	
	std::cout << std::endl << "Testing count method" << std::endl << std::endl;
	/* returns the number of times a key is present. As a map cannot hold several keys with the same value,
	the result is either 0 (key is not present) or 1 (key is present) */
	
	/* case 1 : key is present */
	std::cout << "trying when key exists" << std::endl;
	std::cout << "test.count(47) = " << test.count(47)  << std::endl << std::endl;

	/* case 2 : key is not present */
	std::cout << "trying when key does not exist" << std::endl;
	std::cout << "test.count(999999) = " << test.count(999999) << std::endl;
	std::cout << "test.count(-999999) = " << test.count(-999999) << std::endl;

	separator(col);
	std::cout << std::endl << col.bdYellow() << "find and count tests over" 
	<< col.reset() << std::endl;
	separator(col);
}

/* test upper_bound and lower_bound, equal range */
void	test_bounds(Colors &col) // to test
{
	separator(col);
	std::cout << col.bdYellow() << "Testing upper_bound and lower_bound..." << col.reset() << std::endl;
	separator(col);

	std::cout << "Create a map to test on it" << std::endl;
	std::map<int, std::string>					test;

	test.insert(std::make_pair<int, std::string>(4, "this"));
	test.insert(std::make_pair<int, std::string>(-65, "is"));
	test.insert(std::make_pair<int, std::string>(47, "a"));
	test.insert(std::make_pair<int, std::string>(21, " "));
	test.insert(std::make_pair<int, std::string>(34, "test"));

	std::map<int, std::string>::iterator		feedback;

	std::cout << "testing lower_bound method" << std::endl << std::endl;
	/* will return the iterator pointing to the pair containing the key passed as parameter,
	OR if the parameter does not match any key, then it will display the next key. If the next key does 
	not exist, it will returns an iterator equal to end() */
	
	/* case 1 : key match parameter */
	std::cout << "key match parameter" << std::endl;
	feedback = test.lower_bound(21);
	if (feedback != test.end())
		std::cout << "test.lower_bound(21) = " << (*feedback).first << std::endl;
	else
		std::cout << "end reached" << std::endl;

	/* case 2 : key does not match parameter and next key exists */
	std::cout << "key does not match parameter and next key exists" << std::endl;
	feedback = test.lower_bound(45);
	if (feedback != test.end())
		std::cout << "test.lower_bound(45) = " << (*feedback).first << std::endl;
	else
		std::cout << "end reached" << std::endl;

	/* case 3 : key does not match parameter and next key does not exists */
	std::cout << "key does not match parameter and next key does not exists" << std::endl;
	feedback = test.lower_bound(666);
	if (feedback != test.end())
		std::cout << "test.lower_bound(666) = " << (*feedback).first << std::endl;
	else
		std::cout << "end reached" << std::endl;

	std::cout << "testing upper_bound method" << std::endl << std::endl;
	/* will return the iterator pointing to the pair after the one containing the key passed as parameter,
	OR if the parameter does not match any key, then it will display the next key. If the next key does 
	not exist, it will returns an iterator equal to end() */

	/* case 1 : key match parameter and next key exists */
	std::cout << "key match parameter and next key exists" << std::endl;
	feedback = test.upper_bound(21);
	if (feedback != test.end())
		std::cout << "test.upper_bound(21) = " << (*feedback).first << std::endl;
	else
		std::cout << "end reached" << std::endl;

	/* case 2 : key match parameter and next key does not exists */
	std::cout << "key match parameter and next key does not exists" << std::endl;
	feedback = test.upper_bound(47);
	if (feedback != test.end())
		std::cout << "test.upper_bound(47) = " << (*feedback).first << std::endl;
	else
		std::cout << "end reached" << std::endl;

	/* case 3 : key does not match parameter and next key does exist */
	std::cout << "key does not match parameter and next key does exist" << std::endl;
	feedback = test.upper_bound(46);
	if (feedback != test.end())
		std::cout << "test.upper_bound(46) = " << (*feedback).first << std::endl;
	else
		std::cout << "end reached" << std::endl;

	/* case 4 : key does not match parameter and next key does not exists */
	std::cout << "key does not match parameter and next key does not exists" << std::endl;
	feedback = test.upper_bound(666);
	if (feedback != test.end())
		std::cout << "test.upper_bound(666) = " << (*feedback).first << std::endl;
	else
		std::cout << "end reached" << std::endl;

	std::cout << std::endl << "Testing equal_range" << std::endl;
	/* equal range return a pair of two iterators : the first equal to lower_bound
	and the second equal to upper_bound */
	
	std::cout << "equal range should output like lower_bound and upper_bound" << std::endl;
	int key;
	
	/* case 1 */
	key = 21;
	std::cout << "equal range : lower_bound" << std::endl;
	if (test.equal_range(key).first != test.end())
		std::cout << (*(test.equal_range(key).first)).first << std::endl;
	else
		std::cout << "end reached" << std::endl;

	std::cout << "equal range : upper_bound" <<std::endl;
	if (test.equal_range(key).second != test.end())
		std::cout << (*(test.equal_range(key).second)).first << std::endl;
	else
		std::cout << "end reached" << std::endl;
	
	/* case 2 */
	key = 666;
	std::cout << "equal range : lower_bound" << std::endl;
	if (test.equal_range(key).first != test.end())
		std::cout << (*(test.equal_range(key).first)).first << std::endl;
	else
		std::cout << "end reached" << std::endl;

	std::cout << "equal range : upper_bound" <<std::endl;
	if (test.equal_range(key).second != test.end())
		std::cout << (*(test.equal_range(key).second)).first << std::endl;
	else
		std::cout << "end reached" << std::endl;

	/* case 3 */
	key = 45;
	std::cout << "equal range : lower_bound" << std::endl;
	if (test.equal_range(key).first != test.end())
		std::cout << (*(test.equal_range(key).first)).first << std::endl;
	else
		std::cout << "end reached" << std::endl;

	std::cout << "equal range : upper_bound" <<std::endl;
	if (test.equal_range(key).second != test.end())
		std::cout << (*(test.equal_range(key).second)).first << std::endl;
	else
		std::cout << "end reached" << std::endl;

	/* case 4 */
	key = 46;
	std::cout << "equal range : lower_bound" << std::endl;
	if (test.equal_range(key).first != test.end())
		std::cout << (*(test.equal_range(key).first)).first << std::endl;
	else
		std::cout << "end reached" << std::endl;

	std::cout << "equal range : upper_bound" <<std::endl;
	if (test.equal_range(key).second != test.end())
		std::cout << (*(test.equal_range(key).second)).first << std::endl;
	else
		std::cout << "end reached" << std::endl;

	/* case 5 */
	key = 47;
	std::cout << "equal range : lower_bound" << std::endl;
	if (test.equal_range(key).first != test.end())
		std::cout << (*(test.equal_range(key).first)).first << std::endl;
	else
		std::cout << "end reached" << std::endl;

	std::cout << "equal range : upper_bound" <<std::endl;
	if (test.equal_range(key).second != test.end())
		std::cout << (*(test.equal_range(key).second)).first << std::endl;
	else
		std::cout << "end reached" << std::endl;

	separator(col);
	std::cout << std::endl << col.bdYellow() << "upper and lower bound and equal range tests over" 
	<< col.reset() << std::endl;
	separator(col);
}

/* will verif all map features and function */
void	map_verif_procedure(Colors &col)
{	
	separator(col);
	std::cout << col.bdYellow() << "Testing map..." << col.reset() << std::endl;
	separator(col);

	test_constructors(col);
	test_iterator(col);
	test_reverse_iterator(col);
	// add const iterators
	test_capacity(col);
	test_access(col);
	test_insert(col);
	test_erase(col);
	test_swap_clear(col);
	test_comparators(col);
	test_find_count(col);
	test_bounds(col);

	separator(col);
	std::cout << std::endl << col.bdYellow() << "Map tests over" << col.reset() << std::endl;
	separator(col);
}
