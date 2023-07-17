#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n; cin >> n;
  string s; cin >> s;

  ll ans = 0;
  // d[i] := 今までの計算結果で i で終わる数
  vector<int> d(2);
  REP(i,n) {
    int x = s[i]-'0';
    if (x == 0) {
      // x = 0 のとき必ず 1 になる
      d[1] += d[0];
      d[0] = 0;
    } else {
      // x = 1 のとき 1 の場合は 0, 1 の場合は 0 になる
      swap(d[0],d[1]);
    }
    d[x]++;
    ans += d[1];
  }
  cout << ans << endl;
  return 0;
}