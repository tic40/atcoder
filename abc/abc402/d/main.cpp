#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n,m; cin >> n >> m;
  vector<ll> cnt(n);
  REP(i,m) {
    int a,b; cin >> a >> b;
    int x = (a+b)%n;
    cnt[x]++;
  }
  ll ans = (ll)m * (m-1) / 2;
  REP(i,n) ans -= cnt[i] * (cnt[i]-1) / 2;
  cout << ans << endl;
  return 0;
}