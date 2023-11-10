#include "String_new.h"

String_new::String_new() noexcept
	: s()
	, n()
{
}

String_new::~String_new()
{
	delete[] s;
}

void String_new::Resize(size_t n)
{
	const auto p = new char[n + 1];
	p[n] = '\0';
	delete[] s;
	s = p;
}

char& String_new::Front() const noexcept
{
	return *s;
}

size_t String_new::Size() const noexcept
{
	return n;
}
