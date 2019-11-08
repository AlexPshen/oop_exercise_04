#include <array>
#include <iostream>
#include <tuple>

#include "triangle.h"
#include "quadrate.h"
#include "rectangle.h"
#include "templates.h"


int main(){
    while(1){
        char com1[40];
        std::cin >> com1;
        if(strcmp(com1, "triangle") == 0){
            vertex<double> p1, p2, p3;
            std::cin >> p1 >> p2 >> p3;
            triangle<double> r_tr(p1, p2, p3);
            std::cout << area(r_tr) << std::endl;
            print(r_tr, std::cout);
            std::cout << "{" << center(r_tr) << "}" << std::endl;
            std::tuple<vertex<double>, vertex<double>, vertex<double>> f_tr{p1, p2, p3};
            std::cout << area(f_tr) << std::endl;
            print(f_tr, std::cout);

            std::array<vertex<double>, 3> f_t{p1, p2, p3};
            std::cout << area(f_t) << std::endl;
            print(f_t, std::cout);
        } else if(strcmp(com1, "quadrate") == 0){
            vertex<double> p1, p2, p3, p4;
            std::cin >> p1 >> p2 >> p3 >> p4;
            quadrate<double> r_tr(p1, p2, p3, p4);
            std::cout << area(r_tr) << std::endl;
            print(r_tr, std::cout);
            std::cout << "{" << center(r_tr) << "}" << std::endl;
            std::tuple<vertex<double>, vertex<double>, vertex<double>, vertex<double>> f_tr{p1, p2, p3, p4};
            std::cout << area(f_tr) << std::endl;
            print(f_tr, std::cout);

            std::array<vertex<double>, 4> f_t{p1, p2, p3, p4};
            std::cout << area(f_t) << std::endl;
            print(f_t, std::cout);
        } else if(strcmp(com1, "rectangle") == 0){
            vertex<double> p1, p2, p3, p4;
            std::cin >> p1 >> p2 >> p3 >> p4;
            rectangle<double> r_tr(p1, p2, p3, p4);
            std::cout << area(r_tr) << std::endl;
            print(r_tr, std::cout);
            std::cout << "{" << center(r_tr) << "}" << std::endl;
            std::tuple<vertex<double>, vertex<double>, vertex<double>, vertex<double>> f_tr{p1, p2, p3, p4};
            std::cout << area(f_tr) << std::endl;
            print(f_tr, std::cout);

            std::array<vertex<double>, 4> f_t{p1, p2, p3, p4};
            std::cout << area(f_t) << std::endl;
            print(f_t, std::cout);
        } else if(strcmp(com1, "exit") == 0){
            break;
        } else {
            std::cout << "Incorrect command\n";
        }
    }
}
