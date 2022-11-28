/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VectorConstIterator.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:39:21 by cjulienn          #+#    #+#             */
/*   Updated: 2022/11/14 10:04:37 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_CONST_ITERATOR_HPP
# define VECTOR_CONST_ITERATOR_HPP

# include "../utils/iteratorTraits.hpp"

namespace ft
{
	template <typename T>
	class vectorConstIterator
	{
		public:
		
			/* ALIASES */
			typedef const T														 	iterator_type; // the type of vector
			typedef typename iterator_traits<iterator_type>::iterator_category 		iterator_category;
			typedef typename iterator_traits<iterator_type>::value_type        		value_type;
			typedef typename iterator_traits<iterator_type>::difference_type   		difference_type;
			typedef typename iterator_traits<iterator_type>::pointer           		pointer;
			typedef typename iterator_traits<iterator_type>::reference         		reference;
			
			/* CONSTRUCTOR, DESTRUCTOR, COPY CONSTRUCTOR, OVERLOAD OPERATOR = */
			vectorConstIterator(void) : _ptr(nullptr) {}; // useful ?
			vectorConstIterator(pointer ptr) : _ptr(ptr) {};
			vectorConstIterator(const vectorConstIterator& original) : _ptr(original._ptr) {};
			
			virtual ~vectorConstIterator() {};
			
			vectorConstIterator&	operator=(const vectorConstIterator& original)
			{
				if (this != &original)
					this->_ptr = original._ptr;
				return (*this);
			}

			/* ARITHMETICS OPERATORS */
			vectorConstIterator		operator+(difference_type diff) { return (vectorConstIterator(_ptr + diff)); };
			vectorConstIterator		operator-(difference_type diff) { return (vectorConstIterator(_ptr - diff)); };

			difference_type		operator+(vectorConstIterator other) { return _ptr + other._ptr; };
			difference_type		operator-(vectorConstIterator other) { return _ptr - other._ptr; };

			/* INCREMENTATION OPERATORS */
			vectorConstIterator&	operator++() { _ptr++; return *this; };
			vectorConstIterator	operator++(int)
			{
				vectorConstIterator		tmp(_ptr);

				_ptr++;
				return	tmp;
			}
			vectorConstIterator&	operator--() { _ptr--; return *this; };
			vectorConstIterator	operator--(int)
			{
				vectorConstIterator		tmp(_ptr);

				_ptr--;
				return	tmp;
			}

			vectorConstIterator&	operator+=(difference_type diff) { _ptr += diff; return *this; };
			vectorConstIterator&	operator-=(difference_type diff) { _ptr -= diff; return *this; };

			/* EQUIVALENCY OPERATORS */
			bool	operator==(vectorConstIterator const &other) const { return _ptr == other._ptr; };
			bool	operator!=(vectorConstIterator const &other) const { return _ptr != other._ptr; };
			bool	operator<(vectorConstIterator const &other) const { return _ptr < other._ptr; };
			bool	operator>(vectorConstIterator const &other) const { return _ptr > other._ptr; };
			bool	operator<=(vectorConstIterator const &other) const { return _ptr <= other._ptr; };
			bool	operator>=(vectorConstIterator const &other) const { return _ptr >= other._ptr; };

			/* OPS WITH POINTERS AND REFERENCES */
			reference			operator*() { return *_ptr; };
			const reference		operator*() const { return *_ptr; };
			reference			operator[](difference_type diff) { return *(_ptr + diff); };
			const reference		operator[](difference_type diff) const { return *(_ptr + diff); };
			pointer				operator->() { return _ptr; };
			const pointer		operator->() const { return _ptr; };
		
		private:

			pointer		_ptr;
			
	};
}

#endif
