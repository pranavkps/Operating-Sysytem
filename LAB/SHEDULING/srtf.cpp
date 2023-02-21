#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,i,j;
  cout << "ENTER NUMBER OF PROCESS :";cin >> n;
	int p[n],at[n],bt[n],ct[n],tat[n],wt[n],gc[100],c=0,b2[n];

	for(int i=0;i<n;i++){
    p[i] = 1+i;
    cout << "ENTER AT & BT :";cin >> at[i] >> bt[i];
    b2[i] = bt[i];
  }
	
	int comp = 0,lb,count =0,temp,gcin=0;
	for(comp=0;count<n;comp++){
		temp=-1;
        lb = 999;
        for(i=0;i<n;i++){
            if(at[i]<=comp && b2[i]!=0 && b2[i]<lb){
				lb = b2[i];
				temp = i;
            }
        }
		if(temp!=-1){
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
			gc[gcin++]=100;
		}
    }
	for(i=0;i<n;i++) tat[i] = ct[i] - at[i];
	for(i=0;i<n;i++) wt[i] = tat[i] - bt[i];

	printf("\n\nGantt Chart: \t");
	for(i=0;i<gcin;i++){
		if(gc[i]!=100) printf("P%d\t",gc[i]);
		else printf("Idle\t");
	}
	
	printf("\n\nPId\tAT\tBT\tCT\tTAT\tWT");
	for(int i=0;i<n;i++){
		printf("\n%d\t%d\t%d\t%d\t%d\t%d",p[i],at[i],bt[i],ct[i],tat[i],wt[i]);
	}
}

