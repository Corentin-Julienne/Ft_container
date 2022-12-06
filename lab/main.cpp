/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:35:08 by cjulienn          #+#    #+#             */
/*   Updated: 2022/12/06 11:34:38 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <functional>
#include <iostream>
#include <memory>
#include <algorithm>
#include <vector>

void	leaks_tracking(void)
{
	system("leaks Lab");
}

int main(void)
{
	atexit(leaks_tracking);
	
	std::vector<int>				test;

	test.push_back(4);

	test.assign(0, 42);
	for (std::size_t i = 0; i < test.size(); i++)
		std::cout << "index [" << i << "] = " << test[i] << std::endl;
	std::cout << test.size() << std::endl;
	return (0);
}
