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
            nuf::get_nth_element<I>(Ts...)();
        }

        template<auto I>
        constexpr auto get_n_return(nuf::index<I>)
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

        template<auto first_call, auto starting_value>
        struct lambda_wrapper
        {
            template<auto lambda, auto... lambdas>
            constexpr auto and_then()
            {
                if constexpr ((sizeof(lambdas) + ... + 0) != 0)
                {
                    return lambda_wrapper<lambda, starting_value>{}.and_then<lambdas...>().val_non_static;
                }
                else if constexpr ((sizeof(lambdas) + ... + 0) == 0)
                {
                    return lambda_wrapper<lambda, starting_value>{}.val_non_static;
                }
            }

            //static constexpr auto val = first_call<starting_value>();
            //decltype(first_call<starting_value>()) val_non_static = first_call<starting_value>();
        };

        template<auto I>
        constexpr auto pipe() -> decltype(auto)
        {
            // so we want to go through the lambdas calling each one with, could do something like.
            // lambda_wrapper<get_nth_element<0>(Ts...), I>{}.and_then<get_nth_element<indexes>(Ts...)>();
            return[&]<std::size_t... indexes>(std::index_sequence<indexes...>)
            {
                // return (get_nth_element<indexes>(Ts...)(I)...);
                return lambda_wrapper<get_nth_element<0>(Ts...), I>{}.and_then<get_nth_element<indexes>(Ts...)...>().val;
            }/*(std::make_index_sequence<sizeof...(Ts)>{})*/;
        }

        template<auto I>
        constexpr auto operator[](nuf::index<I>)
        {
            return nuf::get_nth_element<I>(Ts...);
        }
    };
} // namespace nuf