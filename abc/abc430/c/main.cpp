#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n,a,b; cin >> n >> a >> b;
  string s; cin >> s;
  // 累積和
  vector<int> sa(n+1), sb(n+1);
  REP(i,n) sa[i+1] = sa[i] + (s[i] == 'a' ? 1 : 0);
  REP(i,n) sb[i+1] = sb[i] + (s[i] == 'b' ? 1 : 0);

  ll ans = 0;
  REP(l,n) {
    int ra = lower_bound(sa.begin()+l,sa.end(),a+sa[l]) - sa.begin();
    int rb = lower_bound(sb.begin()+ra,sb.end(),b+sb[l]) - sb.begin();
    ans += max(0,rb-ra);
  }
  cout << ans << endl;
  return 0;
}