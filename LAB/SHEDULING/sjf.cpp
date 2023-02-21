#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
  cout << "ENTER NUMBER OF PROCESS :";cin >> n;
	int p[n],at[n],bt[n],ct[n],tat[n],wt[n],gc[100],c=0,v[n];
  for(int i=0;i<n;i++) v[i]=0;

  for(int i=0;i<n;i++){
    p[i] = i+1;
    cout << "ENTER AT & BT :";cin >> at[i] >> bt[i];
  }
	
	int comp = 0,lb,count = -1,nfp,temp=-1,gcin=0;
	while(count<n-1){
        lb = 1000;
        temp = -1;
        for(int i=0;i<n;i++){
            if(at[i]<=comp && v[i]==0 && bt[i]<lb){
                lb = bt[i];
                temp = i;
            }
        }
        if(temp != -1){
            v[temp] = 1;
            ct[temp] = comp + bt[temp];
            comp = ct[temp];
            count++;
            gc[gcin++] = p[temp];
        }
        else{
            if(gc[gcin-1]!=100)
            gc[gcin++] = 100;
            comp++;
        }
    }
    
    for(int i=0;i<n;i++){
      tat[i] = ct[i] - at[i];
      wt[i] = tat[i] - bt[i];
    }
	// printf("\n\nGantt Chart: \t");

	// for(int i=0;i<gcin;i++){
	// 	if(gc[i]!=100) printf("P%d\t",gc[i]);
	// 	else printf("Idle\t");
	// }
	printf("\n\nPId\tAT\tBT\tCT\tTAT\tWT");
	for(int i=0;i<n;i++){
		printf("\n%d\t%d\t%d\t%d\t%d\t%d",p[i],at[i],bt[i],ct[i],tat[i],wt[i]);
	}
}
