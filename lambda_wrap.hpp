#pragma once

namespace nuf
{
	template<auto lambda>
	struct lambda_wrap
	{
		constexpr auto and_then(auto& lamba_then)
		{
			return lambda_then(value);
		}

		static constexpr auto value = lambda();
	};
} // namespace nuf