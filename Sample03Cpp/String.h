#pragma once
#include <ostream>
class String
{
	friend std::ostream& operator<<(std::ostream& ostm, const String& r);
public:
	//�f�X�g���N�^
	virtual ~String(); //���z�f�X�g���N�^

	String& operator+=(const char* t);
	size_t Length() const noexcept;
	void CapitalizeFirstLetterIfPossible() noexcept;
	void Clear() noexcept;

	virtual size_t Size() const noexcept = 0;
	virtual char& Front() const noexcept = 0;
	virtual void Resize(size_t n) = 0; //���z�֐�
};

