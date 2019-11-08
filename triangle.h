#ifndef D_TRIANGLE_H_
#define D_TRIANGLE_H_ 1

#include <algorithm>
#include <iostream>

#include "vertex.h"

template<class T>
struct triangle {
private:
  vertex<T> verts[3];
public:
  triangle(std::istream& is);
  triangle(vertex<T>& p1, vertex<T>& p2, vertex<T>& p3);

  double area() const;
  vertex<double> center() const;
  void print(std::ostream& os) const;

};

template<class T>
triangle<T>::triangle(std::istream& is) {
    for(int i = 0; i < 3; ++i){
        is >> verts[i];
    }
    if((verts[0].x - verts[1].x) * (verts[2].y - verts[1].y) == (verts[0].y - verts[1].y) * (verts[2].x - verts[1].x)){
        throw std::logic_error("It is not triangle");
    }
}

template<class T>
triangle<T>::triangle(vertex<T>& p1, vertex<T>& p2, vertex<T>& p3){
    verts[0].x = p1.x;
    verts[0].y = p1.y;
    verts[1].x = p2.x;
    verts[1].y = p2.y;
    verts[2].x = p3.x;
    verts[2].y = p3.y;
    if((verts[0].x - verts[1].x) * (verts[2].y - verts[1].y) == (verts[0].y - verts[1].y) * (verts[2].x - verts[1].x)){
        throw std::logic_error("It is not triangle");
    }
}

template<class T>
double triangle<T>::area() const {
  const T dx1 = verts[1].x - verts[0].x;
  const T dy1 = verts[1].y - verts[0].y;
  const T dx2 = verts[2].x - verts[0].x;
  const T dy2 = verts[2].y - verts[0].y;
  return std::abs(dx1 * dy2 - dy1 * dx2) * 0.5;
}

template<class T>
void triangle<T>::print(std::ostream& os) const {
    for(int i = 0; i < 3; ++i){
        os << '[' << verts[i] << ']';
        if(i + 1 != 3){
            os << ' ';
        }
    }
    os << '\n';
    return;
}

template<class T>
vertex<double> triangle<T>::center() const{
    double mid1 = (verts[0].x + verts[1].x + verts[2].x) / 3;
    double mid2 = (verts[0].y + verts[1].y + verts[2].y) / 3;
    return vertex<double>{mid1, mid2};
}

#endif // D_TRIANGLE_H_
