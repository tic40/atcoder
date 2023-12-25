#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,k; cin >> n >> k;
  vector<int> cnt(n,2);
  REP(i,k) {
    int a; cin >> a; a--;
    cnt[a]--;
  }

  vector<int> x;
  REP(i,n) REP(j,cnt[i]) x.push_back(i);

  n = x.size(); // n := 靴下の枚数
  if (n%2 == 0) {
    int ans = 0;
    for(int i = 0; i < n; i+=2) ans += x[i+1] - x[i];
    cout << ans << endl;
  } else {
    int now = 0;
    // 0番を消したときの総和
    for(int i = 1; i < n; i+=2) now += x[i+1] - x[i];
    int ans = now;
    // i(奇数番目)を消したときにどうなるかを now との差分を取ることで検証する
    for(int i = 2; i < n; i+=2) {
      now += x[i-1] - x[i-2]; // 追加分を差分として足す
      now -= x[i] - x[i-1]; // 削除分を差分として引く
      ans = min(ans,now);
    }
    cout << ans << endl;
  }
  return 0;
}