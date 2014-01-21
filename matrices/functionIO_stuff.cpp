#include<stdio.h>
int* test(int a,int b)
{
int* pointer;
int info[1];
pointer=info;
info[0]=a;
info[1]=b;
return pointer;
}
int main()
{
int* ptr=test(200,100);
printf("%d",ptr[0]);
printf("\n%d",ptr[1]);
getchar();
return 0;
}
