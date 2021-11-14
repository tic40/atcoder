#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
using ll = long long;
const ll LINF = 1e18;

int main() {
  ll n,k;
  cin >> n >> k;
  vector<ll> a(n);
  REP(i,n) cin >> a[i];

  ll ok = 0, ng = LINF / k;
  while(1 < (ng-ok)) {
    ll mid = (ng+ok) / 2;
    ll sum = 0;
    REP(i,n) sum += min(a[i], mid);
    if (mid*k <= sum) ok = mid;
    else ng = mid;
  }

  cout << ok << endl;
  return 0;
}