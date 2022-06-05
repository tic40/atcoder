#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)

int main() {
  int n; cin >> n;
  vector<bool> sq(n+1);
  for(int i = 1; i*i <= n; i++) sq[i*i] = true;
  vector<vector<int>> d(n+1);
  for(int i = 1; i <= n; i++) {
    // jの約数を追加
    for(int j = i; j <= n; j+=i) d[j].push_back(i);
  }

  vector<int> cnt(n+1);
  for(int i = 1; i <= n; i++) {
    int f = 0;
    // iの約数の中で最大の平方数
    for(int v: d[i]) if (sq[v]) f = v;
    cnt[i/f]++;
  }

  int ans = 0;
  for(int i = 1; i <= n; i++) ans += cnt[i]*cnt[i];
  cout << ans << endl;
  return 0;
}
