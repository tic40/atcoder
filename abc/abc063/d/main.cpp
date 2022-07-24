#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using ll = long long;

int main() {
  int n,a,b; cin >> n >> a >> b;
  vector<int> h(n);
  REP(i,n) cin >> h[i];

  int ok = *max_element(h.begin(),h.end()) / b + 1;
  int ng = 0;
  while(abs(ok-ng)>1) {
    int mid = (ok+ng)/2;

    ll base = b * mid;
    ll acnt = 0;
    REP(i,n) {
      int d = h[i] - base;
      if (d > 0) acnt += (d + (a-b) - 1) / (a-b);
    }
    if (acnt <= mid) ok = mid;
    else ng = mid;
  }

  cout << ok << endl;
  return 0;
}