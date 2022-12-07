/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:35:08 by cjulienn          #+#    #+#             */
/*   Updated: 2022/12/07 13:22:01 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <functional>
#include <iostream>
#include <memory>
#include <algorithm>
#include <vector>
#include <map>
#include <ctime>

void	leaks_tracking(void)
{
	system("leaks Lab");
}

int main(void)
{
	atexit(leaks_tracking);
	
	// beginning test
	
	std::map<int, std::string>		test;

	test.insert(test.begin());
	
	return (0);
}
