#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
const int MOD = 1e9;

int main() {
  int n,k; cin >> n >> k;
  ll s = k;
  vector<ll> a(n+1,1);
  for(int i = k; i <= n; i++) {
    a[i] = s;
    s -= a[i-k];
    s += a[i];
    s = (s % MOD + MOD) % MOD;
  }
  cout << a[n] << endl;
  return 0;
}
