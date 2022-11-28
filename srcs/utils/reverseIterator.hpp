/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverseIterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:08:56 by cjulienn          #+#    #+#             */
/*   Updated: 2022/11/28 16:22:01 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

# include "iteratorTraits.hpp"

/* reverse iterators are made of standard iterators. There is a relation of -1 between an iterator and its 
reverse version. A standard iterator stops at the end (the element after the next element). The reverse iterator do the
same but the end is actually the element before the first element */

namespace ft
{
	template<class Iterator>
	class reverseIterator
	{
		protected:
			
			Iterator	_current; // current non-reverse iterator
		
		public:

			/* ALIASES */

			typedef Iterator													iterator_type;
			typedef	typename iterator_traits<Iterator>::value_type				value_type;
			typedef	typename iterator_traits<Iterator>::iterator_category		iterator_category;
			typedef typename iterator_traits<Iterator>::difference_type			difference_type;
			typedef typename iterator_traits<Iterator>::pointer					pointer;
			typedef typename iterator_traits<Iterator>::reference				reference;

			/* CONSTRUCTORS AND DESTRUCTORS */
			
			reverseIterator(void) : _current(nullptr) {}
			
			explicit reverseIterator(iterator_type it) : _current(it) {}
			
			template<class Iterator>
			reverseIterator (const reverseIterator<Iterator>& rev_it) : _current(it._current) {}
			
			iterator_type	base() const { return (this->_current); }

			/* OVERLOADING OPERATORS */

			reference	operator*() const // to test
			{
				Iterator	tmp = this->_current;

				--tmp;
				return (*tmp);
			}

			reverseIterator	operator+(difference_type n) const // to test
			{
				return (reverseIterator(this->_current - n));
			}

			reverseIterator&	operator++() // to test
			{
				--(this->_current);
				return *this;
			}

			reverseIterator 	operator++(int) // to test
			{
				reverseIterator		tmp = *this;

				--(this->_current);
				return (tmp);
			}
			
			reverseIterator&	operator+=(difference_type n) // to test
			{
				this->_current -= n;
				return *this;
			}

			reverseIterator	operator-(difference_type n) const // to test
			{
				return (reverseIterator(this->_current + n));
			}

			reverseIterator&	operator--() // to test
			{
				++(this->_current);
				return *this;
			}

			reverseIterator	operator--(int) // to test
			{
				reverseIterator		tmp = *this;

				++(this->_current);
				return (tmp);
			}

			reverseIterator&	operator-=(difference_type n) // to test
			{
				this->_current += n;
				return *this;
			}

			pointer	operator->() const // to test
			{
				return &(operator*());
			}

			reference	operator[](difference_type n) const // to test 
			{
				return *(this->base() - n - 1);
			}	
	};

	// NON-MEMBER OVERLOAD

	template <class Iterator>
	bool	operator==(const reverseIterator<Iterator>& lhs, const reverseIterator<Iterator>& rhs) // to test
	{
		return (lhs._current == rhs._current); 
	}

	template <class Iterator>
	bool	operator!=(const reverseIterator<Iterator>& lhs, const reverseIterator<Iterator>& rhs) // to test
	{
		return (lhs._current != rhs._current); 
	}

	template <class Iterator>
	bool	operator<(const reverseIterator<Iterator>& lhs, const reverseIterator<Iterator>& rhs) // to test
	{
		return (lhs._current > rhs._current);
	}

	template <class Iterator>
	bool	operator<=(const reverseIterator<Iterator>& lhs, const reverseIterator<Iterator>& rhs) // to test
	{
		return (lhs._current >= rhs._current);
	}

	template <class Iterator>
	bool	operator>(const reverseIterator<Iterator>& lhs, const reverseIterator<Iterator>& rhs) // to test
	{
		return (lhs._current < rhs._current);
	}

	template <class Iterator>
	bool	operator>=(const reverseIterator<Iterator>& lhs, const reverseIterator<Iterator>& rhs) // to test
	{
		return (lhs._current <= rhs._current);
	}

	template <class Iterator>
	reverseIterator<Iterator>	operator+(typename reverseIterator<Iterator>::difference_type n, // to test
			const reverseIterator<Iterator>& rev_it)
	{
		return (rev_it->_current - n);
	}

	template <class Iterator>
	typename reverseIterator<Iterator>::difference_type	operator-(const reverseIterator<Iterator>& lhs, // to test
			const reverseIterator<Iterator>& rhs)
	{
		return (rev_it->_current + n);
	}
}

#endif
