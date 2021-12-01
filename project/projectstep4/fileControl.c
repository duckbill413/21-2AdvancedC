#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_struct.h"
#include "my_define.h"
#include "my_func.h"
#pragma warning(disable:4996)

void ReqFromFile(TEL** pe, int* cnt, int max_num)
{
	FILE* fp = NULL;
	fp = fopen("PHONE_BOOK.txt", "r");//PHONE_BOOK.txt를 read한다.
	if (fp != NULL)//PHONE_BOOK.txt가 존재할 경우 실행
	{
		while (1)
		{
			if (*cnt >= max_num)//입력 개수 > max_num이 되려하면 OVERFLOW 출력과 함께 종료
			{
				printf("OVERFLOW\n");
				break;
			}
			char name[101] = { 0 }, phone[101] = { 0 }, birth[101] = { 0 };
			//자료를 임시로 입력 받을 배열 선언
			fscanf(fp, "%s %s %s", name, phone, birth);//파일로 부터 자료값을 읽어 온다.
			if (feof(fp))//입력 받은 자료가 없을 경우 종료
				break;

			*(pe + *cnt) = NULL;
			*(pe + *cnt) = (TEL*)malloc(sizeof(TEL)); //입력이 예정 되었으므로 동적할당 해준다.
			//결과적으로 입력된 개수만큼 동적할당이 이루어 진다. 입력개수<=max_num
			TEL* put = *(pe + *cnt);
			put->name = (char*)malloc(sizeof(char) * (strlen(name) + 1));
			put->phone = (char*)malloc(sizeof(char) * (strlen(phone) + 1));
			put->birth = (char*)malloc(sizeof(char) * (strlen(birth) + 1));
			//각 배열의 크기를 구하고 해당크기+1만큼 동적할당 한다.
			strcpy(put->name, name);
			strcpy(put->phone, phone);
			strcpy(put->birth, birth);
			//자료를 구조체에 복사한다.
			(*cnt)++;//입력 개수 +1
		}
		sort(pe, cnt);//입력받은 모든 자료를 정렬
		fclose(fp);//파일입출력 종료
	}
}

void saveFile(TEL** pe, int* cnt)//종료시 파일에 저장하는 함수
{
	FILE* fp = NULL;
	fp = fopen("PHONE_BOOK.txt", "w");//PHONE_BOOK.txt파일을 write모드로 연다
	if (fp != NULL)//파일 열시 성공시 실행
	{
		for (TEL** p = pe; p < pe + *cnt; p++)//구조체 정보를 파일에 입력
			fprintf(fp, "%s %s %s\n", (*p)->name, (*p)->phone, (*p)->birth);
	}
	fclose(fp);//파일입출력 종료
}