#include <stdio.h>
#include <stdlib.h>
#include <string>
#define _CRT_SECURE_NO_WARNINGS_

int main(void)
{
	int num;
	int *ap;
	int  i, j, res = 0;

	printf(">양수 입력 : ");
	scanf_s("%d", &num);
	ap = (int*)malloc((num-1) * sizeof(int));

	if (ap == NULL)
	{
		printf("메모리가 부족합니다!\n");
		exit(1);
	}
	for (i = 0; i < (num - 1); i++)
	{
		ap[i] = i + 2;
	}
	i = 0;

	while (1)
	{
		while ((ap[i] == 0) && (i < (num - 2)))
		{
			i++;
		}
		
		if (i == (num - 2))
			break;
		
		for (j = i + 1; j < (num - 1); j++)
		{
			if ((ap[j] % ap[i]) == 0)
			{
				ap[j] = 0;
			}
		}
		i++;
	}

	for (i = 0; i < (num - 1); i++)
	{
		if (ap[i] != 0) //입력값 내의 숫자가 소수일시 출력
		{
			printf("%3d", ap[i]);
		}

		else // 입력값 내의 숫자가 약분이 가능한 숫자일 경우 %c로 이용한 X로 표시
		{
			printf("%3c", 'X');
		}
		if ((i + 1) % 5 == 0)
		{
			printf("\n");
		}

	}
	free(ap);

	return 0;
}