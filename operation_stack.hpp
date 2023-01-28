#pragma once

#include"get_nth_element.hpp"
#include"index.hpp"

namespace nuf
{
    template<auto... Ts>
    struct operation_stack
    {
        constexpr operation_stack() {/*Doesn't do anything*/ }

        constexpr auto invoke_all()
        {
            (..., Ts()); // doesn't return anything
        }

        template<auto I>
        constexpr auto invoke(nuf::index<I>)
        {
            return nuf::get_nth_element<I>(Ts...)();
        }
    };
} // namespace nuf