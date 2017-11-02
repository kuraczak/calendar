/*
 * mian.cpp
 *
 *  Created on: 18 paź 2017
 *      Author: kuczaty
 */
#include <iostream>
#include "calendar.hpp"
#include "dateFormatter.hpp"

int main(){

	Date data1(29,2,1900);



	std::cout<<data1;

	int datai=data1.dateToInt();

	std::cout<<intToDate(datai);
	std::cout<<"Szymon : Eclipse \n 1:0 ";



}


