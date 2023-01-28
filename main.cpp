#include"operation_stack.hpp"
#include"index.hpp"

#include<iostream> // std::cout
#include<tuple>    // std::tuple

int main()
{
    nuf::operation_stack <
        []() {std::cout << "Hello World"; },
        []() {std::cout << ".\n"; }
    > Hello_World{};

    // prints "Hello World.\n"
    Hello_World.invoke_all();

    // prints "Hello World"
    Hello_World.invoke(nuf::index<0>{});

    nuf::operation_stack<
        []() {return 56; },
        []() {return 3.142; },
        []() {return 'c'; },
        []() {return true; }
    > return_types{};

    auto x = return_types.get_all_returns();
    std::cout << "\n" << std::get<2>(x) << "\n";
}