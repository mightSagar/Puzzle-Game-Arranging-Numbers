#include<stdio.h>
#include<conio.h>
#include<process.h>
#include"time.h"
#define ESC 27
int check();
int finally();
int change(int,int);
int getkey();
int a[4][4]={{1,4,15,7},{8,10,2,11},{14,3,6,13,},{12,9,5,0}};
int z[4][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12,},{13,14,15,0}};
int c,b,w;
int main()
{
	int m,n;
	printf("Arrange the numbers in ascending order : \n\n\n");
	for(m=0;m<4;m++)
	{
		for(n=0;n<4;n++)
		if(a[m][n]!=0)
		printf("\t%d\t",a[m][n]);
		else
		printf(" ");
		printf("\n\n");
	}
	for(m=0;m<4;m++)
		{
			for(n=0;n<4;n++)
			{
				if(a[m][n]==0)
				change(m,n);
			}
		}
	return 0;
}
int change(int i,int j)
{
	while((w=check())==1)
	{
		b=getkey();
		if(b==72)
		{
			if((i+1<4&&(j+1<4||j+1>0)))
				{c=a[i][j];a[i][j]=a[i+1][j];a[i+1][j]=c;}
			else
				change(i,j);
		}
		else if(b==80)
		{
			if((i+1>0&&(j+1>0||j+1<4)))
				{c=a[i][j];a[i][j]=a[i-1][j];a[i-1][j]=c;}
			else
				change(i,j);
		}
		else if(b==75)
		{
			if((j+1<4)&&(i+1>0||i+1<4))
				{c=a[i][j];a[i][j]=a[i][j+1];a[i][j+1]=c;}
			else
				change(i,j);
		}
		else if(b==77)
		{
			if((j+1>0)&&(i+1<4||i+1>0))
				{c=a[i][j];a[i][j]=a[i][j-1];a[i][j-1]=c;}
			else
				change(i,j);
		}
		else
			puts("Result is as follows...:\n\n");
		system("cls");
		printf("Arrange the numbers in ascending order : \n\n\n");
		for(i=0;i<4;i++)
		{
			for(j=0;j<4;j++)
			{
				if(a[i][j]!=0)
					printf("\t%d\t",a[i][j]);
				else
					printf("\t \t");
			}
			printf("\n\n");
		}
		for(i=0;i<4;i++)
		{
			for(j=0;j<4;j++)
				if(a[i][j]==0)
					change(i,j);
		}
	}
}
int getkey()
{
	int ch;
	while((ch=getch())!=ESC)
	{
		while(kbhit())
			return(getch());
	}
	exit(2);
}
int check()
{
	if(a[0][0]!=z[0][0]||a[1][1]!=z[1][1]||a[2][2]!=z[2][2]||a[3][3]!=z[3][3]
	 ||a[0][1]!=z[0][1]||a[0][2]!=z[0][2]||a[0][3]!=z[0][3]||a[1][2]!=z[1][2]
	 ||a[1][3]!=z[1][3]||a[1][0]!=z[1][0]||a[2][0]!=z[2][0]||a[2][1]!=z[2][1]
	 ||a[2][3]!=z[2][3]||a[3][0]!=z[3][0]||a[3][1]!=z[3][1]||a[3][2]!=z[3][2])
		return 1;
	else
		finally();
}
int finally()
{
	int c;
	c=clock()/CLOCKS_PER_SEC;
	if(((600-c)/10)==0)
	{
		printf("Game Over");
		exit(2);
	}
	else
	{
		printf("Your Score is : %d",((600-c)/10));
		exit(1);
	}
}
