#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using P = pair<int,int>;

int main() {
  const int n = 9;
  vector<string> s(n);
  REP(i,n) cin >> s[i];

  unordered_set<int> st;
  REP(i,n) REP(j,n) if (s[i][j] == '#') st.emplace(i,j);

  int ans = 0;
  for(auto a: st) for(auto b: st) if (a!=b) {
    int di = b.first - a.first;
    int dj = b.second - a.second;
    P c(b.first + dj, b.second + di);
    P d(c.first + di, c.second + dj);
    if (s[c.first][c.second] == '#' && s[d.first][d.second] == '#') ans++;
  }
  cout << ans << endl;
  return 0;
}