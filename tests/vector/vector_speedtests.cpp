/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_speedtests.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 16:35:05 by cjulienn          #+#    #+#             */
/*   Updated: 2022/12/01 17:30:45 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/test_includes.hpp"

/* includes some speedtests for basic operations in vector */ // complete

/* check wether the execution is fast enough (ft can be as 20 times slowe than its stl equivalent) */
bool	is_fast_enough()
{
	
}

void	speedtest_result(Colors &col)
{
	if (is_fast_enough())
		std::cout << col.bdGreen() << "Ft feature is fast enough" << col.reset() << std::endl;
	else
		std::cout << col.bdRed() << "Ft is too slow !!!" << col.reset() << std::endl;
}

void	vector_speedtest(Colors &col)
{
	std::cout << col.bdYellow() << "Starting speedtest for vectors" << col.reset() << std::endl;
	
	std::vector<int>	stl_int;
	ft::vector<int>		ft_int;

	std::time_t			stl_timer = std::time(nullptr); // timer for stl
	std::time_t			ft_timer = std::time(nullptr); // timer for ft
	std::time_t			stl_start = std::time(nullptr); // start timer for stl
	std::time_t			ft_start = std::time(nullptr);	// start timer for ft

	

	std::cout << << std::endl;

	
}
