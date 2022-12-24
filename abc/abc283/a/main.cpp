#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  ll a,b; cin >> a >> b;
  ll ans = powl(a,b);
  cout << ans << endl;
  return 0;
}