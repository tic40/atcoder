#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
using ll = long long;
const ll LINF = 1e18;

ll n,k;
vector<ll> a;

void solve() {
  ll ok = 0;
  ll ng = 1e18/k; //  /k しないとオーバーフローする
  while(1 < abs(ng - ok)) {
    ll mid = (ok+ng)/2;
    ll sum = 0;
    REP(i,n) sum += min(a[i],mid);
    if (mid*k <= sum) ok = mid;
    else ng = mid;
  }
  cout << ok << endl;
  return;
}

int main() {
  cin >> n >> k;
  a.resize(n);
  REP(i,n) cin >> a[i];

  solve();
  return 0;
}