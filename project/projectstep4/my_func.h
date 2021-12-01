#ifndef MY_FUNC_H
#define MY_FUNC_H
void insert(TEL** pe, int* cnt, int max_num);//자료 입력
void sort(TEL** pe, int* cnt);//자료 정렬
void show(TEL** pe, int* cnt);//모든 자료 출력
void delete (TEL** pe, int* cnt);//일치하는 이름의 자료 삭제
void searchBirth(TEL** pe, int* cnt);//일치하는 월의 자료 출력
void ReqFromFile(TEL** pe, int* cnt, int max_num);//파일로 부터 자료 입력
void saveFile(TEL** pe, int* cnt);//파일에 자료 입력
#endif // !MY_FUNC_H
