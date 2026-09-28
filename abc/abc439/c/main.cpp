#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  ll n; cin >> n;

  vector<int> cnt(n+1);
  for(ll x = 1; x*x < n; x++) {
    if (x*x >= n) break;
    for(ll y = x+1; y*y < n; y++) {
      ll now = x*x + y*y;
      if (now > n) break;
      cnt[now]++;
    }
  }

  vector<int> ans;
  REP(i,n+1) if (cnt[i] == 1) ans.push_back(i);
  cout << ans.size() << endl;
  for(auto v: ans) cout << v << " ";
  return 0;
}
