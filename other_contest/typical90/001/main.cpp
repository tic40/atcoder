#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,l,k; cin >> n >> l >> k;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  int ok = 1, ng = l;
  while(abs(ok-ng) > 1) {
    int mid = (ok+ng)/2;
    int cnt = 0, last = 0;
    REP(i,n) {
      int left = a[i] - last;
      int right = l - a[i];
      if (left >= mid && right >= mid) { cnt++; last = a[i]; }
    }
    if (cnt >= k) ok = mid;
    else ng = mid;
  }
  cout << ok << endl;
  return 0;
}