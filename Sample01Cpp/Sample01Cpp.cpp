// 名前修飾（Name mangling）
// -----------------------
// 一意性を高めるために元の名前（識別子）を修飾する
// どのように修飾するかはコンパイラが定める（あるいは採用する）特定の規則による
double div(double a, double b);//実数の割り算 ?div@@YANNN@Z

// 名前空間 (Namespace)
// --------------------
// 名前の衝突（conflict）を防止する仕組み
// 引数の仕様が同じであれば同名の関数を定義することは不可
// しかし、別の名前空間内に収容すれば問題は起きない
namespace A {
	int    div(int    a, int    b);//整数の割り算 ?div@A@@YAHHH@Z
}
namespace B {
	int    div(int    a, int    b);//整数の割り算 ?div@B@@YAHHH@Z
}
#include <iostream>
int main()
{
	const auto x = A::div(3 , 2 ); // 3   ÷ 2   → 1    (1.5ではない)
	const auto y = B::div(3 , 2 ); // 3   ÷ 2   → 1    (1.5ではない)
	const auto z =    div(3., 2.); // 3.0 ÷ 2.0 → 1.5 
	std::cout
		<< "x = " << x << '\n'
		<< "y = " << y << '\n'
		<< "z = " << z << '\n'
		;
}
