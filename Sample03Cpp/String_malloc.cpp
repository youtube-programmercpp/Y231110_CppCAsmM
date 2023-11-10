#include "String_malloc.h"
#include <new>

String_malloc::String_malloc() noexcept
	: s()
	, n()
{
}

String_malloc::~String_malloc()
{
	free(s);
}

void String_malloc::Resize(size_t n)
{
	if (const auto p = static_cast<char*>(realloc(s, n + 1))) {
		(s = p)[n] = '\0';
		this->n = n;
	}
	else
		throw std::bad_alloc();
}

char& String_malloc::Front() const noexcept
{
	return *s;
}

size_t String_malloc::Size() const noexcept
{
	return n;
}
