#include <stdio.h>

int passengerN(int);
void rebooking(int *);
int changeseat(int *);
//passengerN, rebooking, changeseat함수 선언
int main()
{
    int n;
    scanf("%d", &n);
    //승객수 입력
    int seat[21]; //좌석 배열 선언
    for (int *ps = seat; ps < seat + n; ps++)
        scanf("%d", ps);
    //seat의 포인터을 이용하여 seat에 값을 입력

    printf("%d\n", passengerN(n));
    //승객수n이 5미만이면 -1, 이상이면 0 출력
    if (passengerN(n) == -1)
        return 0;
    //승객수n이 5미만일 경우 -1을 호출하며 프로그램 종료

    rebooking(seat);
    //rebooking함수 실행
    for (int *ps = seat; ps < seat + n; ps++)
        printf("%d ", *ps);
    //좌석 배열을 승객수만큼 출력
    return 0;
}
void rebooking(int *ar)
{
    int found = 0; //먼저 찾을 중복된 수
    for (int *p = ar; p < ar + 21; p++)
    {                   //좌석은 최대 21개
        if (found == 0) //먼저 찾을 수 발견X
        {
            for (int *q = ar; q < p; q++)
            {                 //처음부터 p이전까지를 비교
                if (*q == *p) //p와 q의 값이 같다면 중복
                {
                    found = *p; //중복된 것에 대해 먼저 변환해 주어야 하므로 먼저 찾을 수 설정
                    *p = changeseat(ar);
                    break;
                    //중복일때 p의 값을 changeseat을 이용하여 최소값으로 변환 하고 다음 p값 비교
                }
            }
        }
        if (found != 0) //먼저 찾을 수가 있다면
        {
            for (int *z = p + 1; z < ar + 21; z++) //위에서 찾은 수 다음부터 끝까지
            {
                if (*z == found) //위와 동일한 수가 중복된 것에 대하여 먼저 변환해준다.
                {
                    *z = changeseat(ar); //중복된수에 changeseat로 새로운 값 입력
                }
            }
            found = 0; //찾는 수에 대하여 모두 입력하였으므로 found(찾는수)를 다시 0으로 설정
        }
    }
}

int passengerN(int n)
{
    if (n < 5 || n > 21)
        return -1; //승객수가 5미만 21초과
    else
        return 0; //승객수 5이상
}

int changeseat(int *ar)
{
    int seat = 1;                 //배치할 좌석 seat선언 및 초기화
    for (int i = 1; i <= 21; i++) //좌석은 1~21번까지 좌석 존재 작은 값 부터 확인
    {
        int found = 0;
        for (int *p = ar; p < ar + 21; p++)
        { //seat배열의 값과 i비교
            if (i == *p)
            {
                found = 1;
                break;
                //i==*p이면 i값이 존재하므로 사용불가 break하고 다음값 확인
            }
        }
        if (!found) //seat배열에 i값이 존재 하지 않는다. 즉, 사용 가능
        {
            seat = i;
            break;
            //seat에 i를 할당하고 원하는 값을 찾았으므로 for문 종료
        }
    }
    return seat; //찾은 seat를 리턴
}