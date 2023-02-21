#include<bits/stdc++.h>
using namespace std;

int find(int a[],int k,int n){
  int x;
  for(int i=0;i<n;i++){
    if(a[i]<=k) x=i;
  }
  return x;
}

int main(){
  cout << "Enter the size of queue :";int n;cin>> n;
  cout << "Enter order request from lower bound to upperbound :";
  n = n+2; int a[n];

  for(int i=0;i<n;i++) cin >> a[i]; 
  cout << "enter position of the arm :";int k;cin >> k;
  int x; cout << "Enter 1 to move RIGHT 2 to move LEFT :"; cin >> x;

  sort(a,a+n);
  int index = find(a,k,n);

  int count = 0;
  if(x==1)
    count = abs(a[n-1]-k) + abs(a[n-1]-a[0]) + abs(a[0]-a[index]);
  else
    count = abs(k-a[0]) + abs(a[n-1]-a[0]) +abs(a[n-1]-a[index]);

  cout << "HEAD MOMENT :" << count;
}