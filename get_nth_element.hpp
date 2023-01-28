#pragma once

#include<utility>
#include<cstddef>

namespace nuf
{
    template<auto I>
    constexpr auto get_nth_element(auto... args)
    {
        return[&]<std::size_t... Indexes>(std::index_sequence<Indexes...>) {
            return [](decltype((void*)Indexes)... DontCare, auto* arg,
                auto *...DontCareEither) constexpr { return *arg; }(&args...);
        }(std::make_index_sequence<I>{});
    }
} // namespace nuf