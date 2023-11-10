#include "String.h"
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <new>
char* String::throw_bad_alloc_if_nullptr(char* s)
{
	
	if (s)                      // if (s != nullptr) と同じ
		return s;               // s が非 nullptr なら s を返す
	else
		throw std::bad_alloc(); // s が nullptr なら std::bad_alloc 例外を投入する
}

String::String() noexcept
	: s() //メンバ変数の初期化… s(nullptr) とも書ける, s{} や s{nullptr} でも良い
{
}
String::~String()
{
	free(s); //デストラクタで文字列を解放する（free は nullptr に対しても実行可能のため if 文は省略した）
}
String& String::operator+=(const char* t)
{
	if (s) {
		const auto a = strlen(s); // 現状の文字列長を a に設定
		const auto b = strlen(t); // 追加の文字列長を b に設定
		const auto c = a + b;     // 合計の文字列長を c に設定
		s = throw_bad_alloc_if_nullptr(static_cast<char*>(realloc(s, c + 1))); //s の領域を c + 1 に拡大
		memcpy(&s[a], t, b);      // s の後半部分に t の内容をコピー
		s[c] = '\0';              // s の末尾に Null 文字を設定
	}
	else
		s = throw_bad_alloc_if_nullptr(_strdup(t)); // s は nullptr なので _strdup で複製した結果を s に設定
	return *this;                 // 当オブジェクトへの参照を返す（+= 演算子として常識的な仕様）
}
size_t String::Length() const noexcept
{
	if (s)
		return strlen(s);// strlen 関数を呼び出し、戻り値をそのまま返す。
	else
		return {};       //← return size_t{}; ← return size_t(); ← return 0;
}

void String::CapitalizeFirstLetterIfPossible() noexcept
{
	if (s)
		*s = toupper(*s);//先頭の文字を大文字に変換する（可能であれば）
}

void String::Clear() noexcept
{
	if (s) {
		free(s);         //メモリを解放
		s = nullptr;     //sにnullptrを設定（s = {}; とも書ける）
	}
}
std::ostream& operator<<(std::ostream& ostm, const String& r)
{
	if (r.s)
		ostm << r.s;
	return ostm;
}

