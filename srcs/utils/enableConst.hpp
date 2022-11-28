/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enableConst.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 14:06:11 by cjulienn          #+#    #+#             */
/*   Updated: 2022/11/28 11:47:53 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENABLE_CONST_HPP
# define ENABLE_CONST_HPP

/* enableConst is not an util duplicated from the STL. However, it is useful in order to have a DRY code.
enableConst is a struct which allows to have two used template specialization. When the typename IsConst is 
true, then the struct member Type is of type Const, otherwise of type Var.

Exemple for usage : 

typedef typename ft::enable_const<IsConst, value_type*, const value_type*>::type	pointer;
typedef typename ft::enable_const<IsConst, value_type&, const value_type&>::type	reference;

in this example, type will be of type Const if Isconst is set to true, Var otherwise */

namespace ft
{
	// never use unspecialized template !!!
	template <bool IsConst, typename Var, typename Const>
	struct enable_const
	{
		// nothing there, empty struct
	};

	template <typename Var, typename Const> // case it is not a const iterator
	struct enable_const<true, Var, Const>
	{
		typedef Var			type;
	};
	
	template <typename Var, typename Const> // case it is a const iterator
	struct enable_const<false, Var, Const>
	{
		typedef Const		type;
	};	
}

#endif
