#include <stdio.h>
#include <stdlib.h>
#include <string>
#define _CRT_SECURE_NO_WARNINGS_

int main(void)
{
	int num;
	int *ap;
	int  i, j, res = 0;

	printf(">��� �Է� : ");
	scanf_s("%d", &num);
	ap = (int*)malloc((num-1) * sizeof(int));

	if (ap == NULL)
	{
		printf("�޸𸮰� �����մϴ�!\n");
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
		if (ap[i] != 0) //�Է°� ���� ���ڰ� �Ҽ��Ͻ� ���
		{
			printf("%3d", ap[i]);
		}

		else // �Է°� ���� ���ڰ� ����� ������ ������ ��� %c�� �̿��� X�� ǥ��
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