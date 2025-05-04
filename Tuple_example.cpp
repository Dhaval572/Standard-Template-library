// About example in modern c++
#include <iostream>
#include <tuple>
using namespace std;

// Print all elements using lambda function
auto printTuple = [](const auto &tup)
{
    apply([](const auto &...args)
          {
              ((cout << args << '\n'), ...); 
          },
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
