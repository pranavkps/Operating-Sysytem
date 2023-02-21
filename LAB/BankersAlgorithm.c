#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//Banker's algorithm
void main(){
	int nop,nor;
	printf("Enter no of processors: ");
	scanf("%d",&nop);
	printf("Enter no of resources: ");
	scanf("%d",&nor);
	int p[nop],r[nor],i,j;
	int allo[nop][nor],max[nop][nor],need[nop][nor],avail[nor],visit[nop];
	printf("Enter no of allocated resourses of each type for processes(allocation matrox): \n");
	for(i=0;i<nop;i++){
		printf("P%d :",i);
		for(j=0;j<nor;j++){
			scanf("%d",&allo[i][j]);
		}
	}
	printf("Enter maximum no of allocation possible(max matrix): \n");
	for(i=0;i<nop;i++){
		printf("P%d :",i);
		for(j=0;j<nor;j++){
			scanf("%d",&max[i][j]);
		}
	}
	printf("Enter no of available resources: ");
	for(j=0;j<nor;j++){
		scanf("%d",&avail[j]);
	}
	for(i=0;i<nop;i++){
		for(j=0;j<nor;j++){
			need[i][j] = max[i][j]- allo[i][j];
		}
	}
	i=0;
	int flag,count=nop;
	while(count>0){
		flag = 0;
		if(visit[i]!=1){
			flag = 1;
		for(j=0;j<nor;j++){
			if(need[i][j]>avail[j] ){
				flag = 0;
				break;
			}
		}
		}
		if(flag){
			visit[i]=1;
			for(j=0;j<nor;j++)
			avail[j]+=allo[i][j];
			p[nop-count] = i;
			count--;
		}
		i=(i+1)%nop;
	}
	printf("Safe sequence: ");
	for(i=0;i<nop;i++)
	printf("P%d  ",p[i]);
}

