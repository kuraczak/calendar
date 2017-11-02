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
	~Date();
	Date(const Date &);
	friend std::ostream & operator<<(std::ostream &, const Date &);
	//friend std::istream & operator<<(std::ostream &, Date &);
	bool operator ==(const Date &) const;
	bool operator !=(const Date &) const;
	Date operator+(int) const;
	Date operator-(int) const;
	Date operator+(const Date &) const;
	Date operator-(const Date &) const;
	Date &operator+=(const Date &);
	Date &operator-=(const Date &);
	Date &operator=(const Date &);

};

#endif /* CALENDAR_HPP_ */
