/*
 * dateFormatter.hpp
 *
 *  Created on: 14 paź 20 17
 *      Author: kuraczak
 */

#ifndef DATEFORMATTER_HPP_
#define DATEFORMATTER_HPP_
#include <string>
#include "calendar.hpp"

class DateFormatter {

public:
	virtual std::string format( Date &data)=0;
	virtual ~DateFormatter()=0;



};

class ComputerDateFormatter: public DateFormatter {
public:
	std::string format( Date &data);
};

class GermanDateFormatter: public DateFormatter {
public:
	std::string format( Date &data);
};

#endif /* DATEFORMATTER_HPP_ */
