/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Colors.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 12:25:01 by cjulienn          #+#    #+#             */
/*   Updated: 2022/11/14 13:30:24 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_HPP
# define COLORS_HPP

#include	<string>
#include	<iostream>

/* Colors class allows to handle std::cout text coloration on the output in the terminal */

class Colors
{
	public:
	
		Colors(void);
		Colors(const Colors& original);
		~Colors();

		Colors&	operator=(const Colors &original);

		const std::string	red(void) const;
		const std::string 	green(void) const;
		const std::string	yellow(void) const;
		const std::string	blue(void) const;

		const std::string	bdRed(void) const;
		const std::string	bdGreen(void) const;
		const std::string	bdYellow(void) const;
		const std::string	bdBlue(void) const;

		const std::string	undRed(void) const;
		const std::string	undGreen(void) const;
		const std::string	undYellow(void) const;
		const std::string	undBlue(void) const;

		const std::string	end(void) const;
		const std::string	reset(void) const;

	private:
	
		const std::string			_red;
		const std::string			_green;
		const std::string			_yellow;
		const std::string			_blue;
		
		const std::string			_bdRed;
		const std::string			_bdGreen;
		const std::string			_bdYellow;
		const std::string			_bdBlue;

		const std::string			_undRed;
		const std::string			_undGreen;
		const std::string			_undYellow;
		const std::string			_undBlue;

		const std::string			_end; // reset color only
		const std::string			_reset; // reset color and effects
};

#endif
