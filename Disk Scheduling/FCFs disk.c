#include <stdio.h>
#define max 20
void main()
{
    int s[max],i,h,n,t=0,f[max],j=0;
    printf("Enter the total no. of request :");
    scanf("%d",&n);
    printf("Enter requests :");
    for(i=0;i<n;i++)
        {
            scanf("%d",&s[i]);
        }
    printf("Enter head request :");
    scanf("%d",&h);
    printf("FCFS disk scheduling>>");
    for(i=0;i<n;i++)
        {
            f[0]=h;
            f[i+1]=s[i];
        }
    for(i=0;i<=n;i++)
        {
                printf("%d ",f[i]);
        }
    for(i=0;i<n;i++)
        {
            if(f[i+1]<f[i])
            {
                j=f[i]-f[i+1];
            }
            else
            {
                j=f[i+1]-f[i];
            }
            t=t+j;
        }
    printf("\nTotal seek time : %d",t);
}