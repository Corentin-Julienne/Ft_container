/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tests.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:45:02 by cjulienn          #+#    #+#             */
/*   Updated: 2022/12/07 16:38:46 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/test_includes.hpp"

/* test the swap version of map and clear method */
void	test_swap_clear(Colors &col)
{
	separator(col);
	std::cout << col.bdYellow() << "Testing swap and clear methods..." << col.reset()
	<< std::endl << std::endl;
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
		std::cout << << std::endl;
		it1++;
	}	

	test2.insert(std::make_pair<int, std::string>(34, "test"));
	test2.insert(std::make_pair<int, std::string>(35, "with"));
	test2.insert(std::make_pair<int, std::string>(36, "some"));
	test2.insert(std::make_pair<int, std::string>(37, "values"));

	std::cout << "displaying the second map" << std::endl;
	std::map<int, std::string>::iterator		it2 = test2.begin();


	separator(col);
	std::cout << std::endl << col.bdYellow() << "swap and clear method tests over" << col.reset() << std::endl;
	separator(col);
}

/* test all the erase versions of map::insert */
void	test_erase(Colors &col) // to test
{
	separator(col);
	std::cout << col.bdYellow() << "Testing erase method..." << col.reset()
	<< std::endl << std::endl;
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

/* test all the versions of map::insert */
void	test_insert(Colors &col) // to test
{
	separator(col);
	std::cout << col.bdYellow() << "Testing insert method..." << col.reset()
	<< std::endl << std::endl;
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

/* test capacity methods : empty, size, max_size */
void	test_capacity(Colors &col) // to test
{
	separator(col);
	std::cout << col.bdYellow() << "Testing capacity methods..." << col.reset()
	<< std::endl << std::endl;
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

/* test access methods : at and [] */
void	test_access(Colors &col) // to test
{
	separator(col);
	std::cout << col.bdYellow() << "Testing access methods..." << col.reset()
	<< std::endl << std::endl;
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

/* test non const reverse_iterator and reverse_iterator arithmetics */
void	test_reverse_iterator(Colors &col) // to test
{
	separator(col);
	std::cout << col.bdYellow() << "Testing reverse_iterators method..." << col.reset()
	<< std::endl << std::endl;
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

/* test standard iterators and iterator arithmetics */
void	test_iterator(Colors &col) // to test
{
	separator(col);
	std::cout << col.bdYellow() << "Testing iterators method..." << col.reset()
	<< std::endl << std::endl;
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

/* will verif all map features and function */
void	map_verif_procedure(Colors &col)
{	
	/* We will check all the methods of ft and stl map in order to check if they
	behave the same way. We will also check iterators and of all type and their 
	behaviour */	
	std::map<int, std::string>		stl_map;
	ft::map<int, std::string>		ft_map;

	std::cout << "Basic constructors activated" << std::endl; // checking basic constructors
	std::cout << "Checking the size method is functionnal and returns 0"<< std::endl;
	std::cout << "for the STL map the return value of size is " << stl_map.size() << std::endl;
	std::cout << "for the FT map the return value of size is " << ft_map.size() << std::endl;
	separator(col);
	std::cout << "checking the max_size method" << std::endl; // checking max_size
	std::cout << "for the STL map the return value of max_size is " << stl_map.max_size() << std::endl;
	std::cout << "for the FT map the return value of max_size is " << ft_map.max_size() << std::endl;
	separator(col);
	std::cout << "checking for the empty method when there is no pair inside map" << std::endl; // checking empty when empty
	std::cout << "P.D : should be equal to 0" << std::endl;
	std::cout << "for the STL map the return value of empty is " << stl_map.empty() << std::endl;
	std::cout << "for the FT map the return value of empty is " << ft_map.empty() << std::endl;
	separator(col);
	/* testing insertion */
	std::cout << "Testing the Insertion Method" << std::endl;
	// testing with single value insertion
	std::cout << "Testing insertion with a single value" << std::endl;

	std::string													example("truc");
	std::pair<std::map<int, std::string>::iterator, bool>		insert_res;			
	
	insert_res = stl_map.insert(std::make_pair<int, std::string>(4, example));
	
	std::cout << "Testing the return value of STL map function insert (with a single value)" << std::endl;
	std::cout << "key is " << insert_res.first << "and value is " << insert_res.second << std::endl; // to correct
	// check wether the size has been correctly incremented
	std::cout << "the new size of the map is " << stl_map.size() << " and should be equal to 1 (single value added)" 
	<< std::endl; // WIP


	separator(col);
	/* testing insert with a range of iterators */
	std::cout << "Testing insertion with a range of iterators" << std::endl;
	// STL MAP
	std::cout << "create a STL map and insert 5 pairs" << std::endl;
	std::map<int, std::string>					stl_full_map;
	stl_full_map.insert(std::make_pair<int, std::string>(65, "alpha"));
	stl_full_map.insert(std::make_pair<int, std::string>(84, "bravo"));
	stl_full_map.insert(std::make_pair<int, std::string>(4, "charlie"));
	stl_full_map.insert(std::make_pair<int, std::string>(844, "delta"));
	stl_full_map.insert(std::make_pair<int, std::string>(1084, "echo"));
	std::cout << "then add two iterators first and last" << std::endl;
	std::map<int, std::string>::iterator		stl_first = stl_full_map.begin();
	std::map<int, std::string>::iterator		stl_last = stl_full_map.end();
	std::cout << "insert this range of iterators into the empty STL map" << std::endl;
	stl_map.insert(stl_first, stl_last);
	// => print the stl_map content there
	separator(col);
	// FT MAP
	std::cout << "create a FT map and insert the same 5 pairs" << std::endl;
	ft::map<int, std::string>					ft_full_map;
	ft_full_map.insert(ft::make_pair<int, std::string>(65, "alpha"));
	ft_full_map.insert(ft::make_pair<int, std::string>(84, "bravo"));
	ft_full_map.insert(ft::make_pair<int, std::string>(4, "charlie"));
	ft_full_map.insert(ft::make_pair<int, std::string>(844, "delta"));
	ft_full_map.insert(ft::make_pair<int, std::string>(1084, "echo"));
	std::cout << "then add two iterators first and last" << std::endl;
	ft::map<int, std::string>::iterator		ft_first = ft_full_map.begin();
	ft::map<int, std::string>::iterator		ft_last = ft_full_map.end();
	std::cout << "insert this range of iterators into the empty FT map" << std::endl;
	ft_map.insert(ft_first, ft_last);
	// => verify the second insert function there
	separator(col);

	/* verifiying erase function */
	std::cout << "Verifying erase function" << std::endl;
	std::cout << "Verifying erase with a single value" << std::endl;
	// STL MAP
	std::cout << "Retrieving the first and last values of STL map" << std::endl;
	stl_map.erase(stl_first);
	stl_map.erase(stl_last);
	// => display new map values
	// FT MAP
	std::cout << "Retrieving the first and last values of FT map" << std::endl;
	ft_map.erase(ft_first);
	ft_map.erase(ft_last);
	// => display new map values
	separator(col);
	std::cout << "Trying the method clear to destroy all the data inside the maps" << std::endl;
	stl_map.clear();
	ft_map.clear();
	std::cout << "Verifying size and content off the maps (should be 0 and print nothing)" << std::endl;
	std::cout << "size of STL map is " << stl_map.size() << " and it the content is : "  << std::endl;
	// => print content there (stl map)
	std::cout << "size of FT map is " << ft_map.size() << " and it the content is : " << std::endl;
	// => print content there (ft map)
	separator(col);
	std::cout << "Verifying erase with a range of iterators" << std::endl;
	// STL MAP
	std::cout << "Starting to populate STL and FT maps with a range of iterators using insert..." << std::endl;
	stl_map.insert(stl_first, stl_last);
	ft_map.insert(ft_first, ft_last);
	// FT MAP
	std::cout << "Erasing everything except first and last value" << std::endl;
	
	std::cout << "Printing STL map after changes : " << std::endl;
	// => print stl_map
	std::cout << "Printing FT map after changes : " << std::endl;
	// => print ft_map
	separator(col);
	std::cout << "Verifying erase with a const ref to key" << std::endl;
	std::cout << "eliminate the pair with key 4 (int)" << std::endl;
	std::size_t		stl_res = stl_map.erase(4);
	std::size_t		ft_res = ft_map.erase(4);
	std::cout << "The STL map erase function suppressed " << stl_res << " elements" << std::endl;
	std::cout << "Printing the STL map with changes : " << std::endl;
	// => print stl map content
	std::cout << "The FT map erase function suppressed " << ft_res << " elements" << std::endl;
	std::cout << "Printing the FT map with changes : " << std::endl;
	// => print ft map content
	separator(col);
	std::cout << "Trying to erase a non-existing key, that time" << std::endl;
	stl_map.erase(666); // see if error msg
	ft_map.erase(666); // see if error msg
	
	separator(col);
	/* there we check the behaviour of iterators of the stl map vs ft map
	the goal is to check wether the functions related to iterators are giving the same values.
	We also check that the behaviour of all classes of iterators (including standards, reverse,
	and their const versions do not behave differently)*/
	std::cout << "Testing map iterators and their behaviour" << std::endl;
	






	std::cout << "End of iterator verification procedure" << std::endl;
	separator(col);
	
	// testing some iterators
	
	
	// testing insert functions
}
