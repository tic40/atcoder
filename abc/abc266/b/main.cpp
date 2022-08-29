#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using ll = long long;

int main() {
  ll n; cin >> n;
  const int p = 998244353;
  int ans = (n % p + p) % p;
  cout << ans << endl;
  return 0;
}