/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VectorIterator.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 18:15:58 by cjulienn          #+#    #+#             */
/*   Updated: 2022/11/12 14:52:47 by cjulienn         ###   ########.fr       */
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
					this->_ptn = original._ptn;
				return (*this);
			}

			/* ARITHMETICS OPERATORS */
			vectorIterator		operator+(difference_type diff) { return (vectorIterator(_ptn + diff)); };
			vectorIterator		operator-(difference_type diff) { return (vectorIterator(_ptn - diff)); };

			difference_type		operator+(vectorIterator other) { return _ptr + other._ptn; };
			difference_type		operator-(vectorIterator other) { return _ptr - other._ptn; };

			/* INCREMENTATION OPERATORS */
			vectorIterator&	operator++() { _ptn++; return *this; };
			vectorIterator	operator++(int)
			{
				vectorIterator		tmp(_ptn);

				_ptn++;
				return	tmp;
			}
			vectorIterator&	operator--() { _ptn--; return *this; };
			vectorIterator	operator--(int)
			{
				vectorIterator		tmp(_ptn);

				_ptn--;
				return	tmp;
			}

			VectorIterator&	operator+=(difference_type diff) { _ptn += diff; return *this };
			VectorIterator&	operator-=(difference_type diff) { _ptn -= diff; return *this };

			/* EQUIVALENCY OPERATORS */
			bool	operator==(vectorIterator const &other) const { return _ptn == other._ptn };
			bool	operator!=(vectorIterator const &other) const { return _ptn != other._ptn };
			bool	operator<(vectorIterator const &other) const { return _ptn < other._ptn };
			bool	operator>(vectorIterator const &other) const { return _ptn > other._ptn };
			bool	operator<=(vectorIterator const &other) const { return _ptn <= other._ptn };
			bool	operator>=(vectorIterator const &other) const { return _ptn >= other._ptn };

			/* OPS WITH POINTERS AND REFERENCES */
			reference			operator*() { return *_ptn; };
			const reference		operator*() const { return *_ptn; };
			reference			operator[](difference_type diff) { return *(_ptn + diff); };
			const reference		operator[](difference_type diff) const { return *(_ptn + diff); };
			pointer				operator->() { return _ptn; };
			const pointer		operator->() const { return _ptn; };
		
		private:

			pointer		_ptn;
			
	};
}

#endif
