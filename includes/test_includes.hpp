/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_includes.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:46:01 by cjulienn          #+#    #+#             */
/*   Updated: 2022/12/15 17:44:53 by cjulienn         ###   ########.fr       */
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
// add vector and map
#include "./vector/vector.hpp"
#include "./vector/vectorIterator.hpp"
#include "./map/map.hpp"
#include "./map/mapIterator.hpp"
#include "./map/node.hpp"
#include "./map/trees/binarySearchTree.hpp"
// add utils
#include "./utils/compare.hpp"
#include "./utils/enableConst.hpp"
#include "./utils/enableIf.hpp"
#include "./utils/isIntegral.hpp"
#include "./utils/iteratorTraits.hpp"
#include "./utils/pair.hpp"
#include "./utils/reverseIterator.hpp"

/* include from test utils */
#include "../srcs/test_utils/colors.hpp"

/* utils */
void		separator(Colors &col);
/* tests on tree */
void		tree_verification(Colors &col);
/* tests on map */
void		map_verif_procedure(Colors &col);
/* tests on vectors */
void		vector_verif_procedure(Colors &col);
void		vector_speedtest(Colors &col);

#endif
