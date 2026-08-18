#include <stdio.h>
int main()
{
    int arr[10],n, i;
    int *ptr;
    printf("enter the number of elements:");
    scanf("%d",&n);
    printf("enter %d elements: \n",n);
    for(i=0; i<n;i++)
    {
        scanf("%d", &arr[i]);
    }
    ptr = arr+n-1;
    printf("array elements in reverse order are :\n");
    for(i=0; i<n; i++)
    {
        printf("%d",*ptr);
        ptr--;
    }
    return 0;

}