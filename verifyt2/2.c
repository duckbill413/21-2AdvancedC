#include <stdio.h>
#include <math.h>

typedef struct complex
{
    float real;
    float imag;
    float abs;
} Complex;

Complex add(Complex a, Complex b);
Complex sub(Complex a, Complex b);
void abs_val(struct complex *p1, struct complex *p2, struct complex *p3);

int main()
{
    Complex com[3];

    for (Complex *pcom = com; pcom < com + 3; pcom++)
        scanf("%f %f", &pcom->real, &pcom->imag);

    abs_val(&com[0], &com[1], &com[2]);
    Complex added = add(com[0], com[1]);
    Complex subed = sub(com[0], com[1]);

    printf("%.1f%+.1fi\n", added.real, added.imag);
    printf("%.1f%+.1fi", subed.real, subed.imag);

    return 0;
}

Complex add(Complex a, Complex b)
{
    Complex result;
    result.real = a.real + b.real;
    result.imag = a.imag + b.imag;
    return result;
}

Complex sub(Complex a, Complex b)
{
    Complex result;
    result.real = a.real - b.real;
    result.imag = a.imag - b.imag;
    return result;
}

void abs_val(struct complex *p1, struct complex *p2, struct complex *p3)
{
    p1->abs = sqrt(pow(p1->real, 2) + pow(p1->imag, 2));
    p2->abs = sqrt(pow(p2->real, 2) + pow(p2->imag, 2));
    p3->abs = sqrt(pow(p3->real, 2) + pow(p3->imag, 2));

    Complex max = *p1;
    Complex min = *p1;

    if (p1->abs < p2->abs)
    {
        max = *p2;
        if (p2->abs < p3->abs)
            max = *p3;
    }
    else if (p1->abs < p3->abs)
    {
        max = *p3;
    }

    if (p1->abs > p2->abs)
    {
        min = *p2;
        if (p2->abs > p3->abs)
            min = *p3;
    }
    else if (p1->abs > p3->abs)
    {
        min = *p3;
    }

    *p1 = max;
    *p2 = min;
    // printf("max: %.1f %.1f\n", p1->real, p1->imag);
    // printf("min: %.1f %.1f\n", p2->real, p2->imag);
}
/*
2.3 4.5
3.4 5.0
-1.4 7.2

2.3 4.5
3.4 5.0
1.4 -7.2

19.754 23.221
98.454 -45.221
21.456 12.333
*/