#include<bits/stdc++.h>
using namespace std;

int main(){
  cout << "Enter no of elements in queue :";int n; cin >> n;
  int a[n];
  cout << "Enter Order Request :";
  for(int i=0;i<n;i++) cin >> a[i];
  cout << "Enter Current Position of arm :";int k; cin>> k;
  int count = 0 ;
  for(int i=0;i<n;i++){
    count += abs(k-a[i]);
    k = a[i];
  }
  cout << "NO OF HEAD MOMENTS :" << count;
}