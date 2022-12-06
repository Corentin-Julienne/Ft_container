/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:35:08 by cjulienn          #+#    #+#             */
/*   Updated: 2022/12/06 17:55:23 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <functional>
#include <iostream>
#include <memory>
#include <algorithm>
#include <vector>
#include <ctime>

void	leaks_tracking(void)
{
	system("leaks Lab");
}

int main(void)
{
	atexit(leaks_tracking);
	
	// beginning test
	std::time_t			test_start = std::time(nullptr);
	std::vector<int>	std_test;

	for (std::size_t i = 0; i < 10000; i++)
		std_test.push_back(i);
	std::time_t			test_end = std::time(nullptr);
	std::cout << "Time elapsed = " << test_end - test_start << std::endl;	
	return (0);
}
