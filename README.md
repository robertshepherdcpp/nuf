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

