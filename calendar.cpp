/*
 * calendar.cpp
 *
 *  Created on: 18 paź 2017
 *      Author: kuczaty
 */

#include  "calendar.hpp"

bool isLeap(int year){
	if(year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
		return true;
	else
		return false;

}

Date::Date(int _day, int _month, int _year) : day(_day),month(_month),year(_year){


}

bool Date::operator==(const Date& d)const{
	if(day==d.day && month==d.month && year==d.year)
		return true;
	else
		return false;

}

bool Date::operator!=(const Date& d)const{
	return !(this->operator==(d));
}

Date Date::operator +(int numberOfDays )const{

	int temp_year=year;
	int temp_month=month;
	int temp_day=day;


	for(int i=0;i<numberOfDays;i++){
		if(temp_day<numOfDays[temp_month])
			temp_day++;
		else if(temp_month<12){
			temp_day=1;
			temp_month++;
		}else{
			temp_year++;
			temp_month=1;
			temp_day=1;
		}
	}

	Date nDate=Date(temp_day,temp_month, temp_year);
	return nDate;



}

std::ostream & operator<<(std::ostream& out, const Date & data){

	out<<data.year<<"-"<<data.month<<"-"<<data.day<<std::endl;
	return out;
}

int Date::dateToInt(){

	int numberOfDays=0;

	for(int i=1970;i<year;i++){
		if(isLeap(i))
			numberOfDays+=366;
		else
			numberOfDays+=365;
	}

	for(int i=1;i<month;i++){
		if(i==2 && isLeap(year))
			numberOfDays++;

		numberOfDays+=numOfDays[i];
	}

	numberOfDays+=day-1;

	return numberOfDays;

}

Date intToDate(int numberOfDays){

	Date d;

	while(numberOfDays>0){
		if(isLeap(d.year)&&numberOfDays>366){
			d.year++;
			numberOfDays-=366;
		}else if(!isLeap(d.year)&&numberOfDays>365){
			d.year++;
			numberOfDays-=365;
		}
		else if(isLeap(d.year)&&d.month==2&&numberOfDays>29){
				numberOfDays-=29;
			d.month++;
		}else if(numberOfDays>d.numOfDays[d.month]){
			numberOfDays-=d.numOfDays[d.month];
			d.month++;
		}else{
			d.day=numberOfDays+1;
			break;
		}
	}

	return d;

}


