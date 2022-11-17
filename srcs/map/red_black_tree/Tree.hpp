/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:31:02 by cjulienn          #+#    #+#             */
/*   Updated: 2022/11/17 15:36:25 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_HPP
# define TREE_HPP

# include "./Node.hpp"
# include "../../utils/pair.hpp"

# include <limits>
# include <memory>
# include <vector>
# include <cstddef>
# include <sstream>
# include <functional>

namespace ft
{
	template <typename Key, typename T, typename Compare = std::less<Key>,
	typename Alloc = std::allocator<ft::pair<const Key, T> > > 
	class Tree
	{
		public:

			/* ALIASES */
			typedef Node<const Key, T, Cmp, Allocator>		node;
			typedef Key										key_type;
			typedef T										mapped_type;
			typedef pair<const Key, T>						value_type;
			typedef std::size_t								size_type;
			typedef Compare									key_compare;
			typedef Alloc									allocator_type;
			typedef typename Alloc::reference 				reference;
			typedef typename Alloc::const_reference 		const_reference;
			typedef typename Alloc::pointer					pointer;
			typedef typename Alloc::const_pointer			const_pointer;

			/* CONSTRUCTORS AND DESTRUCTORS */

			Tree(void) : 

		private:

			node					*_root;
			size_type				_size;
			key_compare				_comparing;
			allocator_type			_treeAlloc;
			std::allocator<node>	_nodeAlloc;
	};
}

#endif
