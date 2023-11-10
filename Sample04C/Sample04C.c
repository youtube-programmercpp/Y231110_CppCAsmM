#include <stdio.h>
int add_v1(int a, int b, int c, int d, int e, int f);
int add_v2(int a, int b, int c, int d, int e, int f);
int main()
{
	int a = 1;
	int b = 2;
	int c = 3;
	int d = 4;
	int e = 5;
	int f = 6;
	const int g = add_v1(a, b, c, d, e, f);
	const int h = add_v2(a, b, c, d, e, f);
	printf("g = %d\n", g);
	printf("h = %d\n", h);
}
