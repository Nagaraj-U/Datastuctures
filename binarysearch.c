#include<stdio.h>

void main()
{

    int i,n,key,l,h,mid,r;
    int a[50];
    printf("enter the number of array elemnts\n");
    scanf("%d",&n);
    printf("enter the sorted array elements\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("enter the eleemnts to be searched\n");
    scanf("%d",&key);
    l=0;
    h=n-1;
   // mid=(l+h)/2;
    r=binary(a,l,h,key);
    r++;
    printf("element found at %d location",r);
}
int binary(int a[],int l,int h,int key)
{
    int mid;
    if(l==h)
    {
        if(a[l]==key)
            return l;
        else
            return 0;
    }
    else
    {
      mid=(l+h)/2;
      if(key==a[mid])
      {
          return mid;
      }
          else
          {
              if(key<a[mid])
              {
                  return binary(a,l,mid-1,key);
              }
              else
              {
                  return binary(a,mid+1,h,key);
              }
          }
      }
    }

