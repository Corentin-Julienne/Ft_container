/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VectorIterator.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 18:15:58 by cjulienn          #+#    #+#             */
/*   Updated: 2022/12/13 12:37:25 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP

# include "../utils/iteratorTraits.hpp"
# include "../utils/enableConst.hpp"

namespace ft
{
	template <typename T, bool IsConst = false>
	class vectorIterator
	{
		public:
		
			/* ALIASES */
			
			/* type of iterator */
			typedef std::bidirectional_iterator_tag  											iterator_category;
			/* various data */
			typedef T														 					value_type;
			typedef std::size_t 																size_type;
			typedef std::ptrdiff_t 																difference_type;
			/* discriminate between const and non const iterators */
			typedef typename ft::enable_const<IsConst, *value_type, const *value_type>::type	pointer;
			typedef typename ft::enable_const<IsConst, &value_type, const &value_type>::type	reference;
			
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

			vectorIterator		operator+(difference_type diff) { return (vectorIterator(_ptr + diff)); }; 	// a + n
			vectorIterator		operator-(difference_type diff) { return (vectorIterator(_ptr - diff)); }; 	// a - n
			difference_type		operator-(vectorIterator other) { return _ptr - other._ptr; }; 				// a - b
			// check for *(1 + it) and *(1 - it)

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
