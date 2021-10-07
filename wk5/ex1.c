//¿¹Á¦ 11.6
#include <stdio.h>

typedef struct complex
{
    double real, imag;
} Complex;

Complex add_complex(Complex, Complex);

int main()
{
    Complex a, b, result;
    scanf("%lf %lf", &a.real, &a.imag);
    scanf("%lf %lf", &b.real, &b.imag);
    result = add_complex(a, b);
    printf("%.1lf %.1lf", result.real, result.imag);

    return 0;
}

Complex add_complex(Complex a, Complex b)
{
    Complex r;
    r.real = a.real + b.real;
    r.imag = a.imag + b.imag;
    return r;
}