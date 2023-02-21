#include<bits/stdc++.h>
using namespace std;

int main(){
  int n; 
  cout << "ENTER SIZE OF QUEUE :";cin >> n;
  int a[n]; cout << "ENTER ORDER RESPONSE :";
  for(int i=0;i<n;i++) cin >> a[i];

  cout <<"ENTER CURRENT POSITION OF THE ARM :";int k ;cin >> k;
  cout << "ENETR 1-MOVE RIGHT 2-MOVE LEFT :";int x; cin >> x;

  sort(a,a+n);
  int count =0;
  if(x==1)
    count = abs(k-a[n-1]) + abs(a[n-1]-a[0]);
  else
    count = abs(k-a[0]) + abs(a[0]-a[n-1]);

  cout << "head moments :" << count;
}