#include <stdio.h>
#define max 20
void main()
{
    int n,hp,p[max],seekt=0,i,j,rq[max],t=0,temp,d,a;
    printf("Enter the total no. of request :");
    scanf("%d",&n);
    printf("Enter requests :");
    for(i=0;i<n;i++)
    {
        scanf("%d",&p[i]);
    }
    printf("Enter head position :");
    scanf("%d",&hp);
    p[n]=hp;
    printf("Enter the no of disks :");
    scanf("%d",&d);
    p[n+1]=d-1;
    for(i=0;i<=n;i++)
    {
        for(j=i+1;j<=n+1;j++)
        {
        if(p[i]>p[j])
        {
            temp=p[i];
            p[i]=p[j];
            p[j]=temp;
        }
        }
    }
    for(i=0;i<=n;i++)
    {
        if(p[i]==hp)
        t=i;
    }
        printf("The SCAN scheduling >>\n");
    for(i=t;i<=n;i++)
        printf("%d\t",p[i]);
    printf("0-->");
    for(i=0;i<=t-1;i++)
    {
        printf("%d\t",p[i]);
        a=i;
    }
    seekt=(p[n+1] - p[t])+p[n+1]+p[t-1];
    printf("\nTotal seek time : %d\n",seekt);
}
