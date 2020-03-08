#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
  int bt[10], wt[10], tat[10], p[10], n, i, j, temp, temp2;
  float avgwt, avgtat;
  
  int sum=0;
  
  printf("Enter the number of processes: ");
  scanf("%d", &n);
  
  printf("\n\nEnter the Burst Time of processes below: \n");
  
  for(i=1; i<=n; i++)
  {
           printf("\nProcess %d: ", i);
           printf("\nBurst Time: ");
           scanf("%d", &bt[i]);
  }
  
  
  for(i=1; i<=n; i++)
  {        
           for(j=i+1; j<=n-1; j++)
           {
                      if(bt[i]>bt[j])
                      {            
                                   temp=bt[i];
                                   bt[i]=bt[j];
                                   bt[j]=temp;
                      }
           }
  }
  
  wt[1]=0;
  tat[1]=bt[1];

  for(i=2; i<=n; i++)
  {
          wt[i]=wt[i-1]+bt[i-1];
          tat[i]=wt[i]+bt[i];
  }
           
           printf("\n\n The Result after Performing Shortest Job First Scheduling");
           
           printf("\n\nBurst Time \t Waiting Time \t Turn around Time");
           
           for(i=1; i<=n; i++)
           {
                    printf("\n\n   %5d           %5d           %5d", bt[i], wt[i], tat[i]);
           }
           
           
           for(i=1; i<=n; i++)
           {
                    sum=sum+wt[i];
                    
           }
           avgwt=(float)sum/n;
           printf("\n\nAvarage Waiting Time is: %.2f", avgwt);
           
           for(i=1, sum=0; i<=n; i++)
           {
                    sum=sum+tat[i];
                    
           }
           avgtat=(float)sum/n;
           printf("\n\nAvarage Turn around Time is: %.2f", avgtat);
           
           
  system("PAUSE");	
  return 0;
}
