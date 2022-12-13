/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VectorIterator.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 18:15:58 by cjulienn          #+#    #+#             */
/*   Updated: 2022/12/12 16:32:20 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP

# include "../utils/iteratorTraits.hpp"

namespace ft
{
	template <typename T>
	class vectorIterator
	{
		public:
		
			/* ALIASES */
			typedef T														 		iterator_type; // the type of vector
			typedef typename iterator_traits<iterator_type>::iterator_category 		iterator_category;
			typedef typename iterator_traits<iterator_type>::value_type        		value_type;
			typedef typename iterator_traits<iterator_type>::difference_type   		difference_type;
			typedef typename iterator_traits<iterator_type>::pointer           		pointer;
			typedef typename iterator_traits<iterator_type>::reference         		reference;
			
			/* CONSTRUCTOR, DESTRUCTOR, COPY CONSTRUCTOR, OVERLOAD OPERATOR = */
			vectorIterator(void) : _ptr(nullptr) {}; // useful ?
			vectorIterator(pointer ptr) : _ptr(ptr) {};
			vectorIterator(const vectorIterator& original) : _ptr(original._ptr) {};
			
			virtual ~vectorIterator() {};
			
			vectorIterator&	operator=(const vectorIterator& original)
			{
				if (this != &original)
					this->_ptr = original._ptr;
				return (*this);
			}

			/* ARITHMETICS OPERATORS */
			vectorIterator		operator+(difference_type diff) { return (vectorIterator(_ptr + diff)); };
			vectorIterator		operator-(difference_type diff) { return (vectorIterator(_ptr - diff)); };

			difference_type		operator+(vectorIterator other) { return _ptr + other._ptr; };
			difference_type		operator-(vectorIterator other) { return _ptr - other._ptr; };

			/* INCREMENTATION OPERATORS */
			vectorIterator&	operator++() { _ptr++; return *this; };
			vectorIterator	operator++(int)
			{
				vectorIterator		tmp(_ptr);

				_ptr++;
				return	tmp;
			}
			vectorIterator&	operator--() { _ptr--; return *this; };
			vectorIterator	operator--(int)
			{
				vectorIterator		tmp(_ptr);

				_ptr--;
				return	tmp;
			}

			vectorIterator&	operator+=(difference_type diff) { _ptr += diff; return *this; };
			vectorIterator&	operator-=(difference_type diff) { _ptr -= diff; return *this; };

			/* EQUIVALENCY OPERATORS */
			bool	operator==(vectorIterator const &other) const { return _ptr == other._ptr; };
			bool	operator!=(vectorIterator const &other) const { return _ptr != other._ptr; };
			bool	operator<(vectorIterator const &other) const { return _ptr < other._ptr; };
			bool	operator>(vectorIterator const &other) const { return _ptr > other._ptr; };
			bool	operator<=(vectorIterator const &other) const { return _ptr <= other._ptr; };
			bool	operator>=(vectorIterator const &other) const { return _ptr >= other._ptr; };

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
