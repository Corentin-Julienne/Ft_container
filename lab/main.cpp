/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:35:08 by cjulienn          #+#    #+#             */
/*   Updated: 2022/12/05 16:33:32 by cjulienn         ###   ########.fr       */
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
	std::vector<int>				new_vect;

	new_vect.push_back(747);
	new_vect.push_back(666);
	new_vect.push_back(-7);

	test.push_back(4);

	test.insert(test.begin(), new_vect.begin(), new_vect.end());
	for (std::size_t i = 0; i < test.size(); i++)
		std::cout << "index [" << i << "] = " << test[i] << std::endl;
	return (0);
}
