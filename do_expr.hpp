// do_expr.hpp
#pragma once

namespace nuf
{
    template<auto lambda, auto... exprs>
    struct do_expr_
    {
        static constexpr auto value = lambda(exprs...);
    };

    template<auto lambda>
    struct do_expr_<lambda>
    {
        static constexpr auto value = lambda();
    };

    template<auto lambda, auto... exprs>
    static constexpr auto do_expr = do_expr_<lambda, exprs...>{}.value;

    template<typename T>
    constexpr auto default_value = T{};
} // namespace nuf