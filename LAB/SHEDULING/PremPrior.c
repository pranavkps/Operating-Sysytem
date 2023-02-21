#include<stdio.h>

void main(){
	int n,i,j;
	printf("Enter no of processes: ");
	scanf("%d",&n);
	int p[n],at[n],bt[n],ct[n],tat[n],wt[n],gc[100],c=0,pr[n],b2[n];
	printf("Enter the process ids: ");
	for(i=0;i<n;i++){
		scanf("%d",&p[i]);
	}
	printf("Enter the Priorities: ");
	for(i=0;i<n;i++){
		scanf("%d",&pr[i]);
	}
	printf("Enter the arrival times: ");
	for(i=0;i<n;i++){
		scanf("%d",&at[i]);
	}
	printf("Enter the Burst times: ");
	for(i=0;i<n;i++){
		scanf("%d",&bt[i]);
		b2[i] = bt[i];
	}
	//sort(p,at,bt,pr,n);
	int comp = 0,lb,count = 0,nfp,temp=-1,gcin=0;
	for(comp=0;count<n;comp++){
        lb = -1;
        temp = -1;
        for(i=0;i<n;i++){
            if(at[i]<=comp && b2[i]!=0 && pr[i]>lb){
                lb = pr[i];
                temp = i;
            }
        }
        if(temp != -1){
            if(gc[gcin-1]!=p[temp])
			gc[gcin++] = p[temp];
			b2[temp]--;
			if(b2[temp]==0){
				count++;
				ct[temp] = comp+1;
			}
        }
        else{
            if(gc[gcin-1]!=100)
            gc[gcin++] = 100;
        }
    }
	for(i=0;i<n;i++)
		tat[i] = ct[i] - at[i];
	for(i=0;i<n;i++)
		wt[i] = tat[i] - bt[i];
	printf("\n\nGantt Chart: \t");
	for(i=0;i<gcin;i++){
		if(gc[i]!=100){
			printf("P%d\t",gc[i]);
		}
		else
			printf("Idle\t");
	}
	printf("\n\nPId\tAT\tBT\tCT\tTAT\tWT");
	for(i=0;i<n;i++){
		printf("\n%d\t%d\t%d\t%d\t%d\t%d",p[i],at[i],bt[i],ct[i],tat[i],wt[i]);
	}
}
