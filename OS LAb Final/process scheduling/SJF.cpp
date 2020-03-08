//SJF ALGORITHM
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<string.h>
#include<stdlib.h>

typedef struct{
  char name[10];
  float bust_time,at;
}string;

string process[20];
int n,i,j;
//float tot=0,wt[10],pt[10],at[10]={0},tat=0,nwt[10],ntat[10];

   float tot=0;//total turn around time
   float wt[10]; //waiting time
   float pt[10];// process time
   float at[10]={0};//araival time
   float tat=0;//total araival time
   float nwt[10];//waiting time for processes reached some time after (time 0)(waiting time-arraival time)
   float ntat[10];//time one process stay in the ready queue wt[i]+pt[i]-at[i]

float avg_wt=0,avg_at=0;
int x1,x2,y1,y2;
char s[20];

int main(){
    int driver=0,mode,choice;
    initgraph(&driver,&mode,"");
    printf("\nHow many process:");
    scanf("%d",&n);
    printf("\nEnter process \nname\tarrival_time\tbust time\n");
    for(i=0;i<n;i++)
        scanf("%s%f%f",&process[i].name,&process[i].at,&process[i].bust_time);

    for(i=0;i<n;i++)
        for(j=0;j<n-i-1;j++)
        {
            if(process[j].bust_time>process[j+1].bust_time)
                {
                float b,a;
                strcpy(s,process[j].name);
                a=process[j].at;
                b=process[j].bust_time ;
                strcpy(process[j].name,process[j+1].name);
                process[j].bust_time=process[j+1].bust_time;
                process[j].at=process[j+1].at;
                strcpy(process[j+1].name,s);
                process[j+1].bust_time=b;
                process[j+1].at=a;
                }
            }

        wt[0]=0;
        for(i=1;i<n;i++)
		wt[i]=wt[i-1]+process[i-1].bust_time;

        for(i=0;i<n;i++){
            nwt[i]=wt[i]-process[i].at;
            tot=tot+nwt[i];
        }

        for(i=0;i<n;i++){
            ntat[i]=wt[i]+process[i].bust_time-process[i].at;
            tat=tat+ntat[i];
            }

        avg_at=tat/n;
        avg_wt=(float)tot/n;
        nwt[0]=0;
        printf("p_name\t p_time\t w_time\tarrival time\n");
        for(i=0;i<n;i++)
            printf("%s\t%.2f\t%.2f\t%.2f\n",process[i].name,process[i].bust_time,nwt[i],process[i].at);

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
        x2=x1+process[i].bust_time*10;
        setcolor(4);
        rectangle(x1,y1,x2,y2);
        setcolor(5);
        outtextxy(x1+(x2-x1)/2,y1-20,process[i].name);
        setcolor(3);
        sprintf(s,"%.2f",wt[i]);
        outtextxy(x1,y2+10,s);
        x1=x2;
        }

        getch();
    closegraph();
  return 0;
}
/*sample input
number of process:5
p1 0 8
p5 2.5 6
p2 0 5
p4 2 10
p3 1 4
*/
