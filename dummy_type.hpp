#pragma once

namespace nuf
{
	struct dummy_type
	{
		int val{}; int value{};
		using type = int;
		auto get() { return value; }
	};
};