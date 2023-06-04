#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,d; cin >> n >> d;
  d *= d;
  vector<int> x(n),y(n);
  REP(i,n) cin >> x[i] >> y[i];

  vector dist(n,vector<int>(n));
  REP(i,n) REP(j,n) dist[i][j] = pow(x[i]-x[j],2) + pow(y[i]-y[j],2);

  vector<bool> ans(n); // 感染していたら true
  ans[0] = true;
  queue<int> q;
  q.push(0);
  while(q.size()) {
    int v = q.front(); q.pop();
    REP(i,n) {
      if (ans[i]) continue;
      if (dist[v][i] > d) continue;
      q.push(i);
      ans[i]=true;
    }
  }

  REP(i,n) cout << (ans[i] ? "Yes" : "No") << endl;
  return 0;
}