#include <stdio.h>

//Fuck this test


char *f1(char *s1, const char *s2)
{
	char *p = s1;
	while(*p) p++;
	while(*p++ = *s2++) ;
	printf("%c", *s1);
	return s1;
}

char *f2(char *s1, const char *s2)
{
	char *p = s1;
	while(*p) p++;
	*p = *s2;
	while(*++p = *++s2);
	printf("%c", *s1);
	return s1;
}

void main(void)
{


	
	char s1 = 'a'; 
	const char s2 = 'b';
	//f1(&s1, &s2);
	f2(&s1, &s2);
	printf("%c", s1);
	printf("Hello world");
	
	return;
}