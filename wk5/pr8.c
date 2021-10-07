#include <stdio.h>

typedef struct complex
{
    double real, imag;
} Complex;

Complex add(Complex, Complex);

int main()
{
    Complex a, b;
    scanf("%lf %lf", &a.real, &a.imag);
    scanf("%lf %lf", &b.real, &b.imag);

    Complex result = add(a, b);

    printf("%.1lf + %.1lfi", result.real, result.imag);

    return 0;
}

Complex add(Complex a, Complex b)
{
    Complex result;
    result.real = a.real + b.real;
    result.imag = a.imag + b.imag;
    return result;
}