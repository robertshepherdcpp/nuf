# nuf

nuf is a compile time library that has a few cute features.

--------------------------------------------------------------------------------------------------------------------------

### `nuf::index`
`nuf::index` is an easy way to pass things at compile time, for instance using the `operator[]` at compile time.
An example implementation of `nuf::index` is:
```C++
template<auto I>
struct index{};
```
--------------------------------------------------------------------------------------------------------------------------
### `nuf::inline_if`

`nuf::inline_if` is just if inline. It allows you to not have to make specializations of classes and much more. An example implementation of `nuf::inline_if` is as follows:
```C++
	template<auto value, auto lam_one, auto lam_two, auto val_one, auto val_two>
	struct inline_if
	{
		constexpr auto operator()()
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
```
So as you can see, you pass all the things as non type template parameters, and then call `operator()` in order to get the value. So an example use case of this would be as follows:
```C++
template<auto T>
struct x_or_y
{
  static constexpr auto value = inline_if<T, [](auto& x){return T == 42;}, [](auto& x){return T != 42;}, 'c', true>{}();
};

int main()
{
  static_assert(x_or_y<56>::value == true); // passes
}
```
