#include <stdio.h>
#include <stdlib.h>

int f(int n) 
{
	if (n == 1)
		return 1;
	if (n == 2)
		return 1;
	if (n == 3)
		return 2;
	if (n > 3)
		return f(n - 1) + f(n - 3);
}
#if defined(__MAIN_DEMO4__)
int main() 
{
	printf("%d\n", f(100));
	system("pause");
}
#endif