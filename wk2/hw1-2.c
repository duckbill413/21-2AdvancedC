#include <stdio.h>

int *MAX(int *);
int *MIN(int *);
//주소값을 반환하는 int형 함수 MAX, MIN 선언

int main()
{
    int n;
    scanf("%d", &n);
    //n번 반복할 정수를 선언하고 입력
    int *par;
    //ar의 배열 포인터 선언
    for (int i = 0; i < n; i++) //n번 반복
    {
        int ar[100] = {0}; //크기가 100인 배열 ar선언 및 초기화
        for (par = ar; par < ar + 100; par++)
        {                     //배열 포인터를 배열 주소 ar로 초기화 해주며 ar의 크기가 100이므로 ar+100
            scanf("%d", par); //배열 포인터 par을 이용하여 ar배열에 값을 입력
            if (*par == 0)
                break;
            //값이 0이 들어오면 중지
        }
        int *big, *small;
        //중간 주소 크기를 확인하기 위해 포인터 big, small 선언
        if (MIN(ar) < MAX(ar)) //MAX의 주소가 MIN보다 클떄
        {
            small = MIN(ar);
            big = MAX(ar);
            //small에 MIN주소 big에 MAX주소
        }
        else //MIN의 주소가 MAX보다 크거나 같을때
        {
            small = MAX(ar);
            big = MIN(ar);
            //small에 MAX주소 big에 MIN주소
        }
        int found = 0;
        //화면에 출력된 정수가 있는지 확인용
        for (int *p = small + 1; p < big; p++)
        {                      //MIN과 MAX사이의 정수를 출력해야 하므로 small+1과 big보다 하나 작은 주소
            found = 1;         //출력한 정수가 있으므로 found=1로 변환
            printf("%d ", *p); //사이의 정수 출력
        }
        if (!found) //found=0이면 출력된 정수가 없음
            printf("none\n");
        printf("\n");
    }
    return 0;
}

int *MAX(int *ar) //MAX 포인터 함수
{
    int max, *pmax; //최대값의 크기와 주소를 입력 받기 위한 정수 및 포인터 선언
    for (int *par = ar; par < ar + 100; par++)
    { //배열 ar의 주소를 입력 받고 그 크기를 범위로 줌
        if (*par == 0)
            break;
        //*par이 0이면 끝이므로 종료
        if (max < *par || par == ar) //max보다 *par이 크거나 처음일 경우
        {
            max = *par;
            pmax = par;
            //max에 *par, pmax에 par 주소 입력
        }
    }
    return pmax; //최댓값의 주소 리턴
}

int *MIN(int *ar) //MIN 포인터 함수
{
    int min, *pmin; //최솟값의 크기와 주소를 입력 받기 위한 정수 및 포인터 선언
    for (int *par = ar; par < ar + 100; par++)
    { //배열 ar의 주소를 입력 받고 그 크기를 범위로 줌
        if (*par == 0)
            break;
        //*par이 0이면 끝이므로 종료
        if (min > *par || par == ar) //min보다 *par이 작거나 처음일 경우
        {
            min = *par;
            pmin = par;
            //min에 *par, pmin에 par 주소 입력
        }
    }
    return pmin; //최솟값의 주소 리턴
}