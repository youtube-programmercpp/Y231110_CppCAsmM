#pragma once
#include <ostream>
class String {
	friend std::ostream& operator<<(std::ostream& ostm, const String& r);
	char* s;
	static char* throw_bad_alloc_if_nullptr(char* s);
public:
	//コンストラクタ
	String() noexcept;
	//デストラクタ
	~String();

	String& operator+=(const char* t);//演算子のオーバーロード
	size_t Length() const noexcept;
	void CapitalizeFirstLetterIfPossible() noexcept;
	void Clear() noexcept;
};
