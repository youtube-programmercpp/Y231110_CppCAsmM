#pragma once
#include <ostream>
class String {
	friend std::ostream& operator<<(std::ostream& ostm, const String& r);
	char* s;
	static char* throw_bad_alloc_if_nullptr(char* s);
public:
	//�R���X�g���N�^
	String() noexcept;
	//�f�X�g���N�^
	~String();

	String& operator+=(const char* t);//���Z�q�̃I�[�o�[���[�h
	size_t Length() const noexcept;
	void CapitalizeFirstLetterIfPossible() noexcept;
	void Clear() noexcept;
};
