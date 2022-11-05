/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:46:29 by cjulienn          #+#    #+#             */
/*   Updated: 2022/11/05 17:37:18 by cjulienn         ###   ########.fr       */
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
		pair(void) : _first_type(), _second_type() {};

		/* initialization constructor */
		pair(const T1& a, const T2& b) : _first_type(a), _second_type(b) {};

		/* copy constructor */
		template<class U, class V>
		pair(const pair<U, V>& pr) : _first_type(pr._first_type), _second_type(pr._second_type) {};

		/* overloading operator = */
		pair&	operator=(const pair& pr)
		{
			if (this != pr)
			{
				_first_type = pr._first_type;
				_second_type = pr._second_type;
			}
			return *this;
		};

		/* member variables */
		T1		_first_type;
		T2		_second_type;
	};

	/* make_pair : call pair constructor and return a pair object */
	template <class T1,class T2>
	pair<T1, T2>	make_pair(T1 x, T2 y)
	{
		return (pair<T1, T2>(x, y));
	}
}

#endif
