/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverseIterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:08:56 by cjulienn          #+#    #+#             */
/*   Updated: 2022/11/11 17:24:15 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

# include "iteratorTraits.hpp"

namespace ft
{
	template<class Iterator>
	class reverse_iterator
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
			
			reverse_iterator(void) : _current() {}
			
			explicit reverse_iterator(iterator_type it) : _current(it) {}
			
			template<class Iterator>
			reverse_iterator (const reverse_iterator<Iterator>& rev_it) : _current(it._current) {}
			
			iterator_type	base() const { return (this->_current); }

			/* OVERLOADING OPERATORS */

			reference	operator*() const
			{
				// TODO
			}

			reverse_iterator	operator+(difference_type n) const
			{
				// TODO
			}

			reverse_iterator&	operator++()
			{
				// TODO
			}

			reverse_iterator 	operator++(int)
			{
				// TODO
			}
			
			reverse_iterator&	operator+=(difference_type n)
			{
				// TODO
			}

			reverse_iterator	operator-(difference_type n) const
			{
				// TODO
			}

			reverse_iterator&	operator--()
			{
				// TODO
			}

			reverse_iterator	operator--(int)
			{
				// TODO
			}

			reverse_iterator&	operator-=(difference_type n)
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
	bool	operator==(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		// TODO
	}

	template <class Iterator>
	bool	operator!=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		// TODO
	}

	template <class Iterator>
	bool	operator<(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		// TODO
	}

	template <class Iterator>
	bool	operator<=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		// TODO
	}

	template <class Iterator>
	bool	operator>(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		// TODO
	}

	template <class Iterator>
	bool	operator>=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		// TODO
	}

	template <class Iterator>
	reverse_iterator<Iterator>	operator+(typename reverse_iterator<Iterator>::difference_type n,
			const reverse_iterator<Iterator>& rev_it)
	{
		// TODO
	}

	template <class Iterator>
	typename reverse_iterator<Iterator>::difference_type	operator-(const reverse_iterator<Iterator>& lhs,
			const reverse_iterator<Iterator>& rhs)
	{
		// TODO
	}
}

#endif
