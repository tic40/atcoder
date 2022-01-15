#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
using ll = long long;

int a,n;
vector<int> d(1000005, -1);

void bfs() {
  queue<int> q;
  q.push(1);
  d[1]=0;
  int mx = min(1000000, n*10);

  auto push = [&](ll nv, int v){
    if (nv <= mx && d[nv] == -1) {
      d[nv] = d[v]+1;
      q.push(nv);
    }
  };

  while (q.size()) {
    int cur = q.front(); q.pop();

    if (cur == n) return;

    push((ll)cur*a, cur);
    if (10 <= cur && cur % 10 != 0) {
      string t = to_string(cur);
      rotate(t.rbegin(), t.rbegin()+1, t.rend());
      push(stoi(t), cur);
    }
  }

  return;
}

int main() {
  cin >> a >> n;
  bfs();
  cout << d[n] << endl;
  return 0;
}