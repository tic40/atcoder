#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using S = tuple<vector<int>,vector<int>,vector<int>>;

int main() {
  int n,m,l; cin >> n >> m >> l;
  vector<int> a(n),b(m),c(l);
  REP(i,n) cin >> a[i];
  REP(i,m) cin >> b[i];
  REP(i,l) cin >> c[i];
  sort(a.begin(),a.end());
  sort(b.begin(),b.end());
  sort(c.begin(),c.end());

  map<S,bool> mp;
  auto dfs = [&](auto dfs, S s) -> bool {
    if (mp.find(s) != mp.end()) return mp[s];
    auto [a,b,c] = s;
    bool win = false;
    REP(i,(int)a.size()) if (!win) {
      auto na = a, nc = c;
      // a[i] を場に出す処理
      nc.push_back(a[i]);
      na.erase(na.begin()+i);
      sort(nc.begin(),nc.end());
      // 出したカードの数未満の場のカードを加えない
      // 手番が代わるので b,a を入れ替えて再帰
      if (!dfs(dfs, S(b,na,nc))) win = true;

      // 出したカードの数未満の場のカードを加える
      REP(j,(int)nc.size()) if (!win && nc[j] < a[i]) {
        auto na2 = na, nc2 = nc;
        // 場のカードを a に加える処理
        nc2.erase(nc2.begin()+j);
        na2.push_back(nc[j]);
        sort(na2.begin(),na2.end());
        if (!dfs(dfs, S(b,na2,nc2))) win = true;
      }
    }
    return mp[s] = win;
  };

  cout << (dfs(dfs, S(a,b,c)) ? "Takahashi" : "Aoki") << endl;
  return 0;
}