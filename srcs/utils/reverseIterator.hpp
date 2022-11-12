/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverseIterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:08:56 by cjulienn          #+#    #+#             */
/*   Updated: 2022/11/12 10:40:53 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef reverseIterator_HPP
# define reverseIterator_HPP

# include "iteratorTraits.hpp"

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
			
			reverseIterator(void) : _current() {}
			
			explicit reverseIterator(iterator_type it) : _current(it) {}
			
			template<class Iterator>
			reverseIterator (const reverseIterator<Iterator>& rev_it) : _current(it._current) {}
			
			iterator_type	base() const { return (this->_current); }

			/* OVERLOADING OPERATORS */

			reference	operator*() const
			{
				// TODO
			}

			reverseIterator	operator+(difference_type n) const
			{
				// TODO
			}

			reverseIterator&	operator++()
			{
				// TODO
			}

			reverseIterator 	operator++(int)
			{
				// TODO
			}
			
			reverseIterator&	operator+=(difference_type n)
			{
				// TODO
			}

			reverseIterator	operator-(difference_type n) const
			{
				// TODO
			}

			reverseIterator&	operator--()
			{
				// TODO
			}

			reverseIterator	operator--(int)
			{
				// TODO
			}

			reverseIterator&	operator-=(difference_type n)
			{
				// TODO
			}

			pointer	operator->() const
			{
				// TODO
			}

			reference	operator[](difference_type n) const
			{
				// TODO
			}
		
		private:

			// eventual helper function
			
	};

	// NON-MEMBER OVERLOAD

	template <class Iterator>
	bool	operator==(const reverseIterator<Iterator>& lhs, const reverseIterator<Iterator>& rhs)
	{
		// TODO
	}

	template <class Iterator>
	bool	operator!=(const reverseIterator<Iterator>& lhs, const reverseIterator<Iterator>& rhs)
	{
		// TODO
	}

	template <class Iterator>
	bool	operator<(const reverseIterator<Iterator>& lhs, const reverseIterator<Iterator>& rhs)
	{
		// TODO
	}

	template <class Iterator>
	bool	operator<=(const reverseIterator<Iterator>& lhs, const reverseIterator<Iterator>& rhs)
	{
		// TODO
	}

	template <class Iterator>
	bool	operator>(const reverseIterator<Iterator>& lhs, const reverseIterator<Iterator>& rhs)
	{
		// TODO
	}

	template <class Iterator>
	bool	operator>=(const reverseIterator<Iterator>& lhs, const reverseIterator<Iterator>& rhs)
	{
		// TODO
	}

	template <class Iterator>
	reverseIterator<Iterator>	operator+(typename reverseIterator<Iterator>::difference_type n,
			const reverseIterator<Iterator>& rev_it)
	{
		// TODO
	}

	template <class Iterator>
	typename reverseIterator<Iterator>::difference_type	operator-(const reverseIterator<Iterator>& lhs,
			const reverseIterator<Iterator>& rhs)
	{
		// TODO
	}
}

#endif
