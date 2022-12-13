/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:35:08 by cjulienn          #+#    #+#             */
/*   Updated: 2022/12/12 17:16:47 by cjulienn         ###   ########.fr       */
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


static void	leaks_tracking(void)
{
	system("leaks Lab");
}

int main(void)
{	
	atexit(leaks_tracking);

	std::vector<int>		test;
	std::cout << test.max_size() << std::endl;
	return 0;
}
