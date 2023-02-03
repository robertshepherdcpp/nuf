#pragma once

namespace nuf
{
    template<auto first_call, auto starting_value>
    struct lambda_variadic_wrapper
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

        template<auto... lambdas, auto I>
        constexpr auto skip_to()
        {
            return nuf::get_nth_element<I>(lambdas...)();
        }

        template<auto... lambdas>
        constexpr auto skip_to_end()
        {
            return nuf::get_nth_element<size - 1>(lambdas)();
        }

        constexpr auto size = (sizeof(lambdas) + ... + 0);

        static constexpr auto val = first_call<starting_value>();
        decltype(first_call<starting_value>()) val_non_static = first_call<starting_value>();
    };
} // namespace nuf