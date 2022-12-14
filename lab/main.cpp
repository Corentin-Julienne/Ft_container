/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:35:08 by cjulienn          #+#    #+#             */
/*   Updated: 2022/12/13 17:57:39 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <functional>
#include <iostream>
#include <memory>
#include <algorithm>
#include <vector>
#include <map>
#include <iterator>
#include <ctime>
#include <time.h>
#include <string>

static void	leaks_tracking(void)
{
	system("leaks Lab");
}

int main(void)
{	
	atexit(leaks_tracking);

	std::map<int, std::string>		test;
	std::map<int, std::string>::iterator		it = test.begin();
	std::map<int, std::string>::iterator		it2 = test.end();

	if (it == it2)
		std::cout << "equal to end()" << std::endl;
	return 0;
}
