#include<stdio.h>
#include<conio.h>


int str[100],frm[20],count=0,distance[20],i,j,k,n,size,max=0,found;

int main()
{
	printf("\nEnter no: of referrence string : ");
	scanf("%d",&n);
	printf("\nEnter referrence strings : ");
	for(i=0;i<n;i++)
		scanf("%d",&str[i]);

	printf("\nEnter size of frame : ");
	scanf("%d",&size);


	for(i=0;i<n;i++)
	{
		printf("%d :",str[i]);
		if(i<size)
		{
			frm[i]=str[i];
			for(j=0;j<=i;j++)  //mind j<=i
				printf("%3d",frm[j]);
			printf("\n");
			count++;
		}
		else
		{
			found=0;
			for(j=0;j<size;j++)
				if(str[i]==frm[j])
					found=1;

				if(found)
					printf("\n");
				else
				{
					count++;
					for(j=0;j<size;j++)
					{
						for(k=i;k<n;k++)  //mind k++
							if(str[k]==frm[j])
								break;

							distance[j]=k-i; //mind k-i
					}


					max=0;
					for(j=0;j<size;j++)
						if(distance[j]>distance[max])
							max=j;


					frm[max]=str[i];

					for(j=0;j<size;j++)
						printf("%3d",frm[j]);
					printf("\n");
				}
		}
	}

	printf("\nNumber of page fault : %d\n",count);

	getch();
}


/*20
7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1
3
*/

