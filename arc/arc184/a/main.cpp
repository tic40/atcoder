#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int ask = (int xs, int y) {
  cout << "? " << x+1 << " " << y+1 << endl;
  int res; cin >> res;
  return res;
}

int main() {
  int n,m,q; cin >> n >> m >> q;

  vector ans(2,vector<int>()); // ans[i] := i=0 は本物、i=1 は偽物の集合
  int l = 0, r = 1;
  while(l < n) {
    vector g(2,vector<int>());
    g[0].push_back(l);

    bool found = false;
    while(r < n) {
      int res = ask(l,r);
      g[res].push_back(r);

      if (g[res].size() == 11) {
        for(auto v: g[res^1]) ans[1].push_back(v);
        for(auto v: g[res]) ans[0].push_back(v);
        found = true;
        break;
      }
      r++;
    }

    if(!found) {
      if (g[0].size() && ask(ans[0][0],g[0][0]) == 1) for(auto v: g[0]) ans[1].push_back(v);
      if (g[1].size() && ask(ans[0][0],g[1][0]) == 1) for(auto v: g[1]) ans[1].push_back(v);
    }
    l = r+1;
    r+=2;
  }

  cout << "! ";
  for(auto v: ans[1]) cout << v+1 << " ";
  return 0;
}