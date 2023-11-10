#include "String.h"
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <new>
char* String::throw_bad_alloc_if_nullptr(char* s)
{
	
	if (s)                      // if (s != nullptr) �Ɠ���
		return s;               // s ���� nullptr �Ȃ� s ��Ԃ�
	else
		throw std::bad_alloc(); // s �� nullptr �Ȃ� std::bad_alloc ��O�𓊓�����
}

String::String() noexcept
	: s() //�����o�ϐ��̏������c s(nullptr) �Ƃ�������, s{} �� s{nullptr} �ł��ǂ�
{
}
String::~String()
{
	free(s); //�f�X�g���N�^�ŕ�������������ifree �� nullptr �ɑ΂��Ă����s�\�̂��� if ���͏ȗ������j
}
String& String::operator+=(const char* t)
{
	if (s) {
		const auto a = strlen(s); // ����̕����񒷂� a �ɐݒ�
		const auto b = strlen(t); // �ǉ��̕����񒷂� b �ɐݒ�
		const auto c = a + b;     // ���v�̕����񒷂� c �ɐݒ�
		s = throw_bad_alloc_if_nullptr(static_cast<char*>(realloc(s, c + 1))); //s �̗̈�� c + 1 �Ɋg��
		memcpy(&s[a], t, b);      // s �̌㔼������ t �̓��e���R�s�[
		s[c] = '\0';              // s �̖����� Null ������ݒ�
	}
	else
		s = throw_bad_alloc_if_nullptr(_strdup(t)); // s �� nullptr �Ȃ̂� _strdup �ŕ����������ʂ� s �ɐݒ�
	return *this;                 // ���I�u�W�F�N�g�ւ̎Q�Ƃ�Ԃ��i+= ���Z�q�Ƃ��ď펯�I�Ȏd�l�j
}
size_t String::Length() const noexcept
{
	if (s)
		return strlen(s);// strlen �֐����Ăяo���A�߂�l�����̂܂ܕԂ��B
	else
		return {};       //�� return size_t{}; �� return size_t(); �� return 0;
}

void String::CapitalizeFirstLetterIfPossible() noexcept
{
	if (s)
		*s = toupper(*s);//�擪�̕�����啶���ɕϊ�����i�\�ł���΁j
}

void String::Clear() noexcept
{
	if (s) {
		free(s);         //�����������
		s = nullptr;     //s��nullptr��ݒ�is = {}; �Ƃ�������j
	}
}
std::ostream& operator<<(std::ostream& ostm, const String& r)
{
	if (r.s)
		ostm << r.s;
	return ostm;
}

