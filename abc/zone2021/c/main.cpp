#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

int n;
vector<int> a,b,c,d,e;

bool check(int x) {
  set<int> s;
  REP(i,n) {
    int bit = 0;
    // メンバーの能力値をbitで表す
    // 能力値がx以上であればフラグを立てる
    if (x <= a[i]) bit += 1<<4;
    if (x <= b[i]) bit += 1<<3;
    if (x <= c[i]) bit += 1<<2;
    if (x <= d[i]) bit += 1<<1;
    if (x <= e[i]) bit += 1<<0;
    s.insert(bit);
  }

  for(int i: s) for(int j: s) for(int k: s) {
    // i,j,k の論理和を取りすべてのフラグが立っている状態であればtrue
    // 最小値なのでi,j,kが重複しても構わない
    if ((i|j|k) == (1<<5)-1) return true;
  }
  return false;
}

int binary_search() {
  // ok: 存在する解 ng: 存在しない解
  int ok = 0, ng = 1e9+1;

  while (abs(ok-ng)>1) {
    int mid = (ok+ng)/2;
    check(mid) ? ok = mid : ng = mid;
  }
  return ok;
}

int main() {
  cin >> n;
  a.resize(n); b.resize(n); c.resize(n); d.resize(n); e.resize(n);
  REP(i,n) cin >> a[i] >> b[i] >> c[i] >> d[i] >> e[i];

  cout << binary_search() << endl;
  return 0;
}