//
//  comparable-printable.hpp
//  data-structures-and-algorithms
//
//  Created by Benjamin Dixon on 4/2/24.
//

#ifndef comparable_printable_hpp
#define comparable_printable_hpp

template <typename T>
concept Comparable = requires(T a, T b) {
    a < b;
    a <= b;
    a > b;
    a >= b;
    a == b;
};

template <typename T>
concept Printable = requires(std::ostream& os, T a) {
    os << a;
};

template <typename T>
concept ComparableAndPrintable = Comparable<T> && Printable<T>;

#endif /* comparable_printable_hpp */
