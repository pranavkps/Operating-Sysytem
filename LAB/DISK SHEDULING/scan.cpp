#include<bits/stdc++.h>
using namespace std;

int main(){
  cout << "Enter the size of queue :";int n;cin>> n;
  cout << "Enter order request :";
  n = n+2; int a[n];
   
  for(int i=1;i<n-1;i++) cin >> a[i]; 
  cout << "ENTER THE LOWER LIMIT AND UPPER LIMIT OF THE SCAN ELEVATOR :";
  cin >> a[0] >> a[n-1];
  cout << "enter position of the arm :";int k;cin >> k;
  int x; cout << "Enter 1 to move RIGHT 2 to move LEFT :"; cin >> x;

  sort(a,a+n);
  int count = 0;
  if(x==1)
    count = abs(a[n-1]-k) + abs(a[n-1]-a[1]);
  else
    count = abs(k-a[0]) + abs(a[n-2]-a[0]);

  cout << "HEAD MOMENT :" << count;
}