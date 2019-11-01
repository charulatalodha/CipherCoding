#include<stdio.h>
#include<conio.h>
#include<string.h>
void main()
{
 char mat[5][5]={'K','E','Y','W','O',
		 'R','D','A','B','C',
		 'F','G','H','I','L',
		 'M','N','P','Q','S',
		 'T','U','V','X','Z'};
 int i,j,k,l;
 int x[10],y[10];
 char str[10];
 clrscr();
 for(i=0;i<5;i++)
 {
  for(j=0;j<5;j++)
	 printf("%c\t",mat[i][j]);
  printf("\n");
 }
 printf("Enter the word");
 scanf("%s",&str);
 printf("%s",str);

  l=strlen(str);
  if(l%2!=0)
 {
  str[l]='X';
  str[l+1]='\0';
  printf("%s",str);
 }
 i=0;
 while(str[i]!='\0')
 {
  if(str[i]=='J')
	 str[i]='I';
	i++;
 }
 j=0;
 while(str[j]!='\0')
 {
  for(i=0;i<5;i++)
  {
	for(k=0;k<5;k++)
	  if(str[j]==mat[i][k])
	  {
		 x[j]=i;
		 y[j]=k;
		 printf("%d\t%d",x[j],y[j]);
	  }
	}
	j++;
	printf("\n");
 }

 i=0;
 while(str[i]!='\0')
 {
  if(x[i]==x[i+1])
  {
	 str[i]=mat[x[i]][(y[i]+1)%5];
	 str[i+1]=mat[x[i+1]][(y[i+1]+1)%5];
  }
  else if(y[i]==y[i+1])
  {
  str[i]=mat[(x[i]+1)%5][y[i]];
  str[i+1]= mat[(x[i+1]+1)%5][y[i+1]];
  }
  else
  {
	str[i]=mat[x[i]][y[i+1]];
	str[i+1]=mat[x[i+1]][y[i]];
  }
  i=i+2;
 }
 printf("Encrypted text is:\n");
 printf("%s",str);
 getch();
}