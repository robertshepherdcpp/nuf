#pragma once

namespace nuf
{
	template<auto value, auto lam_one, auto lam_two, auto val_one, auto val_two>
	struct inline_if
	{
		auto operator()()
		{
			if constexpr (lam_one(value))
			{
				return val_one;
			}
			else if constexpr (lam_two(value))
			{
				return val_two;
			}
		}
	};
} // namespace nuf