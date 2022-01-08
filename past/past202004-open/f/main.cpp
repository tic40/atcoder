#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)

int n;
vector<vector<int>> g;

void solve() {
  priority_queue<int, vector<int>, less<int>> q;
  int ans = 0;
  REP(i,n) {
    for(auto v: g[i]) {
      q.push(v);
    }
    ans += q.top();
    q.pop();
    cout << ans << endl;
  }
  return;
}

int main() {
  cin >> n;
  g.resize(n);
  REP(i,n) {
    int a,b;
    cin >> a >> b;
    a--;
    g[a].push_back(b);
  }

  solve();
  return 0;
}