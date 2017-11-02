
#include <iostream>
#include "calendar.hpp"
#include "dateFormatter.hpp"


int main(){
    Date test(15, 12, 1970);
    std::cout<<"test:"<<test;

    Date nowa (16, 2, 2000);
    std::cout<<"nowa:"<<nowa;

    Date wynik;
    wynik=nowa-test;
    std::cout<<nowa<<'-'<<test<<'='<<wynik;

}


