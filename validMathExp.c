#include<stdio.h>
#include<string.h>

//incomplete program
int main()
{
int i,j,l,t=0;
char input[20];
printf("Enter the input\n");
scanf("%s",&input);
l=strlen(input);
for(i=0;i<l;i++)
{
    if(input[i]=='(')
    t++;
    else if(input[i]==')')
    t--;
    else if(input[i]=='*'||input[i]=='/'||input[i]=='+'||input[i]=='-')
   {
      if(input[i-1]>96 && input[i-1]<123 && input[i+1]>96 && input[i+1]<123)
      {
        continue;
       }
       else
           break;
       }
}
if(i==l && t==0)
   printf("Valid");
else
   printf("Invalid ");
}
