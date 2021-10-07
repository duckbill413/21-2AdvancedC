#include <stdio.h>

struct bike_info //자전거 대여 구조체 선언
{
    int num;       //자전거 번호
    int phone;     //고객 전화번호
    char product;  //상품 S, D
    char sign;     //정기권 가입여부 Y, N
    int sign_kind; //정기권 종류 7/30/180일
    int time;      //대여시간
    double won;    //요금
};

void input(struct bike_info *p, int N);          //bike 대여 정보 저장
void compute(struct bike_info *p, int N);        //bike 대여 비용 저장
void display(struct bike_info *p, int N);        //자전거 대여 비용 출력
void bike_info_sort(struct bike_info *p, int N); //상품 및 자전거 번호에 대하여 오름 차순 정렬

int main()
{
    struct bike_info bi[100]; //100개의 자전거 구조체 변수 생성
    int n;
    scanf("%d", &n);       //자전거 개수 입력
    input(bi, n);          //n개의 자전거 정보 입력
    compute(bi, n);        //n개의 자전거 대여 비용 저장
    bike_info_sort(bi, n); //자전거 데이터를 정렬
    display(bi, n);        //자전거 정보 출력
    return 0;
}

void input(struct bike_info *p, int N)
{
    for (struct bike_info *pp = p; pp < p + N; pp++)
    {                                                          //주소를 이용하여 자전거 정보를 살펴 본다.
        scanf("%d %d %c", &pp->num, &pp->phone, &pp->product); //이름, 전화번호, 상품 정보 입력
        if (pp->product == 'S')                                //상품이 S인 경우
        {
            getchar();                                               //버퍼 지우기
            scanf("%c %d %d", &pp->sign, &pp->sign_kind, &pp->time); //정기권 유무, 정기권 종류, 대여 시간 입력
        }
        else                        //상품이 D인 경우
            scanf("%d", &pp->time); //대여 시간만 입력
    }
}

void compute(struct bike_info *p, int N)
{
    double total = 0.0;
    for (struct bike_info *pp = p; pp < p + N; pp++)
    {
        total = 0.0;                               //대여비용 초기화
        if (pp->product == 'S' && pp->sign == 'N') //상품이 S이면서 정기권이 없을때
        {
            if (pp->sign_kind == 7)        //7일권
                total += 3000;             //3000원 추가
            else if (pp->sign_kind == 30)  //30일권
                total += 5000;             //5000원 추가
            else if (pp->sign_kind == 180) //180일 권
                total += 15000;            //15000원 추가
        }
        else if (pp->product == 'D') //상품이 D일경우 1000원 추가
            total += 1000;

        if (pp->time > 60) //대여시간이 60분 초과
        {
            total += (pp->time - 60) / 5 * 200; //초과된시간 /5에 200원을 곱하여 계산
        }

        pp->won = total; //구조체의 대여비용에 계산한 값 저장
    }
}
void display(struct bike_info *p, int N)
{
    for (struct bike_info *pp = p; pp < p + N; pp++)
        printf("%d %d %c %.lf\n", pp->num, pp->phone, pp->product, pp->won);
    //N개의 구조체 변수에 대하여 정보 출력

    int total = 0, totalD = 0, totalS = 0; //S상품 총액, D상품 총액, 전체 총액 변수 선언
    for (struct bike_info *pp = p; pp < p + N; pp++)
    {
        if (pp->product == 'S')
        {                      //상품이 S인경우
            total += pp->won;  //전체 총액에 추가
            totalS += pp->won; //S총액에 추가
        }
        else
        {                      //상품이 D인 경우
            total += pp->won;  //전체 총액에 추가
            totalD += pp->won; //D총액에 추가
        }
    }

    printf("%d %d %d", totalD, totalS, total); //D, S, 전체 총액을 출력
}
void bike_info_sort(struct bike_info *p, int N)
{
    for (struct bike_info *i = p; i < p + N; i++) //선택정렬
    {
        for (struct bike_info *j = i + 1; j < p + N; j++)
        {
            if (i->product == 'S' && j->product == 'D') //앞의 상품이 S이고 뒤의 상품이 D일경우
            {                                           //D상품들의 정보가 앞으로 와야한다.
                struct bike_info tmp = *i;
                *i = *j;
                *j = tmp; //D상품 정보가 뒤에 있으면 순서 변경
            }
        }
    }
    for (struct bike_info *i = p; i < p + N; i++) //선택정렬
    {
        for (struct bike_info *j = i + 1; j < p + N; j++)
        {                                                    //상품 정보는 정렬된 상태
            if (i->num > j->num && i->product == j->product) //상품 정보 순서가 변하면 안됨
            {                                                //자전거 번호에 대하여 정렬하되 상품이 같을때면 변경
                struct bike_info tmp = *i;
                *i = *j;
                *j = tmp; //구조체 순서 변경
            }
        }
    }
}