#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)

int n;
vector<int> a(1<<16), ans(1<<16);

void solve() {
  queue<int> q;
  REP(i,n) q.push(i);

  vector<int> tmp;
  int cnt = 1;
  while(q.size() >= 2) {
    int v1 = q.front(); q.pop();
    int v2 = q.front(); q.pop();

    int win = a[v1] < a[v2] ? v2 : v1;
    int lose = a[v1] < a[v2] ? v1 : v2;

    tmp.push_back(win);
    ans[lose] = cnt;

    if (q.size()) continue;

    if (tmp.size() == 1) {
      ans[tmp.front()] = cnt;
    } else {
      cnt++;
      for(int t: tmp) q.push(t);
      tmp.clear();
    }
  }
}

int main() {
  int x; cin >> x;
  n = 1<<x;
  REP(i,n) cin >> a[i];

  solve();
  REP(i,n) cout << ans[i] << endl;
  return 0;
}