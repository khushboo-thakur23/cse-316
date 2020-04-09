#include<stdio.h>

struct take_input
{
	int process_id,arrival_time,burst_time,completion_time,rqd_burst_time;//pid
}a1[10], a2[10], a3[10];//f s m

int num, a=0, b=0, c=0,time_quant;//n fc sc mc quanta
void Combine_process()
{
	int input_a=0,input_b= 0;
	if(a==0){
		while(input_a!=b){
			a3[c]= a2[input_a];
			input_a++;
			c++;
		}
	}
	else if(b==0){
		while(input_b!=a){
			a3[c]= a1[input_b];
			input_b++;
			c++;
		}
	}
	else if(a!=0 && b!=0)
	{
		while(input_a<b && input_b<a)
		{
			
			if(a1[input_b].arrival_time > a2[input_a].arrival_time)
			{
				a3[c]= a2[input_a];
				c++;
				input_a++;
			}
			else if(a1[input_b].arrival_time < a2[input_a].arrival_time)
			{
				a3[c]= a1[input_b];
				c++;
				input_b++;
			}
			else if(a1[input_b].arrival_time == a2[input_a].arrival_time)
			{
				a3[c] = a1[input_b];
				c++;
				input_b++;
				a3[c]= a2[input_a];
				c++;
				input_a++;
			}	
		}
		int j=a+b;
		if(c!=j)
		{
			if(b!=input_a)
			{
				while(input_a!=b)
				{
					a3[c]= a2[input_a];
					input_a++;
					c++;
				}
			}
			else if(a!=input_b)
			{
				while(input_b!=a)
				{
					a3[c]= a1[input_b];
					input_b++;
					c++;
				
				}
			}
			
		}
	}	
	else
	{
		printf("\n\nNo Jobs...\n\n");
	}
}
void Take_input()
{
	int flag,i,arrival_time2;
	printf("Enter the  no of Process or Queries: ");
	scanf("%d", &num);
	if(num!=0)
	{
		printf("\nEnter Time Quantum for each Process or query: ");
		scanf("%d", &time_quant);
		printf("\nSelect from following : \n");
		for(i=0; i<num; i++)
		{
			printf("\n1) Faculty ");
			printf("\n2) Student ");
			scanf("%d", &flag);
			if(flag!=1)
			{
				printf("Process ID : ");
				scanf("%d",&a2[b].process_id);
				printf("Arrival Time: ");
				scanf("%d", &arrival_time2); 
				if(arrival_time2<1000 || arrival_time2>2000)
				{
					printf("\nEnter Arrival time between 1000 and 2000\n");
					Take_input();
				}
				else
				{
					a2[b].arrival_time= arrival_time2-1000;
				}
				printf("Burst Time: ");
				scanf("%d", &a2[b].burst_time);
				a2[b].rqd_burst_time= a2[b].burst_time;
				b++;
			}
			else
			{
				printf("Process Id: ");
				scanf("%d", &a1[a].process_id);
				printf("Arrival Time: ");
				scanf("%d", &arrival_time2);
				if(arrival_time2<1000 || arrival_time2>2000)
				{
					printf("\nEnter Arrival time between 1000 and 2000");
					Take_input();
				}
				else
				{
				a1[a].arrival_time= arrival_time2-1000;
				}
				printf("Burst Time: ");
				scanf("%d", &a1[a].burst_time);	
				a1[a].rqd_burst_time= a1[a].burst_time; 
				a++;
			} 
			
		}
	}
	else
	{
		printf("\n No Process or queries\n");
	}	
}
void Output_function()
{
	int i=0,total_time=0,sum=0; 
	float avg;
	printf("\nExecution Result : \n");
	printf("\nProcess ID\tArrival Time\tBurst Time\tCompletion Time\tTurn Around Time\tWaiting Time");
	for(i; i<c; i++){
		printf("\n%d\t%d\t%d\t%d\t%d\t\t%d",
		a3[i].process_id, (a3[i].arrival_time+1000), a3[i].burst_time, (a3[i].completion_time+1000), (a3[i].completion_time-a3[i].arrival_time), ((a3[i].completion_time-a3[i].arrival_time)- a3[i].burst_time));
		total_time= a3[i].completion_time;
		sum+= (a3[i].completion_time-a3[i].arrival_time);
	}
	printf("\nTime used for queries: %d", total_time);
	avg = sum/c;
	printf("\nAverage time : %f", avg);	
}
void Round_Robin_algo()
{
	int arrival_time2= a3[0].arrival_time, flag=0, d=0, i, e;//time mark cc rc
	
	while(arrival_time2!=100 && d!=c)
	{
		for(i=0; i<=0; i++)
		{
			if(a3[i].rqd_burst_time > time_quant)
			{
				arrival_time2=arrival_time2+time_quant;
				a3[i].rqd_burst_time=a3[i].rqd_burst_time-time_quant;
			}
			else if(a3[i].rqd_burst_time <=time_quant && a3[i].rqd_burst_time !=0)
			{
				arrival_time2=arrival_time2+a3[i].rqd_burst_time;
				a3[i].rqd_burst_time =0;
				a3[i].completion_time = arrival_time2;
				d++;
			}
		}
		int flag2 =flag+1;
		for(e= flag2; e<c; e++)
		{
			if(a3[e].arrival_time <= arrival_time2){
				flag++;
			}
		}
	}	
}



void main()
{
	Take_input();
	Combine_process();
	Round_Robin_algo();
	Output_function();
}
