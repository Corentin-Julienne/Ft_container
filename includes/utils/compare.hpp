/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:46:31 by cjulienn          #+#    #+#             */
/*   Updated: 2022/12/14 12:31:28 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPARE_HPP
# define COMPARE_HPP

#include "../test_includes.hpp"

/* contains lexicographical_compare and equal, two template functions used to assess 
equivalence of two ranges of iterators */

namespace ft
{
	/* Compares the elements in the range [first1,last1) 
	with those in the range beginning at first2, 
	and returns true if all of the elements in both ranges match.*/
	template<class InputIterator1, class InputIterator2>
	bool	equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
	{
		while (first1 != last1)
		{
			if (!(*first1 == *first2))
				return false;
			++first1;
			++first2;
		}
		return true;
	}

	/* check wether two ranges of iterator are equal in terms of dictionnary-style 
	alphabetic order*/
	template <class InputIterator1, class InputIterator2>
  	bool	lexicographical_compare(InputIterator1 first1, InputIterator1 last1,
            		InputIterator2 first2, InputIterator2 last2)
	{
		while (first1!=last1)
		{
			if (first2 == last2 || *first2 < *first1)
				return false;
			else if (*first1 < *first2)
				return true;
			++first1;
			++first2;
		}
		return (first2 != last2);
	}
}

#endif
