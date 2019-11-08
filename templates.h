#ifndef D_TEMPLATES_H_
#define D_TEMPLATES_H_ 1

#include <tuple>
#include <type_traits>

#include "vertex.h"

template<class T>
struct is_vertex : std::false_type {}; // не точка

template<class T>
struct is_vertex<vertex<T>> : std::true_type {}; //точка

template<class T>
struct is_figurelike_tuple : std::false_type {}; //не фигура

template<class Head, class ... Tail>
struct is_figurelike_tuple<std::tuple<Head, Tail...>> : std::conjunction<is_vertex<Head>, std::is_same<Head, Tail>...> {};

template<class Type, size_t SIZE>
struct is_figurelike_tuple<std::array<Type, SIZE>> : is_vertex<Type> {}; //фигура через массив

template<class T>
inline constexpr bool is_figurelike_tuple_v = is_figurelike_tuple<T>::value; // value фигур


/////////////////////////////

template<class T, class = void>
struct has_area_metod : std::false_type {}; // не имеет метода area

template<class T>
struct has_area_metod<T, std::void_t<decltype(std::declval<const T>().area())>> : std::true_type {};  //имеет метод area

template<class T>
inline constexpr bool has_area_metod_v = has_area_metod<T>::value; // value для имени area

template<class T>
std::enable_if_t<has_area_metod_v<T>, double> area(const T& figure) {
    return figure.area();                                                 // возвращает площадь треугольника
}

template<size_t ID, class T>
double single_area(const T& t) {
    const auto& a = std::get<0>(t);
    const auto& b = std::get<ID - 1>(t);
    const auto& c = std::get<ID>(t);
    const double dx1 = b.x - a.x;
    const double dy1 = b.y - a.y;
    const double dx2 = c.x - a.x;
    const double dy2 = c.y - a.y;
    return std::abs(dx1 * dy2 - dy1 * dx2) * 0.5;  //вычисление части фигуры - треугольника
}

template<size_t ID, class T>
double recursive_area(const T& t) {
    if constexpr (ID < std::tuple_size_v<T>){
        return single_area<ID>(t) + recursive_area<ID + 1>(t);
    }else{
        return 0;
    }
}            //вычисление площади фигуры с разбиением фигуры на треугольники

template<class T>
std::enable_if_t<is_figurelike_tuple_v<T>, double> area(const T& fake) {
    return recursive_area<2>(fake);
}          // возвращает площадь фигуры

///////////////////////////////

template<class T, class = void>
struct has_print_metod : std::false_type {};  // не имеет метода print

template<class T>
struct has_print_metod<T, std::void_t<decltype(std::declval<const T>().print(std::cout))>> : std::true_type {}; // имеет метод print

template<class T>
inline constexpr bool has_print_metod_v = has_print_metod<T>::value; // value для имени print

template<class T>
std::enable_if_t<has_print_metod_v<T>, void> print(const T& figure, std::ostream& os) {
    return figure.print(os);                                               // print вершин треугольника
}

template<size_t ID, class T>
void single_print(const T& t, std::ostream& os) {
    const auto& point = std::get<ID>(t);
    os << "(" << point << ")" << " ";
}                                                       //print одной вершины

template<size_t ID, class T>
void all_print(const T& t, std::ostream& os) {
    if constexpr (ID < std::tuple_size_v<T>){
        single_print<ID>(t, os);
        all_print<ID + 1>(t, os);
    }
    else{
        os << '\n';
    }
    return;
}                                                  // print всех вершин

template<class T>
std::enable_if_t<is_figurelike_tuple_v<T>, void> print(const T& fake, std::ostream& os) {
    return all_print<0>(fake, os);
}

////////////////////////

template<class T, class = void>
struct has_center_metod : std::false_type {};  // не имеет метода center

template<class T>
struct has_center_metod<T, std::void_t<decltype(std::declval<const T>().center())>> : std::true_type {}; // имеет метод center

template<class T>
inline constexpr bool has_center_metod_v = has_center_metod<T>::value; // value для center

template<class T>
std::enable_if_t<has_center_metod_v<T>, vertex<double>> center(const T& figure) {
    return figure.center();                                            
}





#endif // D_TEMPLATES_H_
