//¿¹Á¦ 11.9
#include <stdio.h>

typedef struct Box
{
    int maindish;
    int sidedish[3];
    int beverage;
} box;

int main()
{
    box a, b;
    scanf("%d %d %d %d %d", &a.maindish, &a.sidedish[0], &a.sidedish[1], &a.sidedish[2], &a.beverage);
    scanf("%d %d %d %d %d", &b.maindish, &b.sidedish[0], &b.sidedish[1], &b.sidedish[2], &b.beverage);
    printf("%d\n%d\n%d\n%d\n%d\n", a.maindish, a.sidedish[0], a.sidedish[1], a.sidedish[2], a.beverage);
    printf("%d\n%d\n%d\n%d\n%d\n", b.maindish, b.sidedish[0], b.sidedish[1], b.sidedish[2], b.beverage);
    return 0;
}