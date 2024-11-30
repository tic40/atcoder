#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,m,l; cin >> n >> m >> l;

  vector<int> a(n),b(m),c(l);
  REP(i,n) cin >> a[i];
  REP(i,m) cin >> b[i];
  REP(i,l) cin >> c[i];
  sort(a.begin(),a.end());
  sort(b.begin(),b.end());
  sort(c.begin(),c.end());

  using S = tuple<vector<int>,vector<int>,vector<int>>;
  map<S,bool> mem;

  auto f = [&](auto f, S s) -> bool {
    if (mem.find(s) != mem.end()) return mem[s];
    auto [a,b,c] = s;
    bool res = false;
    REP(i,(int)a.size()) {
      auto na = a, nc = c;
      nc.push_back(a[i]);
      na.erase(na.begin()+i);
      sort(nc.begin(),nc.end());
      if (!f(f, S(b,na,nc))) res = true;
      REP(j,(int)nc.size()) {
        if (nc[j] < a[i]) {
          auto na2 = na, nc2 = nc;
          nc2.erase(nc2.begin()+j);
          na2.push_back(nc[j]);
          sort(na2.begin(),na2.end());
          if (!f(f, S(b,na2,nc2))) res = true;
        }
      }
    }
    return mem[s] = res;
  };

  cout << (f(f,S(a,b,c)) ? "Takahashi" : "Aoki") << endl;
  return 0;
}