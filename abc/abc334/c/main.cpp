#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,k; cin >> n >> k;
  vector<int> a(k);
  REP(i,k) { cin >> a[i]; a[i]--; }
  vector<int> cnt(n,2);
  REP(i,k) cnt[a[i]]--;

  vector<int> x;
  REP(i,n) REP(j,cnt[i]) x.push_back(i);

  n = x.size(); // n := 靴下の枚数
  if (n%2 == 0) {
    int ans = 0;
    REP(i,n/2) ans += x[i*2+1] - x[i*2];
    cout << ans << endl;
  } else {
    int now = 0;
    // 0番を消したときの総和を初期値として求める
    REP(i,n/2) now += x[i*2+2] - x[i*2+1];
    int ans = now;
    // i(奇数番目)を消したときにどうなるかを now との差分を取ることで検証する
    for(int i = 2; i < n; i+=2) {
      // 差分として追加する分を足す
      now += x[i-1] - x[i-2];
      // 差分として消す分を引く
      now -= x[i] - x[i-1];
      ans  = min(ans,now);
    }
    cout << ans << endl;
  }
  return 0;
}