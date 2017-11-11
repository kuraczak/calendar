/*
 * mian.cpp
 *
 *  Created on: 18 paź 2017
 *      Author: kuczaty
 */
#include <iostream>
#include "calendar.hpp"

int main() {

	Date data1(29, 2, 1900);

	std::cout << data1;

	int datai = data1.dateToInt();

	std::cout << intToDate(datai);
	GermanDateFormatter gdf;
	ComputerDateFormatter cdf;
	std::cout << gdf.format(data1);
	std::cout << cdf.format(data1);

}

