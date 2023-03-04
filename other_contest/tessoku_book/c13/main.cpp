#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using mint = modint1000000007;
const int MOD = 1e9+7;

int main() {
  int n,p; cin >> n >> p;
  vector<ll> a(n);
  REP(i,n) { cin >> a[i]; a[i] %= MOD; }

  ll ans = 0;
  map<int,int> count;
  REP(i,n) {
    if (a[i] == 0) {
      if (p == 0) ans += i;
    } else {
      mint x = (mint)p / a[i];
      ans += count[x.val()];
    }
    count[a[i]]++;
  }
  cout << ans << endl;
  return 0;
}