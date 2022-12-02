/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_includes.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:46:01 by cjulienn          #+#    #+#             */
/*   Updated: 2022/12/01 17:26:37 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_INCLUDES_HPP
# define TEST_INCLUDES_HPP

/* includes form STD and STL */
#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <functional>
#include <ctime>

/* includes from namespace ft */
#include "../../srcs/vector/Vector.hpp"
#include "../../srcs/vector/VectorIterator.hpp"
#include "../../srcs/map/Map.hpp"
#include "../../srcs/map/MapIterator.hpp"
#include "../../srcs/map/redBlackTree.hpp"

/* include from test utils */
#include "./test_utils/Colors.hpp"

/* utils */
void		separator(Colors &col);
/* tests on tree */
void		red_black_tree_verification(Colors &col);
/* tests on map */
void		map_verif_procedure(Colors &col);
/* tests on vectors */
void		vector_verif_procedure(Colors &col);
void		vector_speedtest(Colors &col);

#endif
