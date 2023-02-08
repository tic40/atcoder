#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,x; cin >> n >> x;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  int ok = 0, ng = n;
  while(ng-ok > 1) {
    int mid = (ok+ng)/2;
    if (a[mid] <= x) ok = mid;
    else ng = mid;
  }
  cout << ok+1 << endl;
  return 0;
}