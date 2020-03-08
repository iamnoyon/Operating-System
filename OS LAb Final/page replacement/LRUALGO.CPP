#include<conio.h>
#include<stdio.h>

int main()
{
   int frm,q[30];
   int i,j,k,n,max,hit,count=0,len[30],a[100];
   //clrscr();

      printf("insert the number page request:  ");
   scanf("%d",&n);

   printf("Enter reference string: \n");
   for(i=0;i<n;i++)
   scanf("%d",&a[i]);

   printf("Frame table size: ");
   scanf("%d", &frm);

   for(i=0;i<n;i++)
   {
      printf("%d=  ",a[i]);

      if(i<frm)
      {
	 q[i]=a[i];
	 for(j=0;j<=i;j++)
	 printf("%5d",q[j]);
	 printf("\n");
	 count++;
      }
      else
      {  hit=0;
	 for(j=0;j<frm;j++)
	 if(a[i]==q[j])
	hit=1;
	 if(hit==1)
	 printf("\n");
	 else{
	 for(j=0;j<frm;j++)
	 {
	    for(k=i;k>=0;k--)
	    if(a[k]==q[j])
	    break;
	    len[j]=i-k;
	 }
	 max=0;
	 for(j=0;j<frm;j++)
	 if(len[j]>len[max])
	 max=j;
	    count++;
	    q[max]=a[i];
	  for(j=0;j<frm;j++)
	    printf("%5d",q[j]);
	    printf("\n");
	 }
      }
   }
   printf("fault:%d",count);
   getch();
}


