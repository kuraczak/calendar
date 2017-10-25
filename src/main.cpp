/*
 * mian.cpp
 *
 *  Created on: 18 paź 2017
 *      Author: kuczaty
 */
#include <iostream>
#include "calendar.hpp"

#include <stdio.h>
#include "gtest/gtest.h"

GTEST_API_ int main(int argc, char **argv) {
  printf("Running main() from gtest_main.cc\n");
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}



//int main(){



//	Date data1(29,2,1900);
//
//
//
//	std::cout<<data1;
//
//	int datai=data1.dateToInt();
//
//	std::cout<<intToDate(datai);



//}


