#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

int main() {
  int n,k;
  cin >> n >> k;

  ll ans;
  if (k%2) {
    ll a = n/k;
    ans = a*a*a;
  } else {
    ll a = n/k;
    ll b = (n+k/2)/k; // kで割ってk/2余る数
    ans = a*a*a + b*b*b;
  }

  cout << ans << endl;
  return 0;
}