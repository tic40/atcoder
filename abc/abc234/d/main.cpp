#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)

int n,k;
vector<int> p;

void solve() {
  priority_queue<int, vector<int>, greater<int>> q;
  REP(i,n) {
    q.push(p[i]);
    if (k-1 <= i) {
      if (k <= i) q.pop();
      cout << q.top() << endl;
    }
  }

  return;
}

int main() {
  cin >> n >> k;
  p.resize(n);
  REP(i,n) cin >> p[i];

  solve();
  return 0;
}