#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using P = pair<int,int>;

int main() {
  int n,w; cin >> n >> w;
  vector<P> p;
  REP(i,n) {
    int a,b; cin >> a >> b;
    p.emplace_back(a,b);
  }
  sort(p.rbegin(),p.rend());
  ll ans = 0;
  int nw = 0;
  REP(i,n) {
    auto [a,b] = p[i];
    ans += (ll)a * min(w - nw, b);
    nw += b;
    if (nw >= w) break;
  }
  cout << ans << endl;
  return 0;
}