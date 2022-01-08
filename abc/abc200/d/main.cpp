#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

int n;
vector<int> a;

void out(vector<int> b, vector<int> c) {
  cout << "Yes" << endl;
  cout << b.size() << " ";
  for(int v: b) cout << v << " ";
  cout << endl;
  cout << c.size() << " ";
  for(int v: c) cout << v << " ";
  cout << endl;

  return;
}

void solve() {
  REP(i,n) a[i] %= 200;
  // 鳩の巣原理で最大8要素まで調べればよい
  // 2^8 = 256 なので必ず同じになる配列が存在する
  int an = min(8,n);

  vector<vector<int>> memo(200);
  // bit 全探索
  for(int bit = 1; bit < (1<<an); bit++) {
    int tot = 0;
    vector<int> s;
    REP(i,an) {
      if ((bit >> i) & 1) {
        tot += a[i];
        s.push_back(i+1);
      }
    }
    tot %= 200;

    if (memo[tot].size() == 0) {
      memo[tot] = s;
      continue;
    }

    out(s, memo[tot]);
    return;
  }
  cout << "No" << endl;
  return;
}

int main() {
  cin >> n;
  a.resize(n);
  REP(i,n) cin >> a[i];

  solve();
  return 0;
}