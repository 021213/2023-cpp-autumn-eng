#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstdlib>
#include<cstring>

#define LEN 256

int main(int argc, char** argv)
{
	char str2[LEN];
	char* str1 = (char*)malloc(LEN * sizeof(char));

	scanf("%s", str1);
	gets_s(str2);

	printf("str1 = %s\nstr2 = %s\n", str1, str2);

	char str3[LEN] = "";
	strcat(str3, str1);
	strcat(str3, str2);
	printf("str3 = %s\n", str3);

	char* str4 = (char*)malloc(LEN * sizeof(char));
	str4[0] = '\0';
	printf("str4 = %s\n", strcat(strcat(strcat(strcat(str4, str1), str2), " : "), str3));

	/*count words in string*/
	printf("\ncount spaces in \"%s\"\n", str4);
	char* start = str4;
	char* end;
	char word[LEN];
	int count = -1;
	do
	{
		if (start != str4) ++start;
		char* end = strstr(start, " ");
		strcpy(word, start);
		if (end != nullptr) word[end - start] = '\0';
		start = end;
		++count;
		printf("\tword : %s\n", word);
	} while (start != nullptr);
	printf("count of spaces : %d\n\n", count);
	// strstr
	// strcat
	// strcpy
	// strcmp

	strcpy(str1, "bba");
	strcpy(str2, "bbf");
	printf("compare \"%s\" to \"%s\"\n%d\n\n", str1, str2, strcmp(str1, str2));

	strcpy(str1, "eee");
	strcpy(str2, "bbb");
	printf("compare \"%s\" to \"%s\"\n%d\n\n", str1, str2, strcmp(str1, str2));

	strcpy(str1, "banana");
	strcpy(str2, "banana");
	printf("compare \"%s\" to \"%s\"\n%d\n\n", str1, str2, strcmp(str1, str2));

	free(str1);
	free(str4);

	return 0;
}