#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;

int main() {
  int n; cin >> n;

  ll ok = n, ng = -1;
  while(abs(ok-ng) > 1) {
    ll mid = (ok+ng)/2;
    ll v = mid*(1+mid)/2;

    if (n <= v) ok = mid;
    else ng = mid;
  }

  int ext = ok*(1+ok)/2 - n;
  for(int i = 1; i <= ok; i++) {
    if (i != ext) cout << i << endl;
  }

  return 0;
}