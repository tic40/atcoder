#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using P = pair<int,ll>;

int main() {
  int n,q; cin >> n >> q;
  vector<int> a(n);
  REP(i,n) { cin >> a[i]; a[i]--; }

  int logK = 1;
  while(1 << logK <= 1e9) logK++;
  vector nxt(logK,vector<P>(n));

  REP(i,n) nxt[0][i] = { a[i], i+1 };
  REP(k,logK-1) REP(v,n) {
    auto [to,w] = nxt[k][v];
    nxt[k+1][v].first = nxt[k][to].first;
    nxt[k+1][v].second = w + nxt[k][to].second;
  }

  REP(_,q) {
    int t,b; cin >> t >> b; b--;
    ll ans = 0;

    int now = b;
    REP(k,logK) if (t >> k & 1) {
      ans += nxt[k][now].second;
      now = nxt[k][now].first;
    }

    cout << ans << endl;
  }
  return 0;
}
