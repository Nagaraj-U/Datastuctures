#include <stdio.h>
#include <stdlib.h>
int gcd(int,int);
void main()
{
    int m,n,r;
    printf("enter the numbers\n");
   scanf("%d%d",&m,&n);
   r=gcd(m,n);
   printf("gcd of %d %d is %d",m,n,r);
}
int gcd(int a,int b)
{
    if(b==0)
    {
        return a;
    }
    else
    {
        if(b>a)
        {
            return gcd(b,a);
        }
        else
        {
            return gcd(b,a%b);
        }
    }


}
