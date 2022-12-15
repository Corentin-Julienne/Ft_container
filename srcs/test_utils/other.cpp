/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:49:37 by cjulienn          #+#    #+#             */
/*   Updated: 2022/12/15 17:02:31 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* utils for the tets of vector, map and tree */

#include "../../includes/test_includes.hpp"

/* prints a dividing line to more readability */
void	separator(Colors &col)
{
	std::cout << col.bdYellow() << "----------------------------------------------------------" 
	<< col.reset() << std::endl;
}

