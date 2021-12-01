#include <stdio.h>
#include <stdlib.h>
#include "my_struct.h"
#include "my_define.h"
#include "my_func.h"
#pragma warning(disable:4996)

int main()
{
	int max_num;
	printf("Max_num:"); // 고정
	scanf("%d", &max_num);

	TEL** pe = NULL;                              // 이중 포인터 구조체
	pe = (TEL**)malloc(sizeof(TEL*) * max_num); // max_num의 개수만큼 동적할당
	if (pe == NULL)
		return -1;
	//안내 인터페이스

	int select;
	int cnt = 0;      //전체 인원수 변수
	int maintain = 1; // while문 반복을 위한 변수
	while (maintain)
	{
		printf("*****Menu*****\n");
		printf("<1.Registration><2.ShowAll><3.Delete><4.FindByBirth><5.ReqFromFile><6.Exit>\n");
		printf("Enter_the_menu_number:");
		scanf("%d", &select);
		getchar();

		switch (select)
		{
		case 1:
			insert(pe, &cnt, max_num); //1. Registration
			break;
		case 2:
			show(pe, &cnt);//2. ShowAll
			break;
		case 3:
			delete (pe, &cnt);//3. Delete
			break;
		case 4:
			searchBirth(pe, &cnt);//4. FindByBirth
			break;
		case 5:
			ReqFromFile(pe, &cnt, max_num);//5. ReqFromFile
			break;
		case 6:
			saveFile(pe, &cnt);//6. Exit
			maintain = 0;
			break;
		}
	}

	for (int i = 0; i < cnt; i++) //각 정보에 대하여 동적할당 해제
	{
		free(pe[i]->name);
		free(pe[i]->birth);
		free(pe[i]->phone);
		free(pe[i]);
	}
	free(pe); // max_num 개수만큼 할당한 것에 대하여 동적할당 해제
}