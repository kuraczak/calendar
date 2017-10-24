#ifndef CALENDAR_HPP_
#define CALENDAR_HPP_

#include <iostream>



class Date {
private:
	int day;
	int month;
	int year;
	const int numOfDays[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

public:
	Date(int _day =1, int _month =1, int _year = 1970);
	//~Date();
	Date(const Date &);
	friend std::ostream & operator<<(std::ostream &, const Date &);
	bool operator ==(const Date &) const;
	bool operator !=(const Date &) const;
	Date operator+(int);
	Date operator-(int);
	Date operator+( Date &);
	Date operator-( Date &);
	void operator+=( Date &);
	void operator-=( Date &);
	Date operator=( Date &);

	int dateToInt();
	friend Date intToDate(int);

};

Date intToDate(int);



#endif /* CALENDAR_HPP_ */
