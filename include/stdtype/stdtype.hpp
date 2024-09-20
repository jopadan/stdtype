#pragma once
#include <cstdlib>
#include <cstdint>
#include <cstdio>
#include <cstddef>
#include <ctime>
#include <vector>
#include <array>
#include <iostream>
#include <filesystem>
#include <bit>
#include <algorithm>

template<typename T>
concept scalar = std::integral<T> || std::floating_point<T>;

template<typename T, size_t N>
using arr = std::conditional_t<N == 1, T, T[N]>;
template<typename T, size_t N, size_t NP2 = std::bit_ceil<size_t>(N)>
using vec __attribute__((vector_size(sizeof(T) * NP2))) = T;
template<scalar T, size_t N>
using type = std::conditional_t<N == 1, T, std::conditional_t<(std::popcount<size_t>(N) == 1), vec<T,N>, arr<T,N>>>;

template<size_t N = 1>
using u8 = type<uint8_t, N>;
template<size_t N = 1>
using i8 = type<int8_t, N>;
template<size_t N = 1>
using s8 = type<signed int8_t, N>;

template<size_t N = 1>
using u16 = type<uint16_t, N>;
template<size_t N = 1>
using i16 = type<int16_t, N>;
template<size_t N = 1>
using s16 = type<signed int16_t, N>;

template<size_t N = 1>
using u32 = type<uint32_t, N>;
template<size_t N = 1>
using i32 = type<int32_t, N>;
template<size_t N = 1>
using s32 = type<signed int32_t, N>;

template<size_t N = 1>
using u64 = type<uint64_t, N>;
template<size_t N = 1>
using i64 = type<int64_t, N>;
template<size_t N = 1>
using s64 = type<signed int64_t, N>;

template<size_t N = 1>
using t32 = type<int32_t, N>;
template<size_t N = 1>
using t64 = type<int64_t, N>;

template<size_t N = 1>
using c32 = type<char32_t, N>;
template<size_t N = 1>
using c16 = type<char16_t, N>;
template<size_t N = 1>
using c8 = arr<char, N>;

using buf = uint8_t*;
using str = char*;

