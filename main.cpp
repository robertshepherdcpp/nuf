#include"operation_stack.hpp"
#include"index.hpp"

#include<iostream> // std::cout

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
}