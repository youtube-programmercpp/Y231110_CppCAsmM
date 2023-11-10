#pragma once
#include "String.h"
class String_new :
    public String
{
	char* s;
	size_t n;
public:
	String_new() noexcept;
	~String_new() override;
	void Resize(size_t n) override;
	virtual char& Front() const noexcept override;
	virtual size_t Size() const noexcept override;
};
