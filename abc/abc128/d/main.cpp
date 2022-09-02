#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

int main() {
  int n,k; cin >> n >> k;
  vector<int> v(n);
  REP(i,n) cin >> v[i];

  int ans = 0;
  // 操作Aをa回、操作Bをb回として全探索する
  REP(a,k) REP(b,k-a) {
    if (a+b == 0) continue;
    if (a+b > n) continue;

    vector<int> t;
    REP(i,a) t.push_back(v[i]);
    REP(i,b) t.push_back(v[n-i-1]);

    sort(t.begin(),t.end());
    int tot = accumulate(t.begin(),t.end(),0);

    // 負の価値の宝石は捨てられるだけ捨てる
    REP(i,k-(a+b)) if (t[i] < 0) tot -= t[i];
    ans = max(ans,tot);
  }

  cout << ans << endl;
  return 0;
}