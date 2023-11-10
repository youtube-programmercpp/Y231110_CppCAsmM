//クラス・構造体・共用体
// 関数をクラス内に含めることができる。
// クラスと同じ名前の関数はコンストラクタ…インスタンス化の際に自動的に呼び出される
// クラス名に~を前置した名前の関数はデストラクタ…破棄の際に自動的に呼び出される
#include "String.h"
#include <iostream>
int main()
{
	String s;
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
