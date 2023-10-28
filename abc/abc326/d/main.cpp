#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  string r,c; cin >> r >> c;
  string abc(n,'.');
  REP(i,3) abc[i] = char('A'+i);

  vector rows(3,vector<string>());
  vector<int> b(n);
  REP(i,n) b[i] = i;
  do {
    int first = -1;
    string now = "";
    REP(i,n) now += abc[b[i]];
    REP(i,n) if (now[i] != '.') { first = now[i]-'A'; break; }
    rows[first].push_back(now);
  } while (next_permutation(b.begin(), b.end()));

  vector<string> m;
  vector<int> col(n);
  vector col_cnt(n,vector<int>(3));
  auto dfs = [&](auto self) -> void {
    int i = m.size();
    if (i == n) {
      if (accumulate(col.begin(),col.end(),0) == n) {
        cout << "Yes" << endl;
        for(auto v: m) cout << v << endl;
        exit(0);
      }
      return;
    }

    for(auto v: rows[r[i]-'A']) {
      bool ok = true;
      vector<int> t;
      REP(j,n) {
        if (v[j] == '.') continue;
        if (col_cnt[j][v[j]-'A'] >= 1) { ok = false; break; }
        if (col[j]) continue;
        if (v[j] == c[j]) t.push_back(j);
        else { ok = false; break; }
      }
      if (!ok) continue;
      m.push_back(v);
      for(auto v2: t) col[v2] = 1;
      REP(j,n) if (v[j] != '.') col_cnt[j][v[j]-'A']++;
      self(self);
      m.pop_back();
      for(auto v2: t) col[v2] = 0;
      REP(j,n) if (v[j] != '.') col_cnt[j][v[j]-'A']--;
    }
  };

  dfs(dfs);
  cout << "No" << endl;
  return 0;
}