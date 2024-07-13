#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n; cin >> n;
  vector<int> l(n),r(n);
  REP(i,n) cin >> l[i] >> r[i];

  // 全て l を選んだ状態からスタート
  ll now = accumulate(l.begin(),l.end(),0LL);
  vector<int> ans(n);
  REP(i,n) {
    ll add = min((ll)r[i]-l[i], abs(now));
    ans[i] = l[i] + add;
    now += add;
  }

  if (now != 0) cout << "No" << endl;
  else {
    cout << "Yes" << endl;
    REP(i,n) cout << ans[i] << " ";
  }

  return 0;
}