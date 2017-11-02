#ifndef DATEFORMATTER_HPP_
#define DATEFORMATTER_HPP_
#include <string>
#include <iomanip>
#include "calendar.hpp"

class DateFormatter {

public:
	virtual std::string format(const Date &data)=0;
	virtual ~DateFormatter()=0;
};

class ComputerDateFormatter: public DateFormatter {

};

class GermanDateFormatter: public DateFormatter {

};

#endif /* DATEFORMATTER_HPP_ */
