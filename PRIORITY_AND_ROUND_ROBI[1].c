#include<stdio.h>
struct process
{
    char process_name;
    int arrival_time,burst_time,ct,waiting_time,trnarnd_time,prior,burst_time1;
}pro[10],pro1[10];
void main()
{
	struct process temp;
    int i,time=0,t1,t2,bu_t=0,largest,limit,count=0,k,pf2=0,limit2,n,pos,j,flag=0,y;
    float wait_time=0,turnaround_time= 0,average_waiting_time,average_turnaround_time;
    printf("\nEnter Total Number of Processes:\n");
    scanf("%d",&limit);
    n=limit;
    for(i=0;i<limit;i++)
    {
    	printf("\nEnter Process name:-");
    	fflush(stdin);
        scanf("%c",&pro[i].process_name);
        printf("\nEnter Details For processor %c:\n",pro[i].process_name);
        printf("Enter Arrival Time:-");
        scanf("%d",&pro[i].arrival_time);
        printf("Enter Burst Time:-");
        scanf("%d",&pro[i].burst_time);
        pro[i].burst_time1=pro[i].burst_time;
        printf("Enter Priority:\t");
        scanf("%d",&pro[i].prior);
    }
    printf("\nEnter Time Quantum for Fixed priority queue:-");
    scanf("%d",&t1);
    printf("\nEnter Time Quantum for Round Robin queue:-");
    scanf("%d",&t2);
    printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n");
    for(i=0;i<limit;i++)
    {
        pos=i;
        for(j=i+1;j<limit;j++)
        {
            if(pro[j].arrival_time<pro[pos].arrival_time)
                pos=j;
        }
        temp=pro[i];
        pro[i]=pro[pos];
        pro[pos]=temp;
    }
    time=pro[0].arrival_time;
    for(i=0;limit!=0;i++)
    {
    	while(count!=t1)
    	{
    		count++;
    		if(pro[i].arrival_time<=time)
    		{
    			for(j=i+1;j<limit;j++)
    			{
    				if(pro[j].arrival_time==time&&pro[j].prior<pro[i].prior)
    				{
    					pro1[pf2]=pro[i];
						pf2++;
    					for(k=i;k<limit-1;k++)
    						pro[k]=pro[k+1];
    					limit--;
						count=0;
    					i=j-1;
    					j--;
					}
				}
			}
			time++;
			pro[i].burst_time--;
			if(pro[i].burst_time==0)
			{
				pro[i].trnarnd_time=time-pro[i].arrival_time;
				pro[i].waiting_time=pro[i].trnarnd_time-pro[i].burst_time1;
				printf("%c\t|\t%d\t|\t%d\n",pro[i].process_name,pro[i].trnarnd_time,pro[i].waiting_time);
				wait_time+=time-pro[i].arrival_time-pro[i].burst_time1; 
    			turnaround_time+=time-pro[i].arrival_time;
    			for(k=i;k<limit-1;k++)
    				pro[k]=pro[k+1];i--;
    			limit--;
				count=t1;break;
			}
		}
		count=0;
		if(pro[i].burst_time!=0)
		{
			pro1[pf2]=pro[i];
			pf2++;
			for(k=i;k<limit-1;k++)
    			pro[k]=pro[k+1];
    		limit--;
		}
			if(i==limit-1)
				i=-1;
	}
	
	limit2=pf2;
	for(count=0;limit2!=0;) 
	{ 
		if(pro1[count].burst_time<=t2&&pro1[count].burst_time>0) 
    	{ 
    		time+=pro1[count].burst_time; 
    		pro1[count].burst_time=0; 
    		flag=1; 
    	} 
    	else if(pro1[count].burst_time>0) 
    	{ 
    		pro1[count].burst_time-=t2; 
    		time+=t2; 
    	} 
    	if(pro1[count].burst_time==0&&flag==1) 
    	{ 
    		limit2--; 
    		pro1[count].trnarnd_time=time-pro1[count].arrival_time;
			pro1[count].waiting_time=pro1[count].trnarnd_time-pro1[count].burst_time1; 
			printf("%c\t|\t%d\t|\t%d\n",pro1[count].process_name,pro1[count].trnarnd_time,pro1[count].waiting_time); 
    		turnaround_time+=time-pro1[count].arrival_time; 
    		wait_time+=time-pro1[count].arrival_time-pro1[count].burst_time1;
    		for(k=count;k<limit2;k++)
    			pro1[k]=pro1[k+1];count--;
    		flag=0; 
    	} 

    	if(count==limit2-1) 
      		count=0; 
    	else 
    		count++; 
    }
    printf("\nAverage Waiting Time= %f\n",wait_time*1.0/n); 
    printf("Avg Turnaround Time = %f",turnaround_time*1.0/n);   
}
