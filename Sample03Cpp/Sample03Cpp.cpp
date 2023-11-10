//仮想関数、基底クラス、派生クラス
// 基底クラスのメンバを仮想関数にして派生クラスでオーバーライドする
// 仮想関数は派生クラスにおける実装が呼び出される
#include "String_malloc.h"
#include "String_new.h"
#include <iostream>
void Test(String& s)
{
	s += "abc";
	s += "def";
	s += "ghi";
	const auto n = s.Length();
	std::cout << "length = " << n << std::endl;
	s.CapitalizeFirstLetterIfPossible();
	std::cout << "string = " << s << std::endl;
	s.Clear();
	s += "jkl";
	s += "mno";
	s += "pqr";
	std::cout << "new string = " << s << std::endl;
}
int main()
{
	String_malloc s1;
	String_new    s2;
	Test(s1);
	Test(s2);
}
