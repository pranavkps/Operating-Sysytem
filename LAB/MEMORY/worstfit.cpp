#include<bits/stdc++.h>
using namespace std;

int min(int m[],int visit[],int n,int k){
    int index=-1,max=INT_MIN;
    for(int i=0;i<n;i++){
        if(visit[i]!=-1 && m[i]>=k && m[i]>max){
            index = i;max = m[i];
        }
    }
    return index;
}

int main(){
    cout << "Enter the number of memory blocks :";
    int n; cin >> n; int m[n];
    int vist_m[n],res[n];
    for(int i=0;i<n;i++) cin >> m[i];
    cout << "Enter the number of Processes :";
    int p; cin >> p; int pi[p];
    for(int i=0;i<p;i++) cin >> pi[i];

    int i=0,j=0;
    int internal_flagmantation = 0;
    int external_flagmantation = 0;

    for(int i=0;i<p;i++){
        int index = min(m,vist_m,n,pi[i]);
        if(index != -1){
            internal_flagmantation += m[index] - pi[i];
            vist_m[index] = -1;
            res[index] = pi[i];
            pi[i] = -1;
        }
    }
    int c1=0, c2=0;
    for(int i=0;i<n;i++){
        if(vist_m[i]!= -1){
            c1+=m[i];
            res[i] = -1;
        }
    }
    for(int i=0;i<p;i++) if(pi[i]!=-1) c2+=pi[i];

    if(c1>=c2 && c2!=0) external_flagmantation = c1;
    cout << "RESULT MEMORY BLOCKS :";
    for(int i=0;i<n;i++) cout << res[i] << " ";
    
    cout << "\nINTERNAL FLAGMANTATION :" << internal_flagmantation << endl;
    cout << "ENTERNAL FLAGMANTATION :" << external_flagmantation;
}