#include<bits/stdc++.h>
using namespace std;

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
// HIGHEST NUMBER HIGHEST PRI
void sort(int pid[],int at[],int bt[],int p[],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            if(p[j]<p[j+1]){
                swap(&p[j],&p[j+1]);
                swap(&at[j],&at[j+1]);
                swap(&pid[j],&pid[j+1]);
                swap(&bt[j],&bt[j+1]);
            }
        }
    }
}

int main(){

    // int pid[] ={1,2,3,4,5,6};
    // int at[] = {0,1,2,3,4,5};
    // int bt[] {4,2,3,1,2,6};
    // int p[] = {4,5,6,10,9,7};
    // int n = sizeof(at)/sizeof(at[0]);
    cout << "ENTER NO OF PROCESS :";int n; cin >> n;
    int pid[n],at[n],bt[n],p[n];
    int ct[n];
    for(int i=0;i<n;i++){
        pid[i] = i+1;
        cout << "ENTER AT BT & PRIORITY :";cin >> at[i] >> bt[i] >> p[i];
    }
    // int ct[n];

    sort(pid,at,bt,p,n);
    // int count = 0;
    int a[n],b[n];

    for(int i=0;i<n;i++) a[i] = at[i];
    for(int i=0;i<n;i++) b[i] = bt[i];

    int count = 0;int s = n;

    while(s!=0){
        int c = 0,min = INT_MAX;

        for(int i=0;i<n;i++){
            if(a[i]<=count && b[i]!=-1){
                b[i]--; count++; c=1;
            }
            if(b[i]==0){
                ct[i]=count; b[i]--; s--;a[i]=-1;
            }
            if(c==1)
                break;
        }
        if(c==0){
            for(int i=0;i<n;i++){
                if(b[i]!=-1 && a[i]<min){
                    min = a[i]; 
                }
            }
            count += min - count;
        }
    }
    for(int i=0;i<n;i++)
        cout << pid[i]<<" "<<at[i]<<" "<<bt[i]<<" "<<ct[i]<<endl;

}