#ifndef MY_FUNC_H
#define MY_FUNC_H
void insert(TEL** pe, int* cnt, int max_num);//�ڷ� �Է�
void sort(TEL** pe, int* cnt);//�ڷ� ����
void show(TEL** pe, int* cnt);//��� �ڷ� ���
void delete (TEL** pe, int* cnt);//��ġ�ϴ� �̸��� �ڷ� ����
void searchBirth(TEL** pe, int* cnt);//��ġ�ϴ� ���� �ڷ� ���
void ReqFromFile(TEL** pe, int* cnt, int max_num);//���Ϸ� ���� �ڷ� �Է�
void saveFile(TEL** pe, int* cnt);//���Ͽ� �ڷ� �Է�
#endif // !MY_FUNC_H
