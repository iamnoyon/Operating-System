

#include<stdio.h>
#include<conio.h>
#define true 1
#define false 0

int main()
{

   int avail[200],max[200][200],alloc[200][200],need[200][200];
   int work[200],finish[200],  i,j,  n,m,  safe;


   printf("\nEnter num of process (n): ");
   scanf("%d",&n);

    printf("\nEnter num of resource type (m): ");
    scanf("%d",&m);


   //===> allocation[][] table
   printf("\nEnter allocation table:\n");
   for( i=0; i<n; i++ )
        for( j=0; j<m; j++ )
        
	    scanf("%d",&alloc[i][j]);


   //===> max[][] table
   printf("\nEnter max table:\n");
   for( i=0; i<n; i++ )
        for( j=0; j<m; j++ )
	    scanf("%d",&max[i][j]);


   //===> available[][] table
   printf("\nEnter available table:\n");
   for( i=0; i<m; i++ )
        scanf("%d",&avail[i]);


   //===> need[][] calculation
   for( i=0; i<n; i++ )
        for( j=0; j<m; j++ )
	    need[i][j] = max[i][j]-alloc[i][j];


//===> safty algorithm <===\\




   // ===> step_01
   for( i=0; i<m; i++ )  work[i] = avail[i];    // work[m] = available[m]
   for( i=0; i<n; i++ )  finish[i] = false;     // finish[n] = false

   // ===>  step_02
   while ( true ) {

         safe = false;
         for (i=0; i<n; i++){

              if(finish[i]==true ) continue;
              for(j=0; j<m; j++)
                   if(need[i][j] > work[j] )continue;

              // ===>  step_03
              for(j=0; j<m; j++)
                   work[j] = work[j] + alloc[i][j] ;
              finish[i] = true;

              safe = true;
              break;
              }
         if(!safe)  break;
         }

   // ===>  step_04
   safe = true;
   for( i=0; i<n; i++)
        if(finish[i] == false)
        safe = false;

   if( safe )  printf("\nThe system is in a safe state\n");
   else        printf("\nThe system is not in a safe state\n");

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
