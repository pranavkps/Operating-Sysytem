#include<bits/stdc++.h>
using namespace std;

int main(){
  cout << "ENter no o process in disk :";int n;cin >> n;
  cout << "Enter Order requests :";int a[n];
  for(int i=0;i<n;i++) cin >> a[i];
  cout << "Enter current position of arm :";int k;cin >> k;
  int visit[n]={0};
  int count = 0;

  for(int i=0;i<n;i++){
    int min = INT_MAX;
    int index = i;
    for(int j=0;j<n;j++){
      if(abs(k-a[j])<=min && visit[j]!=-1){
        min = abs(k-a[j]);
        index = j;
      }
    }
    count += abs(k-a[index]);
    k = a[index];
    visit[index] = -1;
  }
  cout << "HEAD MOMENTS :" << count;
}