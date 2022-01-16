#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
using ll = long long;

int main() {
  int a,n;
  cin >> a >> n;
  vector<int> d(1000005, -1);

  queue<int> q;
  q.push(1);
  d[1]=0;

  auto push = [&](int nv, int cnt) {
    if (nv <= min(1000000, n*10) && d[nv] == -1) {
      d[nv] = cnt+1;
      q.push(nv);
    }
  };

  while(q.size()) {
    int v = q.front(); q.pop();
    int cnt = d[v];
    if (v == n) break;

    if (v <= 1000000/a) push(v*a,cnt);

    if (10 <= v && v % 10 != 0) {
      string s = to_string(v);
      rotate(s.rbegin(), s.rbegin()+1, s.rend());
      push(stoi(s),cnt);
    }
  }

  cout << d[n] << endl;
  return 0;
}