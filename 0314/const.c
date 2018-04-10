#include <stdio.h>


char *GetMemory(void)
{
	char p[] = "hello ,world";
	return p;
}

void test(void)
{
	char *str = NULL;
	str = GetMemory();
	printf("%s\n",str);
}

int main(void)
{
	test();
}
