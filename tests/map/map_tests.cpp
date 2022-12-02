/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tests.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:45:02 by cjulienn          #+#    #+#             */
/*   Updated: 2022/12/01 16:07:19 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/test_includes.hpp"

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
