#include "String.h"
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <new>
String::~String()
{
}
String& String::operator+=(const char* t)
{
	if (const auto a = Size()) {
		const auto b = strlen(t);
		const auto c = a + b;
		Resize(c);
		memcpy(&Front() + a, t, b);
	}
	else {
		const auto n = strlen(t);
		Resize(n);
		memcpy(&Front(), t, n);
	}
	return *this;
}
size_t String::Length() const noexcept
{
	return Size();
}

void String::CapitalizeFirstLetterIfPossible() noexcept
{
	if (Size()) {
		auto& r = Front();
		r = toupper(r);//æ“ª‚Ì•¶š‚ğ‘å•¶š‚É•ÏŠ·‚·‚éi‰Â”\‚Å‚ ‚ê‚Îj
	}
}

void String::Clear() noexcept
{
	Resize(0);
}
std::ostream& operator<<(std::ostream& ostm, const String& r)
{
	if (r.Size())
		ostm << &r.Front();
	return ostm;
}

