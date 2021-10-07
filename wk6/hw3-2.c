#include <stdio.h>
#include <string.h>

struct hotel_info
{
    char name[31];//호텔 이름
    int grade;//등급
    double score;//평판도
    double range;//거리
    char food;//조식여부
};

int in_hotel_info(struct hotel_info *p);
//호텔의 이름, 등급, 평판도, 거리, 조식포함여부를 사용자로부터 입력 받아 배열에 저장
void out_hotel_info(struct hotel_info *p, int N, int G, double D);
//배열에 저장된 호텔 중 G 이상의 등급과 D 이하의 거리를 갖는 호텔을 검색하여, 이 중 평판도가 가장 높은 호텔의 정보를 화면에 출력

int main()
{
    struct hotel_info hi[100];//초대 100개의 호텔
    int num = in_hotel_info(hi);//호텔 정보를 입력 받고 num에 호텔의 수 입력
    int G;
    double D;
    scanf("%d %lf", &G, &D);//사용자로부터 등급과 거리를 입력 받는다.

    out_hotel_info(hi, num, G, D);//조건에 맞는 호텔을 검색하고 출력

    return 0;
}

int in_hotel_info(struct hotel_info *p)
{
    struct hotel_info *hi;
    for (hi = p;; hi++)
    {
        scanf("%s", hi->name);//hi를 통해 호텔 이름 입력
        if (!strncmp(hi->name, "0", 1))//호텔이름이 0이면 종료
            break;
        scanf("%d %lf %lf %c", &hi->grade, &hi->score, &hi->range, &hi->food);//그 밖의 정보를 입력
    }
    return hi - p;//hi포인터 주소와 p주소 사이의 거리가 호텔의 수이다.
}

void out_hotel_info(struct hotel_info *p, int N, int G, double D)
{
    struct hotel_info *hi;
    struct hotel_info sort[100];//정렬을 위한 sort구조체 변수 선언
    int found = 0;

    for (hi = p; hi < p + N; hi++)
    {
        if (hi->grade >= G && hi->range <= D)//호텔을 검색하여 조건에 맞는 경우
        {
            sort[found++] = *hi;//sort객체에 호텔을 넣고 찾은 호텔 개수를 증가
        }
    }

    //정렬
    struct hotel_info tmp;//swap을 위한 임시 변수
    for (struct hotel_info *i = sort; i < sort + found; i++)
    {
        for (struct hotel_info *j = i + 1; j < sort + found; j++)
        {
            if (i->score < j->score)//선택 정렬을 이용하여 이후의 변수가 정렬이 되있지 않으면 정렬 시간다.
            {//score을 비교 평판도 순으로 정렬
                tmp = *i;
                *i = *j;
                *j = tmp;//구조체 순서 변경
            }
            else if (i->score == j->score && strcmp(i->name, j->name) > 0)
            {//평판도가 같을 경우 strcmp를 이용하여 명칭을 이용해 순서 정렬
                tmp = *i;
                *i = *j;
                *j = tmp;//구조체 순서 정렬
            }
        }
    }

    for (struct hotel_info *p = sort; p < sort + found; p++)//정렬된 구조체를 출력한다.
        printf("%s %d %.1lf %.1lf %c\n", p->name, p->grade, p->score, p->range, p->food);
}