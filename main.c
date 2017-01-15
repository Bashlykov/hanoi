#include <stdio.h>
#define M 10

int t, s1=0, s2=0,
         r1=0, r2=0,
         stack[M];

void f(int n, int x, int y)
{
    int i;

    for (i=1; i<=n; i++)
    {
        if(i>0)
        {
            if (i%2)
            {
                if (t%2)
                {
                    s2=y;
                    if (stack[i]!=0) r2=stack[i]-1; else r2=s2;
                    if (r2<1) r2=3;
                }
                else
                {
                    s2=y-1;
                    if (stack[i]!=0) r2=stack[i]+1; else r2=s2;
                    if (r2>3) r2=1;
                }
                stack[i]=r2;
                printf("Disk %d move from %d to %d\n",i,x,r2);
                f(i-1, r1, r2);
            }
            else
            {
                if (t%2)
                {
                    s1=y-1;
                    if (stack[i]!=0) r1=stack[i]+1; else r1=s1;
                    if (r1>3) r1=1;
                }
                else
                {
                    s1=y;
                    if (stack[i]!=0) r1=stack[i]-1; else r1=s1;
                    if (r1<1) r1=3;
                }
                stack[i]=r1;
                printf("Disk %d move from %d to %d\n",i,x,r1);
                f(i-1, r2, r1);
            }
        }
    }
    return;
}

int main(char *args[], int argn)
{
    int j;
    for (j=0; j<M; j++) stack[j]=0;
    printf("Input n disks: ");
    scanf("%d", &t);
    f(t,1,3);
    return 0;
}
