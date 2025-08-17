#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n,q; cin >> n >> q;
  vector<int> a(n);
  REP(i,n) cin >> a[i];
  sort(a.begin(),a.end());
  vector<ll> s(n+1);
  REP(i,n) s[i+1] = s[i]+a[i];
  int mx = *max_element(a.begin(),a.end());

  auto solve = [&]() -> ll {
    int b; cin >> b;
    if (mx < b) return -1;

    ll ans = 0;
    auto idx = lower_bound(a.begin(),a.end(),b) - a.begin();
    ans += s[idx];
    ans += (ll)(n-idx)*(b-1);
    ans++;
    return ans;
  };

  REP(_,q) cout << solve() << endl;
  return 0;
}