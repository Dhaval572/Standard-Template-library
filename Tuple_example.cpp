// Tuple example in modern c++
#include <iostream>
#include <tuple>
using namespace std;

/*
    +---------------------+
    | Advantages of tuple |
    +---------------------+

    1. Supports heterogeneity: Can store different types together.

    2. Standardized and type-safe: Provided by STL, with full type checking.

    3. Decomposition support: Can be unpacked using std::tie() or structured bindings.

    4. Extensible: Easily used in templated or generic code.

    5. Comparison operators: Element-wise comparison is built-in.

    6. Type safety over C-style structs

    +-----------+
    | Use cases |
    +-----------+

    1. Returning Multiple Values from Functions

    2. Structured Bindings for Clean Unpacking

    3. Replacing std::pair for Complex Cases

    4. Compile-Time Data Processing

        Example:

            constexpr auto sizes = make_tuple(sizeof(int), sizeof(double), sizeof(char));
            static_assert(get<0>(sizes) == 4); // Compile-time check

*/

// Print all elements using lambda function
auto printTuple = [](const auto &tup)
{
    apply([](const auto &...args)
          { ((cout << args << '\n'), ...); },
          tup);
    cout << '\n';
};

int main()
{

    tuple<int, char, float> myTup(12, 'c', 234.34f);

    printTuple(myTup);

    // Access particular element with index
    cout << "At 0 index: " << get<0>(myTup) << '\n';
    cout << "At 2 index: " << get<2>(myTup) << '\n';

    // Easy way to creating tuple using structured blinding ( Same run time speed as normal tuple define )
    auto [x, y, z] = make_tuple(24, "str", 3.14f);
    cout << x << ", " << y << ", " << z << '\n';

    return 0;
}
