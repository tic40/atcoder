#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
using ll = long long;
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9+7;

int n;
vector<int> a;

void solve() {
  stack<pair<int,int>> x;

  int tot = 0;
  REP(i,n) {
    tot++;

    if (x.size() == 0) {
      x.push({ a[i], 1 });
      cout << tot << endl;
      continue;
    }

    auto [prev, prev_num] = x.top();
    if (a[i] == prev) {
      int nv = prev_num+1;
      x.pop();
      x.push({ a[i], nv });
      if (a[i] == nv) {
        x.pop();
        tot -= nv;
      }
    } else {
      x.push({ a[i], 1 });
    }

    cout << tot << endl;
  }
  return;
}

int main() {
  cin >> n;
  a.resize(n);
  REP(i,n) cin >> a[i];

  solve();
  return 0;
}