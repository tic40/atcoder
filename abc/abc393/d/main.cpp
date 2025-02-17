#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n; string s; cin >> n >> s;

  // 中央値を取る
  auto solve1 = [&]() {
    vector<int> p;
    REP(i,n) if (s[i] == '1') p.push_back(i);
    int k = p.size();
    REP(i,k) p[i] -= i;
    int med = p[k/2];

    ll ans = 0;
    REP(i,k) ans += abs(med-p[i]);
    cout << ans << endl;
  };

  // 左右
  auto solve2 = [&]() {
    vector<ll> dl(n+1),dr(n+1);
    REP(ri,2) {
      ll now = 0;
      int one = 0;
      REP(i,n) {
        if (s[i] == '0') now += one;
        else one++;
        dl[i+1] = now;
      }
      swap(dl,dr);
      reverse(dl.begin(),dl.end());
      reverse(dr.begin(),dr.end());
      reverse(s.begin(),s.end());
    }
    ll ans = 1e18;
    REP(i,n+1) ans = min(ans,dl[i]+dr[i]);
    cout << ans << endl;
  };

  // solve1();
  solve2();
  return 0;
}
