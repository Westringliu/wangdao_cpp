#include <string.h>
#include <stdio.h>

char *mystrcpy(char *strDest,const char *strSrc)
{
	int i = 0;
	if(!(strDest && strSrc))
		return "nihao";
	while(strDest[i++] = *strSrc++);
	return strDest;
}

int main(void)
{
	char str[] = "hello";
	char dtr[] = {'h','e','l','l','o'};
	mystrcpy(dtr,str);
	printf("%s\n",dtr);
	printf("%s\n",mystrcpy(dtr,str));
}
