#include "my_func.h"

void searchBirth(TEL** pe, int* cnt)
{
	printf("Birth:");
	int tmp;
	scanf("%d", &tmp);//찾을 생일을 입력
	getchar();

	for (int i = 0; i < *cnt; i++)
	{
		int month = 0;
		for (char* search = pe[i]->birth + 4; search < pe[i]->birth + 6; search++)
			month = month * 10 + (*search - '0');//생일의 월이 있는 5,6번 문자를 이용하여 월 계산
		if (month == tmp)//생일인 월이 같을 경우 출력
			printf("%s %s %s\n", pe[i]->name, pe[i]->phone, pe[i]->birth);
	}
}