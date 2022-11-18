/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:18:44 by cjulienn          #+#    #+#             */
/*   Updated: 2022/11/18 15:59:35 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_HPP
# define NODE_HPP

#include <functional>
#include <memory>
#include "binarySearchTree.hpp"

#define RED			true
#define BLACK		false

namespace lab
{
	template <class Key, class T>
	class Node
	{	
		public:

			/* ALIASES */
			typedef Key									key_type;
			typedef T									mapped_type;
			typedef std::pair<const Key, T>				value_type;
			typedef std::size_t							size_type;

		public:

			Node(void) : _color(RED), _parent(nullptr), _right(nullptr), _left(nullptr) {}

			Node(value_type &val) : _color(RED), _parent(nullptr), _right(nullptr), _left(nullptr), _val(val) {};

			~Node() {};

			Node(const Node& original) : _color(original._color), _parent(original._parent), _left(original._left),
			_val(original._val) {}

			/* getters and setters */

			void	setParentNode(Node *node) { this->_parent = node; };
			void	setRightNode(Node *node) {this->_right = node; };
			void	setLeftNode(Node *node) {this->_left = node; };

			const Node	getParentNode(void) const { return this->_parent; };
			const Node	getRightNode(void) const { return this->_right; };
			const Node	getLeftNode(void) const { return this->_left; };

			/* utils */
		
		private:

			value_type		_val;
			bool			_color;
			Node			*_parent;
			Node			*_right;
			Node			*_left;
	};
}

#endif
