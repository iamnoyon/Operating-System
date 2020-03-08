#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#define N 20

typedef struct process{
    char n[25];
    float at,bt,wt,tt;} A;
A pro[101],temp[101],T;

typedef struct{
    int p;
    float t;} B;

    B chart[101];

    int done[101],PN,pn;

int main()
    {
    int gdriver=DETECT,gmode;
    initgraph(&gdriver,&gmode,"..\\bgi");
    int i,j,pn,x1,y1,x2,y2;
    float tq,twt,ttt,t;
    char str[5];
    printf("Enter the number of processes : ");

    scanf("%d",&pn);
    printf("\nEnter process \nname\tarrival_time\tbust time\n");
    for(i=1;i<=pn;i++)
        scanf("%s%f%f",pro[i].n,&pro[i].at,&pro[i].bt);
    printf("\nEnter the time quantam : ");
        scanf("%f",&tq);

    for(i=pn;i>=2;i--)
        for(j=1;j<i;j++)
            if(pro[j].at>pro[j+1].at){
                T=pro[j];
                pro[j]=pro[j+1];
                pro[j+1]=T;}

    for(i=1;i<=pn;i++)
        temp[i]=pro[i];
    t=twt=ttt=PN=0;j=1;
    while(PN!=pn)
    {
	for(i=1;i<=pn;i++)
            if((!done[i])&&(pro[i].at<=t))
            {
                if(tq<temp[i].bt){
                    temp[i].bt-=tq;
                    t+=tq;}
                else
                {
                    t+=temp[i].bt;
                    temp[i].bt=0;
                    done[i]=1;
                    PN++;
                    pro[i].wt=t-(pro[i].bt+pro[i].at);
                    twt+=pro[i].wt;
                    pro[i].tt=t-pro[i].at;
                    ttt+=pro[i].tt;
                }
                chart[j].p=i;
                chart[j].t=t;
                j++;
            }
    }
    printf("\nAfter calculation, we get :\n\tName Arrival Burst Waiting Turnaround\n");
    for(i=1;i<=pn;i++)
	printf("\t%s\t%.2f\t%.2f\t%.2f\t%.2f\n",pro[i].n,pro[i].at,pro[i].bt,pro[i].wt,pro[i].tt);

	printf("\nAfter calculation, we get :\n");
	printf("\nTotal waiting time = %.2f\n",twt);
	printf("Average waiting time = %.2f\n",twt/pn);
	printf("Total turnaround time = %.2f\n",ttt);
	printf("Average turnaround time = %.2f\n",ttt/pn);

    x1=20;y1=400;
    setcolor(6);
    outtextxy(x1-5,y1-15,"0");
    for(i=1;i<j;i++)
    {
	x2=(x1+(N*(chart[i].t-chart[i-1].t)));
	y2=(y1+40);
	sprintf(str,"%.2f",chart[i].t);
	outtextxy(x2-5,y1-15,str);
	outtextxy(((x1+x2)/2)-5,y1+5,pro[chart[i].p].n);

	rectangle(x1,y1,x2,y2);
	x1=x2;
    }
    getch();
    return 0;
}


