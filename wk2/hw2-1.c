#include <stdio.h>

int passengerN(int); //승객수 확인
int checking(int *, int *);
//중복 값이 있는지 확인하기 위한 함수
int main()
{
    int n;
    scanf("%d", &n);
    //승객수 입력
    int seat[21] = {0};
    //좌석 배열 선언 및 초기화
    for (int *ps = seat; ps < seat + n; ps++)
        scanf("%d", ps);
    //seat의 포인터를 이용하여 seat배열에 값입력

    if (passengerN(n) == -1) //승객수가 5미만일 경우
    {
        printf("%d\n", passengerN(n)); //-1출력하고 프로그램 종료
        return 0;
    }
    int found = 0; //중복값 존재 확인

    int fseat[21] = {0};
    int *pfseat = fseat;
    //중복되는 값은 한번 출력하면 출력할 필요가 없기 때문에 저장해 놓기 위한 배열

    for (int *ps = seat; ps < seat + n; ps++)
    {
        if (checking(fseat, ps) >= 1)
            continue;
        //앞에서 확인한 값인지 체크한다 1이상이면 앞에서 확인
        if (checking(seat, ps) > 1) //seat배열에 대해서 *ps의 값이 2개 이상이면 중복됨
        {
            found = 1;                                  //중복값이 존재 했으므로 found = 1
            printf("%d %d\n", *ps, checking(seat, ps)); //중복된 값과 횟수를 출력
            *pfseat++ = *ps;                            //확인한 값 배열에 *ps값을 입력시킴
        }
    }

    if (!found) //중복된 적이 없다면 0출력
        printf("0");

    return 0;
}
int checking(int *s, int *check) //확인할 배열과 값을 인자로 사용
{
    int cnt = 0;
    for (int *p = s; p < s + 21; p++)
    {
        if (*p == *check) //확인할 값이 배열에서 몇번 사용되었는지 확인
            cnt++;        //중복되면 cnt값을 올림
    }
    return cnt; //중복횟수 반환
}
int passengerN(int n)
{
    if (n < 5 || n > 21) //승객수가 5미만 21초과 이면 -1반환
        return -1;
    else //이외는 0반환
        return 0;
}