#include<stdio.h>
#include<conio.h>
int stack[20],top=-1;
int vis[20];
int a[20][20];
void dfs(int s,int n);
void push(int item);
int pop();
void dfs(int s,int n)
{
     int i,k;
     push(s);
     vis[s]=1;
     k=pop();
     if(k!=0)
     printf("\%d",k);
     while(k!=0)
     {
                for(i=1;i<=n;i++)
                if((a[k][i]!=0)&&(vis[i]=0))
                {
                                        push(i);
                                        vis[i]=1;
                }
                k=pop();
                if(k!=0)
                printf("\n%d",k);
     }
     for(i=1;i<=n;i++)
     if(vis[i]==0)
     dfs(i,n);
     }
     void push(int item)
     {
          if(top==19)

                     printf("\nstack overflow");

          else
          stack[++top]=item;
     }
     int pop()
     {
         int k;
         if(top==-1)
         return(0);
         else
         {
         k=stack[top--];
         return(k);
         }
     }
     int main()
     {
         int i,j,s,n;
         printf("\nenter the no of vertices");
         scanf("%d",&n);
         for(i=1;i<=n;i++)
         {
                          for(j=1;j<=n;j++)
                          {
                                           printf("\nEnter 1 if %d has a node %d else 0",i,j);
                                           scanf("%d",&a[i][j]);
                          }
         }
         printf("\nADJACENCY MATRIX:");
         for(i=1;i<=n;i++)
         {
                          for(j=1;j<=n;j++)
                          {
                                       printf("\n%d",a[i][j]);
                          }
         }
            for(i=1;i<=n;i++)

                                   vis[i]=0;
                                   printf("\nEnter the source vertex");
                                   scanf("%d",&s);
                                   dfs(s,n);
                                   getch();

         }
