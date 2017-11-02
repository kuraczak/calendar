#include  "calendar.hpp"

Date::Date(int _day, int _month, int _year) {
    day=_day;
    month=_month;
    year=_year;
}

Date::Date(const Date & tmp){
    day=tmp.day;
    month=tmp.month;
    year=tmp.year;
}

Date:: ~Date(){};

std::ostream & operator<<(std::ostream &out, const Date &oth){
    out<<"("<<oth.year<<"-"<<oth.month<<"-"<<oth.day<<")"<<'\n';
}

Date &Date:: operator= (const Date & tmp){
    day=tmp.day;
    month=tmp.month;
    year=tmp.year;
return *this;
}

Date Date::operator+(int add_days) const{
    Date tmp=*this;
    int freedays=numOfDays[tmp.month]-tmp.day;
    std::cout<<"freedays:"<<freedays<<'\n';

    int i = tmp.month;
    while(add_days>tmp.numOfDays[i]){
        std::cout<<"i:"<<i<<'\n';
        std::cout<<"nOd w forze:"<<tmp.numOfDays[i]<<'\n';
        if(tmp.month==12){
            tmp.year++;
            tmp.month=1;
            i=1;
        }
        add_days=add_days-tmp.numOfDays[i];
        std::cout<<"adddays:"<<add_days<<'\n';
        tmp.month++;
        i++;
    }
    tmp.day=tmp.day+add_days;
return tmp;
}

Date Date::operator- (int less_days) const{
    Date tmp=*this;
    if(less_days<tmp.day){
        tmp.day=tmp.day-less_days;
        return tmp;
    }

    int i=tmp.month;
    less_days=less_days-tmp.day;
    while(less_days>numOfDays[i-1]){
        std::cout<<"lessdays:"<<less_days<<'\n';
        if(tmp.month==1){
            tmp.year--;
            if(tmp.year<0){
                std::cout<<"Data wyszla z epoki";
                return 0;
            }
            tmp.month=12;
            i=12;
        }
        tmp.month--;
        i--;
        std::cout<<"i:"<<i<<'\n';
        std::cout<<"nOd w forze:"<<tmp.numOfDays[i]<<'\n';
        less_days=less_days-numOfDays[i];
        std::cout<<"lessdaysprim:"<<less_days<<'\n';
    }
return tmp;
}

Date Date::operator+(const Date &tmp)const{
    Date added=*this;
    added.year=added.year+tmp.year;

    added.month=added.month+tmp.month;
    if(added.month>12){
        added.month=added.month-12;
        added.year++;
    }

    added.day=tmp.day+day;
    if(added.day>numOfDays[added.month]){
        added.day=added.day-numOfDays[added.month];
        added.month++;
        if(added.month==13){
            added.year++;
            added.month=1;
        }
    }
return added;
}

Date Date::operator-(const Date &tmp)const{
    Date lesser=*this;
    lesser.year=lesser.year-tmp.year;
    if (lesser.year<0){
        std::cout<<"Data wyszla z epoki";
        return 0;
    }


    if((month-tmp.month)<0){
        lesser.month=12-lesser.month;
        lesser.year--;
        if(lesser.year<0){
                std::cout<<"Data wyszla z epoki";
                return 0;
            }
    }
    else
        lesser.month=lesser.month-tmp.month;


    if((day-tmp.day)<0){
        lesser.day=numOfDays[lesser.month-1]+(day-tmp.day);
        lesser.month--;
        if(lesser.month==0){
            lesser.year--;
            if(lesser.year<0){
                std::cout<<"Data wyszla z epoki";
                return 0;
            }
            lesser.month=12;
        }
    }
    else
        lesser.day=day-tmp.day;
return lesser;
}

Date &Date::operator+=(const Date &tmp) {
    year=year+tmp.year;

    month=month+tmp.month;
    if (month>12){
        year++;
        month==1;
    }

    day=day+tmp.day;
    if (day>numOfDays[month]){
        day=day-numOfDays[month+1];
        month++;
        if(month>12){
            year++;
            month==1;
        }
    }
return *this;
}

//  podobnie operator -= ale mi się już nie chce



bool Date::operator==(const Date& d)const{
	if(day==d.day && month==d.month && year==d.year)
		return true;
	else
		return false;
}

bool Date::operator!=(const Date& d)const{
	return !(this->operator==(d));
}


