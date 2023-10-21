#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
const ll LINF = numeric_limits<ll>::max();

int main() {
  int n; cin >> n;
  map<ll,vector<ll>> mp;
  REP(i,n) {
    ll t,d; cin >> t >> d;
    mp[t].push_back(t+d);
  }

  ll t = 0, ans = 0;
  priority_queue<ll, vector<ll>, greater<ll>> q;
  auto f = [&](ll k) {
    while(t < k && q.size()) {
      ll now = q.top(); q.pop();
      if (t <= now) { ans++; t++; }
    }
  };

  for(auto [k,v]: mp) {
    f(k); t = k;
    for(auto nv: v) q.push(nv);
  }
  f(LINF);
  cout << ans << endl;
  return 0;
}