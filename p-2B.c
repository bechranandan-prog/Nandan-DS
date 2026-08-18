#include <stdio.h>
void callbyvalue(int x)
{
    x=x+10;
    printf("inside call by value %d\n", x);
}
void callbyrefrence(int *x)
{
    *x= *x+10;
    printf("Inside call by refrence value %d\n",*x);
}
int main()
{
    int a,b;
    printf("enter a");
    scanf("%d", &a);
    printf("enter b");
    scanf("%d", &b);
    printf("before value of call by value is %d \n", a);
    callbyvalue(a);
    printf("after call by value : %d\n",a);
    printf("before value of call by refrence is %d\n ", b);
    callbyrefrence(&b);
    printf("after call by refrence : %d",b);
return 0;
}