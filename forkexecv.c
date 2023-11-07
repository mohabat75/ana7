//S2a.c file:

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
int main(int argc,char *argv[])
{
 int val[10],ele;
 pid_t pid;
 char *cval[10];
 int i,j,n,temp;
 printf("\n Enter the size of array\n");
 scanf("%d",&n);
 printf("\n Enter the number\n");
 for(i=0;i<n;i++)
 {
 scanf("%d",&val[i]);
 }
 printf("\n Element entered are\n");
 for(i=0;i<n;i++)
 printf("%d",val[i]);

 {
 for(i=1;i<n;i++)
 {
 for(j=0;j<n-1;j++)
 {
 if(val[j]>val[j+1])
 {
 temp=val[j];
 val[j]=val[j+1];
 val[j+1]=temp;
 }
 }
 }
 printf("\n Sorted element are\n:");
 for(i=0;i<n;i++)
 {
 printf("%d",val[i]);
 }
 printf("\n Enter element to search:");
 scanf("%d",&ele);
 val[i]=ele;
 for(i=0;i<n+1;i++)
 {
 char a[sizeof(int)];
 snprintf(a,sizeof(int),"%d",val[i]);
 strcpy(cval[i],a);
 }
 cval[i]=NULL;
 pid=fork();
 if(pid==0)
 {
 execv(argv[1],cval);
 perror("\n Error in execv call");
 }
}
}

  
//s2c.c file:
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc,char *argv[],char *en[])
{
 int i,j,c,arr[argc],ele,n;

 for(j=0;j<argc-1;j++)
 {
 n=atoi(argv[j]);
 arr[j]=n;
 }
 ele=atoi(argv[j]);
 i=0;j=argc-1;
 c=(i+j)/2;
 while(arr[c]!=ele & i<=j)
 {
 if(ele>arr[c])
 i=c+1;
 else
 j=c-1;
 c=(i+j)/2;
 }
 if(i<=j)
 printf("\n Element found in given array");
 else
 printf("\n Element not found in given array");
 return 0;
}
/*
Output:
avcoe@avcoe-HP-ProDesk-400-G1-SFF:~$ gcc s2a.c -o first
avcoe@avcoe-HP-ProDesk-400-G1-SFF:~$ gcc s2c.c -o second
avcoe@avcoe-HP-ProDesk-400-G1-SFF:~$ ./first ./second
Enter the size of array
5
Enter the number
2
7
8
4
5
Element entered are
27845
Sorted element are
:24578
Enter element to search:8
Element found in given array
*/
