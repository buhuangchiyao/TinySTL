//模板类basic_string
#pragma once
#ifndef TINY_STL_BASIC_STRING_H_
#define TINY_STL_BASIC_STRING_H_
#include <cstddef>
#include "exceptedef.h"

namespace mystl
{
	/// <summary>
	/// char_traits模板类
	/// </summary>
	/// <typeparam name="T">模板类型</typeparam>
	template <typename T>
	struct char_traits
	{
		typedef T char_type;

		static size_t length(const char_type *str)
		{
			size_t len = 0;
			for (; *str != char_type(0); ++str)
				++len;
			return len;
		}

		static int compare(const char_type *s1, const char_type *s2, size_t n)
		{
			for (; n != 0; --n, ++s1, ++s2)
			{
				if (*s1 < *s2)
					return -1;
				if (*s2 < *s1)
					return 1;
			}
			return 0;
		}

		static char_type *copy(char_type *dst, const char_type *src, size_t n)
		{
			//判断指针是否会覆盖
			MY_DEBUG(src + n <= dst || dst + n <= src);
			char_type *r = dst;
			for (; n != 0; --n, ++dst, ++src)
				*dst = *src;
			return r;
		}

		static char_type *move(char_type *dst, const char_type * src, size_t n)
		{
			char_type *r = dst;
			if (dst < src)
			{
				for (; n != 0; --n, ++dst, ++src)
					*dst = *src;
			}
			else if (src < dst)
			{
				dst += n;
				src += n;
				for (; n != 0; --n)
					*--dst = *--src;
			}
			return r;
		}

		static char_type *fill(char_type *dst, char_type ch, size_t count)
		{
			char_type *r = dst;
			for (; count > 0; --count, ++dst)
				*dst = ch;
			return r;
		}
	};

	/// @brief Partialized char_traits<char>
	template <>
	struct char_traits<char>
	{
		typedef char char_type;

		static size_t length(const char_type *start) noexcept
		{
			auto end = start;
			while (*end != '\0')
				++end;
			return end - start;
		}

		static size_t compare(const char_type *s1, const char_type *s2, size_t len) noexcept
		{

			MYSTL_DEBUG(len>0);
			while(*s1 == *s2)
			{
				++s1;
				++s2;
			}

			return *s1 - *s2;
		}
	};
}

#endif // TINY_STL_BASIC_STRING_H_
