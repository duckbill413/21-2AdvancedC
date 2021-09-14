#include <stdio.h>

void sort(int *, int *, int, int);
void uppsort(int *, int);
void downsort(int *, int);
//정렬을 위한 함수 세개 선언

int main()
{
    int arr1[11], arr2[11];
    int size1 = 0, size2 = 0;
    //정수를 입력할 배열 두개 및 배열 크기를 위한 정수 두개 선언
    for (int *parr = arr1; parr < arr1 + 11; parr++)
    {
        scanf("%d", parr); //포인터를 이용하여 arr1에 값 입력
        if (*parr == 0)
            break; //0이 입력되면 입력 종료
        size1++;   //0입력 되기 전까지의 배열 크기
    }
    for (int *parr = arr2; parr < arr2 + 11; parr++)
    {
        scanf("%d", parr); //포인터를 이용하여 arr1에 값 입력
        if (*parr == 0)
            break; //0이 입력되면 입력 종료
        size2++;   //0입력 되기 전까지의 배열 크기
    }
    sort(arr1, arr2, size1, size2);
    downsort(arr1, size1);
    uppsort(arr2, size2);
    //정렬을 위한 함수 실행

    for (int *parr = arr1; parr < arr1 + size1; parr++)
        printf("%d ", *parr);
    //포인터를 이용하여 배열의 값 출력
    printf("\n");
    for (int *parr = arr2; parr < arr2 + size2; parr++)
        printf("%d ", *parr);
    //포인터를 이용하여 배열의 값 출력

    return 0;
}

void sort(int *a, int *b, int n, int m)
{ //큰값은 arr1, 작은값은 arr2에 입력하기 위한 함수
    for (int *p = a; p < a + n; p++)
    {
        for (int *q = b; q < b + n; q++)
        {
            if (*p < *q) //같은 위치의 arr1과 arr2를 비교
            {
                int tmp = *q;
                *q = *p;
                *p = tmp;
                //arr2의 값이 크면 arr1에 넣고 arr2에는 arr1의 작은 값을 넣는다.
            }
        }
    }
}

void downsort(int *a, int n)
{                                    //내림차순 정렬을 위한 함수
    for (int *p = a; p < a + n; p++) //버블정렬 사용
    {
        for (int *q = a; q < a + n; q++)
        {
            if (*p > *q) //뒤의 값이 더 크면
            {
                int tmp = *q;
                *q = *p;
                *p = tmp;
                //tmp를 이용하여 뒤와 앞의 값을 바꾸어준다.
            }
        }
    }
}

void uppsort(int *a, int n)
{                                    //오름차순 정렬을 위한 함수
    for (int *p = a; p < a + n; p++) //버블정렬 사용
    {
        for (int *q = a; q < a + n; q++)
        {
            if (*p < *q) //앞의 값이 더 크면
            {
                int tmp = *q;
                *q = *p;
                *p = tmp;
                //tmp를 이용하여 뒤와 앞의 값을 바꾸어준다.
            }
        }
    }
}