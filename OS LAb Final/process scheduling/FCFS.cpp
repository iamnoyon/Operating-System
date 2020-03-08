 //FCFS ALGORITHM
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
int main()
{
   char p[10][5],s[10];
   int n,i;
   float tot=0;//total turn around time
   float wt[10]; //waiting time
   float pt[10];// process time
   float at[10]={0};//araival time
   float tat=0;//total araival time
   float nwt[10];//waiting time for processes reached some time after (time 0)(waiting time-arraival time)
   float ntat[10];//time one process stay in the ready queue wt[i]+pt[i]-at[i]
   float avg_wt=0,avg_at=0;

	int x=DETECT, y=0;
	initgraph(&x,&y,"..//bgi");

	printf("Enter no of processes: ");
	scanf("%d",&n);
	printf("Enter process \nname\tarrival_time\t bust_time\n ");
	for(i=0;i<n;i++)
		scanf("%s%f%f",&p[i],&at[i],&pt[i]);

	wt[0]=0;
	for(i=1;i<n;i++)
		wt[i]=wt[i-1]+pt[i-1];

	for(i=0;i<n;i++){
	    nwt[i]=wt[i]-at[i];
	    tot=tot+nwt[i];
	}

	for(i=0;i<n;i++){
	    ntat[i]=wt[i]+pt[i]-at[i];
	    tat=tat+ntat[i];
	   }
	avg_at=tat/n;
	avg_wt=(float)tot/n;
	printf("p_name\t p_time\t w_time\tarrival time\n");
	for(i=0;i<n;i++)
	printf("%s\t%.2f\t%.2f\t%.2f\n",p[i],pt[i],nwt[i],at[i]);

	printf("total turn arround time=%.2f\n",tat);
	printf("Avg turn arround time=%.2f\n",avg_at);
	printf("total waiting time=%.2f\n",tot);
	printf("Avg waiting time=%.2f",avg_wt);

	int x1,x2,y1,y2;
    x1=200;
    y1=250;
    y2=300;

   for(i=0; i<n; i++)
   {
      x2=x1+pt[i]*10;
      setcolor(4);
      rectangle(x1,y1,x2,y2);
      setcolor(5);
      outtextxy(x1+(x2-x1)/2,y1-20,p[i]);
      setcolor(3);
      sprintf(s,"%.2f",wt[i]);
      outtextxy(x1,y2+10,s);
      x1=x2;
   }
   getch();
   closegraph();
return 0;
}

/*                         sum(turn around time n....wt[i]+pt[i]-at[i];)
avg turn around time = ...............................
                               number of process

                       sum(waiting time.......wt[i]-at[i];)
 avg  waiting time = .................................
                        number of process

*/


/*sample input
number of process: 5
p1 0 8
p5 2.5 6
p2 0 5
p4 2 10
p3 1 4
*/

