/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Colors.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 12:24:59 by cjulienn          #+#    #+#             */
/*   Updated: 2022/11/14 13:33:40 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Colors.hpp"

Colors::Colors(void) : _red("\e[0;31m"), _green("\e[0;32m"), _yellow("\e[0;33m"),
_blue("\e[0;34m"), _bdRed("\e[1;31m"), _bdGreen("\e[1;32m"), _bdYellow("\e[1;33m"), 
_bdBlue("\e[1;34m"), _undRed("\e[4;31m"), _undGreen("\e[4;32m"), _undYellow("\e[4;33m"),
_undBlue("\e[4;34m"), _end("\033[39m"), _reset("\033[0m") {}

Colors::Colors(const Colors& original) : _red(original._red), _green(original._green), _yellow(original._yellow),
_blue(original._blue), _bdRed(original._bdRed), _bdGreen(original._bdGreen), _bdYellow(original._bdYellow),
_bdBlue(original._bdBlue), _end(original._end), _reset(original._reset) {}

Colors::~Colors() {}

Colors&		Colors::operator=(const Colors& original) { return *this; }; // should not be used, all member variables are constant

/* main colors */

const std::string	Colors::red(void) const { return this->_red; };

const std::string	Colors::green(void) const { return this->_green; };

const std::string	Colors::yellow(void) const { return this->_yellow; };

const std::string	Colors::blue(void) const { return this->_green; };

/* bold colors */

const std::string	Colors::bdRed(void) const { return this->_bdRed; };

const std::string	Colors::bdGreen(void) const { return this->_bdGreen; };

const std::string	Colors::bdYellow(void) const { return this->_bdYellow; };

const std::string	Colors::bdBlue(void) const { return this->_bdBlue; };

/* underline colors */

const std::string	Colors::undRed(void) const { return this->_undRed; };

const std::string	Colors::undGreen(void) const { return this->_undGreen; };

const std::string	Colors::undYellow(void) const { return this->_undYellow; };

const std::string	Colors::undBlue(void) const { return this->_undBlue; };


/* end and reset effets */

const std::string	Colors::end(void) const { return this->_end; };

const std::string	Colors::reset(void) const { return this->_reset; };
