#pragma once
#include "String.h"
class String_malloc :
    public String
{
	char* s;
	size_t n;
public:
	String_malloc() noexcept;
	~String_malloc();
	void Resize(size_t n) override;
	virtual char& Front() const noexcept override;
	virtual size_t Size() const noexcept override;
};

