/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iteratorTraits.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 13:54:14 by cjulienn          #+#    #+#             */
/*   Updated: 2022/12/14 12:31:46 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAITS_HPP
# define ITERATOR_TRAITS_HPP

#include <iterator>
#include "../test_includes.hpp"

namespace ft
{
	/* general purpose struct */
	template<class Iterator>
	struct iterator_traits
	{
		typedef typename Iterator::difference_type			difference_type;
		typedef typename Iterator::value_type				value_type;
		typedef typename Iterator::pointer					pointer;
		typedef typename Iterator::reference				reference;
		typedef typename Iterator::iterator_category		iterator_category;
	};

	/* specialization for pointers */
	template<class T>
	struct iterator_traits<T*>
	{
		typedef std::ptrdiff_t								difference_type;
		typedef T											value_type;
		typedef T*											pointer;
		typedef T&											reference;
		typedef std::random_access_iterator_tag				iterator_category;	
	};

	/* specialization for const pointers */
	template<class T>
	struct iterator_traits<const T*>
	{
		typedef std::ptrdiff_t								difference_type;
		typedef T											value_type;
		typedef const T*									pointer;
		typedef const T&									reference;
		typedef std::random_access_iterator_tag				iterator_category;	
	};
}

#endif
