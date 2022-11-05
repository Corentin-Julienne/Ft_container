/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enableIf.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:46:35 by cjulienn          #+#    #+#             */
/*   Updated: 2022/11/03 15:46:36 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENABLE_IF_HPP
# define ENABLE_IF_HPP

/* enable_if is related to SFINAE (see next paragraph). enable_if check wether a condition is true,
 and enable the template substitution by the compiler. Otherwise, it makes it fails in a SFINAE way */

/* SFINAE (Substitution Failure Is Not An Error) refers to the fact that the compiler will try every template 
possibility (type, including the ones provide by template specialization) in order to find a valid substitution. 
A failure to substitute will not produce a compilation error ,but will merely cause the compiler to try another 
template type, until one works. The error will occurs only if no valid template substitution is found */

namespace ft
{
	/* produce empty struct */
	template<bool B, class T = void>
	struct enable_if {};
 
	template<class T>
	struct enable_if<true, T>
	{
		typedef T type;
	};
}

#endif
