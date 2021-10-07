//¿¹Á¦ 11.7
#include <stdio.h>

typedef struct complex
{
    double real, imag;
} Complex;

Complex *large_complex(Complex *, Complex *);

int main()
{
    Complex a, b, *result;
    scanf("%lf %lf", &a.real, &a.imag);
    scanf("%lf %lf", &b.real, &b.imag);
    result = large_complex(&a, &b);

    printf("%.1lf %.1lf", result->real, result->imag);
    return 0;
}

Complex *large_complex(Complex *a, Complex *b)
{
    double size1, size2;
    size1 = a->real * a->real + a->imag * a->imag;
    size2 = b->real * b->real + b->imag * b->imag;
    if (size1 > size2)
        return a;
    else
        return b;
}