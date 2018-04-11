#include<stdio.h>
#include<conio.h>
#include<stdio.h>
struct process
{
    char process_name;
    int a_t,b_t,c_t,w_t,t_t,prior,b_t1;
}pro[10],pro1[10];
void main()
{
	struct process temp;
    float w_t=0,t_t= 0,a_w_t,a_t_t;
    int i,time=0,t1,t2,bu_t=0,largest,L,C=0,k,pf2=0,L2,n,pos,j,flag=0,y;
    printf("\nEnter total number of processes:\n");
    scanf("%d",&L);
    n=L;
    for(i=0;i<L;i++)
    {
    	printf("\nEnter process name:-");
    	fflush(stdin);
        scanf("%c",&pro[i].process_name);
        printf("\nEnter details for processor %c:\n",pro[i].process_name);
        printf("Enter arrival time:-");
        scanf("%d",&pro[i].a_t);
        printf("Enter burst time:-");
        scanf("%d",&pro[i].b_t);
        pro[i].b_t1=pro[i].b_t;
        printf("Enter priority:\t");
        scanf("%d",&pro[i].prior);
    }
    printf("\nEnter time quantum for fixed priority queue:-");
    scanf("%d",&t1);
    printf("\nEnter time quantum for round robin queue:-");
    scanf("%d",&t2);
    printf("\n\nProcess\t|turnaround time|waiting time\n\n");
    for(i=0;i<L;i++)
    {
        pos=i;
        for(j=i+1;j<L;j++)
        {
            if(pro[j].a_t<pro[pos].a_t)
                pos=j;
        }
        temp=pro[i];
        pro[i]=pro[pos];
        pro[pos]=temp;
    }
    time=pro[0].a_t;
    for(i=0;L!=0;i++)
    {
    	while(C!=t1)
    	{
    		C++;
    		if(pro[i].a_t<=time)
    		{
    			for(j=i+1;j<L;j++)
    			{
    				if(pro[j].a_t==time&&pro[j].prior<pro[i].prior)
    				{
    					pro1[pf2]=pro[i];
						pf2++;
    					for(k=i;k<L-1;k++)
    						pro[k]=pro[k+1];
    					L--;
						C=0;
    					i=j-1;
    					j--;
					}
				}
			}
			time++;
			pro[i].b_t--;
			if(pro[i].b_t==0)
			{
				pro[i].t_t=time-pro[i].a_t;
				pro[i].w_t=pro[i].t_t-pro[i].b_t1;
				printf("%c\t|\t%d\t|\t%d\n",pro[i].process_name,pro[i].t_t,pro[i].w_t);
				w_t+=time-pro[i].a_t-pro[i].b_t1; 
    			t_t+=time-pro[i].a_t;
    			for(k=i;k<L-1;k++)
    				pro[k]=pro[k+1];i--;
    			L--;
				C=t1;break;
			}
		}
		C=0;
		if(pro[i].b_t!=0)
		{
			pro1[pf2]=pro[i];
			pf2++;
			for(k=i;k<L-1;k++)
    			pro[k]=pro[k+1];
    		L--;
		}
			if(i==L-1)
				i=-1;
	}
	
	L2=pf2;
	for(C=0;L2!=0;) 
	{ 
		if(pro1[C].b_t<=t2&&pro1[C].b_t>0) 
    	{ 
    		time+=pro1[C].b_t; 
    		pro1[C].b_t=0; 
    		flag=1; 
    	} 
    	else if(pro1[C].b_t>0) 
    	{ 
    		pro1[C].b_t-=t2; 
    		time+=t2; 
    	} 
    	if(pro1[C].b_t==0&&flag==1) 
    	{ 
    		L2--; 
    		pro1[C].t_t=time-pro1[C].a_t;
			pro1[C].w_t=pro1[C].t_t-pro1[C].b_t1; 
			printf("%c\t|\t%d\t|\t%d\n",pro1[C].process_name,pro1[C].t_t,pro1[C].w_t); 
    		t_t+=time-pro1[C].a_t; 
    		w_t+=time-pro1[C].a_t-pro1[C].b_t1;
    		for(k=C;k<L2;k++)
    			pro1[k]=pro1[k+1];C--;
    		flag=0; 
    	} 

    	if(C==L2-1) 
      		C=0; 
    	else 
    		C++; 
    }
    printf("\nAverage waiting time= %f\n",w_t*1.0/n); 
    printf("Avg turnaround time = %f",t_t*1.0/n);   
}
