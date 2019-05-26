#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
typedef long long ll;

int main() {
  int n, m, a, b, c;
  ll ans;
  vector<pair<int,int>> v;
  cin >> n >> m;
  REP(i, n) {
    cin >> a;
    v.push_back(make_pair(a, 1));
  }
  REP(i, m) {
    cin >> b >> c;
    v.push_back(make_pair(c, b));
  }
  sort(v.rbegin(), v.rend());
  int i = 0;
  while(n) {
    ll res = min(n, v[i].second);
    ans += res * v[i].first;
    n -= res;
    i++;
  }
  cout << ans << "\n";
}