/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:46:29 by cjulienn          #+#    #+#             */
/*   Updated: 2022/11/29 17:01:50 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft
{
	/* pair struct */
	template <class T1, class T2>
	struct	pair
	{
		/* default constructor */
		pair(void) : first(), second() {};

		/* initialization constructor */
		pair(const T1& a, const T2& b) : first(a), second(b) {};

		/* copy constructor */
		template<class U, class V>
		pair(const pair<U, V>& pr) : first(pr.first), second(pr.second) {};

		/* overloading operator = */
		pair&	operator=(const pair& pr)
		{
			if (this != pr)
			{
				first = pr.first;
				second = pr.second;
			}
			return *this;
		};

		/* member variables */
		T1		first;
		T2		second;
	};

	/* make_pair : call pair constructor and return a pair object */
	template <class T1,class T2>
	pair<T1, T2>	make_pair(T1 x, T2 y)
	{
		return (pair<T1, T2>(x, y));
	}
}

#endif
