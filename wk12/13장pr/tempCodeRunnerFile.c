
// #include <stdio.h>
// int main(void)
// {
//     char ch;
//     unsigned int result = 0x00000000;
//     printf("첫번째 문자: ");
//     scanf("%c", &ch);
//     result = result | ch;
//     printf("%d  ", ch);
//     printf("%08x\n", result);
//     getchar();
//     printf("두번째 문자: ");
//     scanf("%c", &ch);
//     result = result << 8;
//     result = result | ch;
//     getchar();
//     printf("세번째 문자: ");
//     scanf("%c", &ch);
//     result = result << 8;
//     result = result | ch;
//     getchar();
//     printf("네번째 문자: ");
//     scanf("%c", &ch);
//     result = result << 8;
//     result = result | ch;
//     getchar();
//     printf("결과값: %08x\n", result);
//     return 0;
// }