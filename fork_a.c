# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
void main()
{
int i,j,temp=0;
int arr[5];
printf("ENTER ELEMENTS IN ARRAY:\n");
for(i=0;i<5;i++)
{
scanf("%d\t",&(arr[i]));
}
pid_t pid;
pid=fork();
if(pid==0)
{
printf("\n");
printf("\n");
printf("Child class execution:\n");
printf("Child Process Id=%d\n",getpid());
for(i=0;i<5;i++)
{
for(j=0;j<5;j++)
{
if(arr[i]>arr[j])
{
temp=arr[i];
arr[i]=arr[j];
arr[j]=temp;
}
}
}
printf("Sorted array elements in descending order are:\n");
for(i=0;i<5;i++)
{
printf("%d\t",arr[i]);
}
}
else
{
printf("Parent class execution:\n");
printf("Parent Process Id=%d\n",getpid());
for(i=0;i<5;i++)
{
for(j=0;j<5;j++)
{
if(arr[i]<arr[j])
{
temp=arr[i];
arr[i]=arr[j];
arr[j]=temp;
}
}
}
printf("Sorted array elements in ascending order are:\n");
for(i=0;i<5;i++)
{
printf("%d\t",arr[i]);
}
}
}

/*
OUTPUT
ENTER ELEMENTS IN ARRAY:
14
5
27
10
18
9
Parent class execution:
Parent Process Id=3427
Sorted array elements in ascending order are:
5 10 14 18 27
Child class execution:
Child Process Id=3428
Sorted array elements in descending order are:
27 18 14 10 5
  */
