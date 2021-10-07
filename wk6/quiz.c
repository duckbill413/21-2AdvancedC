#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct student
{

    int id;

    char name[10];

    double grade;
};
int main()
{

    struct student st1 = {10, "Tom", 3.2}, st2 = {20, "Cat"};

    struct student *past[3] = {&st1, &st2};

    past[2] = past[1];

    *past[2] = *past[0];

    printf("id: %d\n", past[2]->id);

    printf("name: %s\n", past[2]->name);

    printf("grade: %.2f\n", past[2]->grade);

    return 0;
}

/////////////////////////////
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct student
{

    int id;

    char name[10];

    double grade;
};

void ABC(struct student st)
{
    st.id = 30;
}
int main()
{
    struct student st1 = {10, "Tom", 3.2}, st2 = {20, "Cat"};

    ABC(st1);

    printf("id: %d\n", st1.id);
}
/////////////////////////////
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct student
{

    int id;

    char name[10];

    double grade;
};

void ABC(struct student st[])
{

    (st + 1)->id = 30;
}
int main()
{
    struct student st[2] = {{10, "Tom", 3.2}, {20, "Cat"}};

    ABC(st);

    printf("id: %d\n", st[0].id);

    printf("id: %d\n", st[1].id);
}
/////////////////////////////
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct student
{

    int id;

    char name[10];

    double grade;
};
int main()
{
    struct student st[2] = {{10, "Tom", 3.2}, {20, "Cat"}};

    printf("id: %d\n", st[0].id);

    printf("id: %d\n", st->id);

    printf("id: %d\n", (st + 1)->id);

    printf("id: %d\n", *(st).id);
}
/////