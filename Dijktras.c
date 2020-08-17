#include<stdio.h>
#include<conio.h>
#include<string.h>

void main()
{
	int n,i,j,k=1,r,cv;
	char p;
	printf("Enter no of vertices:");
	scanf("%d",&n);
	int G[n][n];
	char PATH[n][2*n],temp[2];
	printf("Enter weight adjacency matrix:\n\t");
	for(i=0;i<n;i++)
	printf("%c\t",(97+i));
	printf("\n");
	for(i=0;i<n;i++)
	{
		printf("%c\t",(97+i));
		for(j=0;j<n;j++)
		{
			scanf("%d",&G[i][j]);
		}
	}
	
	printf("\nEnter source vertex(character):");
	p=getch();
	printf("%c\n",p);
	r=(int)p-97;
	
	int VIS[n],D[n];
	
	for(i=0;i<n;i++)
	{
		VIS[i]=0;
		PATH[i][0]=p;
		PATH[i][1]='\0';
	}
	
	VIS[r]=1;D[r]=0;
	for(i=0;i<n;i++)
	{
		if(VIS[i]==0)
		{
			D[i]=G[r][i];
		}
	}
	int min=100;
	for(i=0;i<n;i++)
	{
		if(min>D[i]&&D[i]!=0)
		{
			min=D[i];
			cv=i;
		}
	}
	
	while(k<n)
	{
		VIS[cv]=1;
		min=100;
		for(i=0;i<n;i++)
		{
			if(VIS[i]==0)
			{
				//D[i]=(D[i]>(D[cv]+G[cv][i])?(D[cv]+G[cv][i]):D[i]);
				if(D[i]>(D[cv]+G[cv][i]))
				{
					temp[0]='-';
					temp[1]=(char)(97+cv);
					strcat(PATH[i],temp);
					D[i]=D[cv]+G[cv][i];
				}
				/*else
				{
					PATH[i][1]='-';
					PATH[i][2]=(char)(97+i);
					PATH[i][3]='\0';
				}*/
			}
		}
		for(i=0;i<n;i++)
		{
			if(VIS[i]==0)
			{
				if(min>D[i] && D[i]!=0)
				{
					min=D[i];
					cv=i;
				}
			}
		}
		k++;
	}
	printf("Shotest path lengths:\t\tShortest paths::\n");
	for(i=0;i<n;i++)
	{
		printf("%c->%c: %d\t\t\t\t",(97+r),(97+i),D[i]);
		temp[0]='-';
		temp[1]=(char)(97+i);
		strcat(PATH[i],temp);
		puts(PATH[i]);
	}

}
