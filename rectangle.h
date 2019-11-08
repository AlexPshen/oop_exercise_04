#ifndef D_RECTANGLE_H_
#define D_RECTANGLE_H_ 1

#include <algorithm>
#include <iostream>

#include "vertex.h"

template<class T>
struct rectangle{
private:
    vertex<T> top1, top2, top3, top4;
public:
    rectangle(std::istream& is){
        is >> top1.x >> top1.y >> top2.x >> top2.y >> top3.x >> top3.y >> top4.x >> top4.y;
        double scalar1 = scalar_mult(top2, top1, top3);
        double scalar2 = scalar_mult(top2, top1, top4); 
        double scalar3 = scalar_mult(top3, top1, top4);
        double scalar01, scalar02, scalar03;
        if(scalar1 == 0){
            scalar01 = scalar_mult(top4, top2, top1); 
            scalar02 = scalar_mult(top2, top4, top3); 
            scalar03 = scalar_mult(top1, top3, top4);     
            if(!(scalar01 == 0 && scalar02 == 0 && scalar03 == 0)){
                throw std::logic_error("It is not rectangle");
            }
        } else if(scalar2 == 0){
            scalar01 = scalar_mult(top1, top2, top3);
            scalar02 = scalar_mult(top1, top4, top3);
            scalar03 = scalar_mult(top2, top3, top4);     
            if(!(scalar01 == 0 && scalar02 == 0 && scalar03 == 0)){
                throw std::logic_error("It is not rectangle");
            }
        } else if(scalar3 == 0){
            scalar01 = scalar_mult(top3, top2, top4); 
            scalar02 = scalar_mult(top1, top4, top2);
            scalar03 = scalar_mult(top2, top3, top1);   
            if(!(scalar01 == 0 && scalar02 == 0 && scalar03 == 0)){
                throw std::logic_error("It is not rectangle");
            }  
        } else {
            throw std::logic_error("It is not rectangle");
        }
    }
    
    rectangle(vertex<T>& p1, vertex<T>& p2, vertex<T>& p3, vertex<T>& p4);
    vertex<double> center() const;
    double area() const;
    void print(std::ostream& os) const;
};

template<class T>
rectangle<T>::rectangle(vertex<T>& p1, vertex<T>& p2, vertex<T>& p3, vertex<T>& p4){
    top1.x = p1.x;
    top1.y = p1.y;
    top2.x = p2.x;
    top2.y = p2.y;
    top3.x = p3.x;
    top3.y = p3.y;
    top4.x = p4.x;
    top4.y = p4.y;
    double scalar1 = scalar_mult(top2, top1, top3);
    double scalar2 = scalar_mult(top2, top1, top4); 
    double scalar3 = scalar_mult(top3, top1, top4);
    double scalar01, scalar02, scalar03;
    if(scalar1 == 0){
        scalar01 = scalar_mult(top4, top2, top1); 
        scalar02 = scalar_mult(top2, top4, top3); 
        scalar03 = scalar_mult(top1, top3, top4);   
        if(!(scalar01 == 0 && scalar02 == 0 && scalar03 == 0)){
            throw std::logic_error("It is not quadrate");
        }
    } else if(scalar2 == 0){
        scalar01 = scalar_mult(top1, top2, top3);
        scalar02 = scalar_mult(top1, top4, top3);
        scalar03 = scalar_mult(top2, top3, top4);   
        if(!(scalar01 == 0 && scalar02 == 0 && scalar03 == 0)){
            throw std::logic_error("It is not quadrate");      
        }
    } else if(scalar3 == 0){
        scalar01 = scalar_mult(top3, top2, top4); 
        scalar02 = scalar_mult(top1, top4, top2);
        scalar03 = scalar_mult(top2, top3, top1);   
        if(!(scalar01 == 0 && scalar02 == 0 && scalar03 == 0)){
            throw std::logic_error("It is not quadrate");
        }  
    } else {
        throw std::logic_error("It is not quadrate");
    }
}


template<class T>
void rectangle<T>::print(std::ostream& os) const{
    os << "[" << top1 << "]" << " ";
    os << "[" << top2 << "]" << " "; 
    os << "[" << top3 << "]" << " ";
    os << "[" << top4 << "]" << " ";  
    os << '\n';
}

template<class T>
double rectangle<T>::area() const{
    double scalar1 = scalar_mult(top2, top1, top3);
    double scalar2 = scalar_mult(top2, top1, top4); 
    double scalar3 = scalar_mult(top3, top1, top4);
    double mid1, mid2;
    if(scalar1 == 0){
        mid1 = segment_length(top1, top2);
        mid2 = segment_length(top1, top3);
    } else if(scalar2 == 0){
        mid1 = segment_length(top1, top2);
        mid2 = segment_length(top1, top4);
    } else if(scalar3 == 0){
        mid1 = segment_length(top1, top3);
        mid2 = segment_length(top1, top4);
    }
    return mid1 * mid2;
}

template<class T>
vertex<double> rectangle<T>::center() const{
    double scalar1 = scalar_mult(top2, top1, top3);
    double scalar2 = scalar_mult(top2, top1, top4); 
    double scalar3 = scalar_mult(top3, top1, top4);
    double midx, midy;
    if(scalar1 == 0){
        midx = (top3.x + top2.x) * 0.5;
        midy = (top3.y + top2.y) * 0.5;
    } else if(scalar2 == 0){
        midx = (top4.x + top2.x) * 0.5;
        midy = (top4.y + top2.y) * 0.5;
    } else if(scalar3 == 0){
        midx = (top3.x + top4.x) * 0.5;
        midy = (top3.y + top4.y) * 0.5;
    }
    return vertex<double>{midx, midy};
}


#endif
