//first come first serve

#include<bits/stdc++.h>
using namespace std;

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void sort(int pid[],int at[],int bt[],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            if(at[j]>at[j+1]){
                swap(&at[j],&at[j+1]);
                swap(&pid[j],&pid[j+1]);
                swap(&bt[j],&bt[j+1]);
            }
        }
    }
}
int main(){
    int n;
    // cout << "ENTER NO OF PROCESS :";cin >> n;
    int pid[] = {1,2,3,4,5,6};
    int at[] = {4,8,6,5,2,7};
    int bt[] = {4,2,3,3,1,7};
    n = sizeof(at)/sizeof(at[0]);
    // int pid[n],at[n],bt[n];
    // for(int i=0;i<n;i++){
    //     pid[i] =i+1;
    //     cout << "ENTER AT & BT :";cin>> at[i]>>bt[i];
    // }
    int ct[n+1];

    sort(pid,at,bt,n);
    int count = at[0];
    for(int i=0;i<n;i++){
        if(at[i]>count)
            count += at[i] - count;    
        count += bt[i];
        ct[pid[i]-1] = count;
    }
    sort(at,pid,bt,n);
    for(int i=0;i<n;i++)
        cout << pid[i] << " " << at[i] << " " << bt[i] << " "<< ct[i] << endl;
}