/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:31:00 by cjulienn          #+#    #+#             */
/*   Updated: 2022/11/17 15:33:35 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_HPP
# define NODE_HPP

#include <functional>
# include <limits>
# include <memory>
# include <vector>
# include <cstddef>
# include <sstream>

# include "../../utils/pair.hpp"

# define RED		true
# define BLACK		false

# define RIGHT		3
# define LEFT		4

namespace ft
{
	template <
		typename Key,
		typename T,
		typename Compare = std::less<Key>,
		typename Alloc = std::allocator<pair<const Key, T> > 
	> class Node
	{
		public:

			/* ALIASES */
			typedef Key										key_type;
			typedef T										mapped_type;
			typedef pair<const Key, T>	 					value_type;
			typedef Compare									key_compare;
			typedef Alloc									allocator_type;
			typedef typename Alloc::reference 				reference;
			typedef typename Alloc::const_reference 		const_reference;
			typedef typename Alloc::pointer					pointer;
			typedef typename Alloc::const_pointer			const_pointer;
			typedef typename std::size_t 					size_type;
			typedef typename std::ptrdiff_t 				difference_type;

			/* CONSTRUCTORS, DESTRUCTORS, OVERLOADING OPERATOR = */
			Node(void) : _color(RED), _right(nullptr), _left(nullptr), _parent(nullptr)
			{
				this->_val._first_type = const Key;
				this->_val._second_type = T;
			}

			Node(value_type &value) : _color(RED), _right(nullptr), _left(nullptr), _parent(nullptr), _val(value) {};

			

			/* METHODS */
			
			
			
		private:

			bool			_color;
			value_type		_val;
			Node			*_left;
			Node			*_right;
			Node			*_parent;
	};
}

#endif
