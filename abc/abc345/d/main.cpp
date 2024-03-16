#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using P = pair<int,int>;

int main() {
  int n,h,w; cin >> n >> h >> w;
  vector<int> a(n),b(n);
  REP(i,n) cin >> a[i] >> b[i];

  vector<vector<int>> g;
  REP(bit, (1<<n)) {
    vector<int> v;
    int tot = 0;
    REP(i,n) if ((bit >> i) & 1) { v.push_back(i); tot += a[i]*b[i]; }
    if (tot == h*w) g.push_back(v);
  }

  for(auto v: g) {
    int vs = v.size();
    vector<int> d(vs);
    iota(d.begin(),d.end(),0);

    do {
      auto dfs = [&](auto self, int now, int nx, int ny, vector<vector<int>> used) {
        auto find = [&]() {
          REP(i,h) REP(j,w) if (used[i][j] == false) return P{i,j};
          return P(-1,-1);
        };
        auto [ni,nj] = find();

        for(int i = ni; i < ni+nx; i++) for(int j = nj; j < nj+ny; j++) {
          if (i >= h || j >= w) return false;
          if (used[i][j] == true) return false;
          used[i][j] = true;
        }

        if (now+1 == vs) return true;

        return self(self,now+1,a[v[d[now+1]]],b[v[d[now+1]]],used)
          || self(self,now+1,b[v[d[now+1]]],a[v[d[now+1]]],used);
      };
      bool ok = dfs(dfs,0,a[v[d[0]]],b[v[d[0]]],vector(h,vector<int>(w)))
        || dfs(dfs,0,b[v[d[0]]],a[v[d[0]]],vector(h,vector<int>(w)));
      if (ok) { cout << "Yes" << endl; return 0; }
    } while (next_permutation(d.begin(), d.end()));
  }
  cout << "No" << endl;
  return 0;
}