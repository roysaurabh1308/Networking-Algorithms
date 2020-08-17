#include<stdio.h>
#include<stdlib.h>
const int max=50;

void main()
{
int GS,DS;
printf("\nEnter CRC Generator Size : ");
scanf("%d",&GS);
printf("\nEnter Data Size : ");
scanf("%d",&DS);
int data[max],crc[max],D1[max],res[max],i,flag,temp[max];
printf("\nEnter Data : ");
for(i=0;i<DS;i++)
{scanf("%d",&data[i]);}
printf("\nEnter CRC : ");
for(i=0;i<GS;i++)
{scanf(" %d",&crc[i]);}
for(i=0;i<DS;i++)
D1[i]=data[i];
for(i=0;i<GS;i++)
D1[DS+i]=0;
flag=0;
for(i=0;i<GS;i++)
{
flag++;
temp[i]=D1[i];
if(temp[i]==crc[i])
res[i]=0;
else 
res[i]=1;
}
while(flag<DS+GS)
{
for(i=0;i<GS;i++)
temp[i]=res[i];
while((temp[0]==0)&&(flag<DS+GS))
{
for(i=0;i<GS-1;i++)
temp[i]=temp[i+1];
temp[GS-1]=D1[flag];
flag++;
}
for(i=0;i<GS;i++)
{if(temp[i]==crc[i])
res[i]=0;
else
res[i]=1;}
}
printf("\nObtained Remainder : ");
for(i=0;i<GS;i++)
printf("%d",res[i]);
printf("\nTherefore Data to be sent : ");
for(i=0;i<DS;i++)
printf("%d",data[i]);
for(i=0;i<GS;i++)
printf("%d",res[i]);
printf("\n\n");
}
