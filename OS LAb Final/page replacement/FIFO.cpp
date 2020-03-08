#include<stdio.h>
#include<conio.h>

int main()
{
   int n,i,a[100],size,q[30],start,end,pos,j,found,count=0;


   printf("insert the number page request:  ");
   scanf("%d",&n);


   printf("\nEnter reference string: \n");
   for (i=0; i<n; i++)
   scanf("%d",&a[i]);

   printf("Enter size frame table: ");
   scanf("%d",&size);

   start=0;
   end=0;
   pos=0;
   for (i=0; i<n; i++)
   {
      printf("%d =  ",a[i]);
      found=0;
      for (j=start; j<end; j++)
      if (a[i]==q[j])
      found=1;

      if (found==1)
      printf("     \n");
      else
      {
	 count++;
	 q[pos]=a[i];
	 pos++;
	 if (pos==size)
	 pos=0;
	 if (end<size)
	 end++;
	 for (j=start; j<end; j++)
	 printf("%5d",q[j]);
	 printf("\n");
      }
   }
   printf("\n\nNo. of page fault: %d",count);
   getch();
   return 0;
}

/*20
7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1
3
*/
