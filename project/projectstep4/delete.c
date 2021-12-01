#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_struct.h"
#include "my_define.h"
#include "my_func.h"
#pragma warning(disable:4996)

void delete (TEL** pe, int* cnt)
{
	if (*cnt == 0) //저장된 정보가 없을때
		printf("NO MEMBER\n");
	else
	{
		printf("Name:"); // 고정
		char tmp[21];
		scanf("%s", tmp);//삭제할 이름 입력
		getchar();

		int found = 0;
		TEL** p;
		for (p = pe; p < pe + *cnt; p++)
		{
			if (!strcmp((*p)->name, tmp))//삭제할 이름과 동일 인물 발견
			{
				found = 1;//동일인물 발견시 found = 1
				break;
			}
		}

		if (found)//동일인물 발견시 실행
		{
			for (TEL** q = p; q < pe + *cnt - 1; q++)//마지막 전의 항까지 실행
			{
				(*q)->name = (char*)realloc((*q)->name, sizeof(char) * (strlen((*(q + 1))->name) + 1));
				(*q)->phone = (char*)realloc((*q)->phone, sizeof(char) * (strlen((*(q + 1))->phone) + 1));
				(*q)->birth = (char*)realloc((*q)->birth, sizeof(char) * (strlen((*(q + 1))->birth) + 1));
				//자료 입력을 위하여 다음 항의 크기만큼 크기를 재할당 해준다.
				strcpy((*q)->name, (*(q + 1))->name);
				strcpy((*q)->phone, (*(q + 1))->phone);
				strcpy((*q)->birth, (*(q + 1))->birth);
				//다음항의 자료를 복사해 온다.
			}
			(*cnt)--;
			free(pe[*cnt]->name);
			free(pe[*cnt]->phone);
			free(pe[*cnt]->birth);
			free(pe[*cnt]);
			//마지막 항의 구조체와 그 멤버를 동적할당 해제하여 준다.
		}
	}
}