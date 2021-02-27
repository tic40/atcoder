#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

int n;
vector<ll> a;

int binary_search() {
  int ng = -1, ok = n-1;

  while (abs(ok-ng)>1) {
    int mid = (ok+ng)/2;
    ll cur = a[mid];
    REP(i,n) {
      if (i == mid) continue;
      if (cur*2 < a[i]) {
        cur = -1; break;
      }
      cur += a[i];
    }
    if (cur == -1) ng = mid;
    else ok = mid;
  }
  return ok;
}

void solve() {
  sort(a.begin(),a.end());
  int idx = binary_search();
  cout << n - idx << endl;
  return;
}

int main() {
  cin >> n;
  a.resize(n);
  REP(i,n) cin >> a[i];

  solve();
  return 0;
}