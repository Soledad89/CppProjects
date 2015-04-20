#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

int strmatch(const char *, const char *);

int main()
{
	const char s1[] = "tops";
	const char s2[] = "stop";
	if (strmatch(s1, s2))
		printf("Match Success!");
	return 0;
}

int strmatch(const char *s1,const char *s2)
{
	int i, len1, len2;
	int s[26];

	memset(s, 0, sizeof(s));
	len1 = strlen(s1);
	len2 = strlen(s2);
	if (len1 <= 0 || len2 <= 0 || len1 != len2)
	{
		printf("Match fails");
		return FALSE;
	}
	for (i = 0; i < len1; i++)
		s[s1[i] - 'a'] ++;
	for (i = 0; i < len2; i++)
		s[s2[i] - 'a'] --;
	for (i = 0; i < 26; i++)
		if ( s[i] != 0)
		{
			printf("Match fails");
			return FALSE;
		}
	return TRUE;
}


