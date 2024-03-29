#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

int m;
vector<string> s;

void solve() {
  // sa: 先頭3文字 sb: 後ろから3文字
  vector<string> sa(m), sb(m);
  REP(i,m) {
    sa[i] = s[i].substr(0,3);
    sb[i] = s[i].substr(s[i].size() - 3);
  }
  map<string, int> mp;
  REP(i,m) {
    mp[sa[i]] = 0;
    mp[sb[i]] = 0;
  }

  int n = 0;
  // 0から順番に頂点番号をナンバリングする
  for(auto& p: mp) {
    p.second = n;
    n++;
  }

  vector<vector<int>> to(n);
  vector<int> deg(n); // 入次数
  REP(i,m) {
    int a = mp[sa[i]];
    int b = mp[sb[i]];
    to[b].push_back(a);
    deg[a]++;
  }

  queue<int> q;
  vector<int> ans(n); // -1: 負け, 0: 引き分け, 1: 価値
  REP(i,n) {
    if (deg[i] == 0) {
      ans[i] = -1;
      q.push(i); // 入次数が0の点をpush
    }
  }
  while(q.size()) {
    int v = q.front(); q.pop();
    if (ans[v] == -1) {
      for (int u: to[v]) {
        if (ans[u]) continue;
        ans[u] = 1;
        q.push(u);
      }
    } else {
      for (int u: to[v]) {
        if (ans[u]) continue;
        deg[u]--;
        if (deg[u] == 0) {
          ans[u] = -1;
          q.push(u);
        }
      }
    }
  }

  REP(i,m) {
    int b = mp[sb[i]];
    if (ans[b] == -1) cout << "Takahashi" << endl;
    else if (ans[b] == 0) cout << "Draw" << endl;
    else cout << "Aoki" << endl;
  }

  return;
}

int main() {
  cin >> m;
  s.resize(m);
  REP(i,m) cin >> s[i];

  solve();
  return 0;
}