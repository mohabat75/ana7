//FIFO
#include<stdio.h>
int main()
{
int i,j,n,a[50],frame[10],no,k,avail,count=0;
 printf("\n ENTER THE NUMBER OF PAGES:\n");
scanf("%d",&n);
 printf("\n ENTER THE PAGE NUMBER :\n");
 for(i=1;i<=n;i++)
 scanf("%d",&a[i]);
 printf("\n ENTER THE NUMBER OF FRAMES :");
 scanf("%d",&no);
for(i=0;i<no;i++)
 frame[i]= -1;
 j=0;
 printf("\tref string\t page frames\n");
for(i=1;i<=n;i++)
 {
 printf("%d\t\t",a[i]);
 avail=0;
 for(k=0;k<no;k++)
if(frame[k]==a[i])
 avail=1;
 if (avail==0)
 {
 frame[j]=a[i];
 j=(j+1)%no;
 count++;
 for(k=0;k<no;k++)
 printf("%d\t",frame[k]);
}
 printf("\n");
}
 printf("Page Fault Is %d",count);
 return 0;
}


/*
OUTPUT
ENTER THE NUMBER OF PAGES:
10
 ENTER THE PAGE NUMBER :
2 3 4 2 1 3 7 5 4 3
 ENTER THE NUMBER OF FRAMES :3
ref string page frames
2 2 -1 -1
3 2 3 -1
4 2 3 4
21
1
3
4
37
1
7
4
5
1
7
5
4
4
7
5
3
4
3
5
Page Fault Is 8
  */
