#include <stdio.h>

// Macros
#define subm(a,b) (a-b)
#define cubem(a) (a*a*a)
#define minm(a,b) (a<b?a:b)
#define oddm(a) (a%2==0?0:1)

// Functions
int subf(int a, int b) {
	return a - b;
}
int cubef(int a) {
	return a * a * a;
}
int minf(int a, int b) {
	if (a <= b) {
		return a;
	}
	else {
		return b;
	}
}
int oddf(int a) {
	if (a % 2 == 1) {
		return 1;
	}
	else {
		return 0;
	}
}
int main()
{
	int a = 3, b = 6;
	printf("subf(a,b) = %d\n", subf(a, b));
	printf("subm(a,b) = %d\n", subm(a, b));
	printf("subf(a++,b--) = %d\n", subf(a++, b--));
	a = 3; b = 6;
	printf("subm(a++,b--) = %d\n", subm(a++, b--));
	a = 3; b = 6;
	printf("cubef(a) = %d\n", cubef(a));
	printf("cubem(a) = %d\n", cubem(a));
	printf("cubef(--a) = %d\n", cubef(--a));
	a = 3; b = 6;
	printf("cubem(--a) = %d\n", cubem(--a));
	a = 3; b = 6;
	printf("minf(a,b) = %d\n", minf(a, b));
	printf("minm(a,b) = %d\n", minm(a, b));
	printf("minf(--a,--b) = %d\n", minf(--a, --b));
	a = 3; b = 6;
	printf("minm(--a,--b) = %d\n", minm(--a, --b));
	a = 2; b = 6;
	printf("oddf(a) = %d\n", oddf(a));
	printf("oddm(a) = %d\n", oddm(a));
	printf("oddf(a++) = %d\n", oddf(a++));
	a = 2; b = 6;
	printf("oddm(a++) = %d\n", oddm(a++));

	return 0;
}