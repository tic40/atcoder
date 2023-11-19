#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,m; cin >> n >> m;
  string s,t; cin >> s >> t;
  string tg = string(m,'#');

  queue<int> q;
  auto f = [&](int i) -> void {
    if (i < 0 || i+m-1 >= n) return;
    if (s.substr(i,m) == tg) return;

    bool ok = true;
    REP(j,m) ok = ok && (s[i+j] == t[j] || s[i+j] == '#');
    if (ok) {
      REP(j,m) s[i+j] = '#';
      q.push(i);
    }
  };

  REP(i,n-m+1) f(i);
  while(q.size()) {
    auto v = q.front(); q.pop();
    for(int i = v-m+1; i < v; i++) f(i);
    for(int i = v+1; i < v+m; i++) f(i);
  }

  cout << (s == string(n,'#') ? "Yes" : "No") << endl;
  return 0;
}