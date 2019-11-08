#ifndef D_VERTEX_H_
#define D_VERTEX_H_ 1

#include <iostream>
#include<vector>
#include<cmath>
#include<string.h>

template<class T>
struct vertex {
    T x;
    T y;
};

template<class T>
std::istream& operator>> (std::istream& is, vertex<T>& p) {
  is >> p.x >> p.y;
  return is;
}

template<class T>
std::ostream& operator<< (std::ostream& os, const vertex<T>& p) {
  os << p.x << ' ' << p.y;
  return os;
}

template<class T>
double scalar_mult(vertex<T> top1_end, vertex<T> top_begin, vertex<T> top2_end){
    return (top_begin.x - top1_end.x)*(top_begin.x - top2_end.x) + (top_begin.y - top1_end.y)*(top_begin.y - top2_end.y);
}

template<class T>
double segment_length(vertex<T> top1, vertex<T> top2){
    return sqrt(pow(top1.x - top2.x, 2) + pow(top1.y - top2.y, 2));
}

#endif // D_VERTEX_H_
