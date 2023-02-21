#include<bits/stdc++.h>
using namespace std;

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
// HIGHEST NUMBER HIGHEST PRIORITY
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

    int pid[] ={1,2,3,4,5,6};
    int at[] = {0,1,2,3,4,5};
    int bt[] {4,2,3,1,2,6};
    int p[] = {4,5,6,10,9,7};
    int n = sizeof(at)/sizeof(at[0]);
    int ct[n];
    // cout << "ENTER NO OF PROCESS :";int n; cin >> n;
    // int pid[n],at[n],bt[n],p[n];
    // for(int i=0;i<n;i++){
    //     pid[i] = i+1;
    //     cout << "ENTER AT BT & PRIORITY :";cin >> at[i] >> bt[i] >> p[i];
    // }
    sort(pid,at,bt,p,n);
    int count = 0;
    int a[n],b[n];

    for(int i=0;i<n;i++) a[i] = at[i];
    for(int i=0;i<n;i++) b[i] = bt[i];

    for(int j=0;j<n;j++){
        int min = INT_MAX; int c=0;
        int index = 0;

        for(int i=0;i<n;i++){
            if(a[i]<=count && b[i]!=-1){
                count += b[i];
                b[i] = -1;
                a[i] = -1;
                c=1; index = i; break;
            }
        }
        if(c==0){
            for(int i=0;i,n;i++){
                if(a[i]!=-1 && a[i]<min){
                    min = a[i];index = i;
                }
            }
            count += min - count;
            count += b[index];
            a[index] = -1;
            b[index] = -1;
        }
        ct[index] = count;
    }
    for(int i=0;i<n;i++)
        cout << pid[i]<<" "<<at[i]<<" "<<bt[i]<<" "<<ct[i]<<endl;

}