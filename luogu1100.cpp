#include <cstdio>
int main()
{
    short num[4];
    scanf("%d", (int *)&num);
    num[3] = num[0];
    num[2] = num[1];
    printf("%u", *(int *)(num+2));
}