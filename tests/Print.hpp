/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:07:21 by cjulienn          #+#    #+#             */
/*   Updated: 2022/11/30 12:34:25 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <map>

#ifndef PRINT_HPP
# define PRINT_HPP

	/* never used the unspecialoized template function !!! */
	template<bool IsStl, typename STL_Map, typename FT_Map>
	struct	map_content
	{
		// nothing there, see template specializations
	}

	/* case this is an STL map */
	template<typename STL_Map, typename FT_Map >
	struct map_content<true, STL_Map, FT_Map>
	{
		typedef STL_Map			map_type;
	}

	/* case this is an FT map */
	template<typename STL_Map, typename FT_Map>
	struct map_content<false, STL_Map, FT_Map>
	{
		typedef	FT_Map			map_type;
	}
	
	/* should be able to print the content of a map (key and value) */
	template <typename Map>
	void	print_map(Map &map, bool type)
	{
		struct map_content<type, >		what_type;
	}

#endif
