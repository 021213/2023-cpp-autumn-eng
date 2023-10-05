#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstdlib>
#include<ctime>

int main(int argc, char** argv)
{
	srand(time(nullptr));
	int n = 0;
	scanf("%d", &n); //std::cin >> n;
	int* a = nullptr; //#define NULL nullptr
	a = (int*)malloc(sizeof(int) * n); //dynamic array in Pure C
	int i = 0;
	for (i = 0; i < n; ++i)
	{
		*(a + i) = rand() % 90 + 10; //*(a + i) == a[i]
	}
	for (i = 0; i < n; ++i)
	{
		printf("[%d]=%d ", a + i, *(a + i));
	}//%d int	%f float	%ld	long long	%lf double	%c char		%s string
	free(a);
	return 0;
}
