/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isIntegral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:46:33 by cjulienn          #+#    #+#             */
/*   Updated: 2022/11/03 15:46:34 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_INTEGRAL_HPP
# define IS_INTEGRAL_HPP

#include <stdint.h>

/* "Integral" refers to integer types (i.e. whole numbers). 
In C++ this means types like int, long, short, etc. */

/* we implemented it using template specialization (if type is not specialized,
value is equal to false, true otherwise) */

namespace ft
{
	template<typename T>
	struct is_integral
	{
		static const bool value = false;
	};

	template<>
	struct is_integral<bool>
	{
		static const bool value = true;
	};

	template<>
	struct is_integral<char>
	{
		static const bool value = true;
	};

	template<>
	struct is_integral<char16_t>
	{
		static const bool value = true;
	};

	template<>
	struct is_integral<char32_t>
	{
		static const bool value = true;
	};

	template<>
	struct is_integral<wchar_t>
	{
		static const bool value = true;
	};

	template<>
	struct is_integral<short>
	{
		static const bool value = true;
	};

	template<>
	struct is_integral<int>
	{
		static const bool value = true;
	};

	template<>
	struct is_integral<long>
	{
		static const bool value = true;
	};

	template<>
	struct is_integral<long long>
	{
		static const bool value = true;
	};
}

#endif
