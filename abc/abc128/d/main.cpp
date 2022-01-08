#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

int n,k;
vector<int> v;

void solve() {

  int ans = 0;

  for (int left = 0; left <= min(k,n); left++) {
    for (int right = 0; right+left <= min(k,n); right++) {
      vector<int> tmp;
      REP(i,left) tmp.push_back(v[i]);
      REP(i,right) tmp.push_back(v[n - i - 1]);

      int tot = 0;
      for(int x: tmp) tot += x; // 価値のトータル算出

      sort(tmp.begin(),tmp.end()); // 昇順に並べかえ
      REP(i,tmp.size()) { // 宝石捨てるケース: 価値の低いものから捨てる
        if (k-(left+right) <= i) break; // 操作回数の上限
        if (0 <= tmp[i]) break; // 価値が正の宝石は捨てる必要はない
        tot -= tmp[i];
      }
      ans = max(ans, tot);
    }
  }

  cout << ans << endl;
  return;
}

int main() {
  cin >> n >> k;
  v.resize(n);
  REP(i,n) cin >> v[i];

  solve();
  return 0;
}