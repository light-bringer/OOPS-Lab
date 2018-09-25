#include<stdio.h>
#include<stdlib.h>

long long int max(long long int a,long long int b)
{
    return a>b?a:b;
}

long long int min(long long int a,long long int b)
{
    return a<b?a:b;
}

long long int solve(long long int a[],int n)
{
    long long int curr_max,max_forward[100000],min_forward[100000],curr_min;
    curr_max=a[0];
    curr_min=a[0];
    max_forward[0]=a[0];
    min_forward[0]=a[0];

    int i;

    for(i=1;i<n;i++)
    {
        curr_max=max(curr_max+a[i],a[i]);
        max_forward[i]=max(curr_max,max_forward[i-1]);
        curr_min=min(curr_min+a[i],a[i]);
        min_forward[i]=min(curr_min,min_forward[i-1]);
    }

    long long int max_backward[100000],min_backward[100000];
    max_backward[n-1]=min_backward[n-1]=a[n-1];
    curr_max=a[n-1];
    curr_min=a[n-1];

    for(i=n-2;i>=0;i--)
    {
        curr_max=max(curr_max+a[i],a[i]);
        max_backward[i]=max(max_backward[i+1],curr_max);
        curr_min=min(curr_min+a[i],a[i]);
        min_backward[i]=min(min_backward[i+1],curr_min);
    }
    long long int ans=0;

    for(i=0;i<n-1;i++)
    {
      ans=max(ans,abs(max_backward[i+1]-min_forward[i]));
      ans=max(ans,abs(max_forward[i]-min_backward[i+1]));
    }
    return ans;
}
int main()
{
    int t;
    scanf("%d",&t);

    while(t--)
    {
        int n,i;
        scanf("%d",&n);

        long long int a[n];

        for(i=0;i<n;i++)
            scanf("%lld",&a[i]);

        long long int answer=solve(a,n);
        printf("%lld\n",answer);
    }
    return 0;
}
