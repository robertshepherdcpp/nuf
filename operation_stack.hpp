#pragma once

#include"get_nth_element.hpp"
#include"index.hpp"

#include<tuple>

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

        constexpr auto get_all_returns()
        {
            auto tuple_lambdas = std::make_tuple(Ts...);
            return [&] <std::size_t... indexes>(std::index_sequence<indexes...>)
            {
                // return std::tuple{(nuf::get_nth_element<indexes>(Ts)())...};
                return std::tuple{(std::get<indexes>(tuple_lambdas)())...};
            }(std::make_index_sequence < sizeof...(Ts)>{});
        }
    };
} // namespace nuf