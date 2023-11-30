#include <stdio.h>
#include <string.h>


void swap(const char *type, void *ap, void *cp);

int main(void)
{
	int age1, age2;
	double cm1, cm2;
	
	printf("첫 번째 사람의 나이와 키 입력 : ");
	scanf_s("%d %lf", &age1, &cm1);
	
	printf("두 번째 사람의 나이와 키 입력 : ");
	scanf_s("%d %lf", &age2, &cm2);

	swap("int", &age1, &age2);
	swap("double", &cm1, &cm2);

	printf("첫 번째 사람의 나이와 키 : %d, %.1lf\n", age2, cm2);
	printf("두 번째 사람의 나이와 키 : %d, %.1lf\n", age1, cm1);

	return 0;
}

void swap(const char *type, void* ap, void* cp)	//
{
	int temp;
	double ctemp;

	if (strcmp(type, "int") == 0)
	{
		temp = *(int*)ap;
		*(int*)ap = *(int*)cp;
		*(int*)cp = temp;
	}

	if (strcmp(type, "double") == 0)
	{
		ctemp = *(double*)ap;
			*(double*)ap = *(double*)cp;
			*(double*)cp = ctemp;
	}
}

