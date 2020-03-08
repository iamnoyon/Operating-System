#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define true 1
#define false 0

int i,j,n,m;
int avail[20],max[20][20],alloc[20][20],need[20][20];
int work[20],finish[20],request[20];




int isSafe()
   {
   int safe;
   for( i=0; i<m; i++ ) work[i] = avail[i];
   for( i=0; i<n; i++ ) finish[i] = false;

   while(1)
       {
	   safe=false;
       for( i=0; i<n; i++)
	        {
	        if(finish[i] == true) continue;
	        for( j=0; j<m; j++ ) if(need[i][j] > work[j]) continue;
	        for( j=0; j<m; j++ ) work[i] = work[i]+alloc[i][j];
	        finish[i] = true;
		    safe=true;  break;
            }
	   if(!safe) break;
       }

   safe = true;
   for( i=0; i<n; i++ ) if( finish[i] == false ) safe = false;
   return safe;
   }






int main()
{

   printf("\nEnter num of process (n): ");
   scanf("%d",&n);

    printf("\nEnter num of resource type (m): ");
    scanf("%d",&m);


   printf("\nEnter allocation table:\n");
   for( i=0; i<n; i++ )
        for( j=0; j<m; j++ )
	    scanf("%d",&alloc[i][j]);

   printf("\nEnter max table:\n");
   for( i=0; i<n; i++ )
        for( j=0; j<m; j++ )
        scanf("%d",&max[i][j]);

   printf("\nEnter available table:\n");
   for( i=0; i<m; i++ ) scanf("%d",&avail[i]);

   for( i=0; i<n; i++ )
      for( j=0; j<m; j++ ) need[i][j] = max[i][j]-alloc[i][j];


   //safty checking
   if(!isSafe())
      {
      printf("\nThe system is not safe\n"); getch();
      exit(0);
      }
   printf("\nThe system is safe\n");


   printf("\nEnter process num for resource request: ");
        scanf("%d",&i);
        i = i-1;

   printf("\nEnter requested resources: ");
   for( j=0; j<m; j++ )
        scanf("%d",&request[j]);


   //resource request algorithm : step_01
   for( j=0; j<m; j++ )
        if( request[j] > need[i][j] )
	        {
	        printf("\nRequest is greater than need\n");getch();
	        exit(0);
	        }

   //resource request algorithm : step_02
   for( j=0; j<m; j++ )
        if( request[j] > avail[j] )
	        {
	        printf("\nP%d must wait, since resources are not available\n",i);getch();
	        exit(0);
	        }

   //resource request algorithm : step_03
   for( j=0; j<m; j++ )
        {
        avail[j] = avail[j] - request[j];
        alloc[i][j] = alloc[i][j] + request[j];
        need[i][j] = need[i][j] - request[j];
        }

   //resource request algorithm : result
   if( isSafe() ) printf("\n\nThe system is safe after request for p%d is granted\n\n",i+1);
   else printf("\nThe request for p%d is not granted because the system is not safe\n",i+1);

   getch();
   return 0;
}

/*

5 3

0 1 0
2 0 0
3 0 2
2 1 1
0 0 2

7 5 3
3 2 2
9 0 2
2 2 2
4 3 3

3 3 2


*/
