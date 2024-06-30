#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n,t; cin >> n >> t;
  string s; cin >> s;
  vector<ll> x(n),xm;
  REP(i,n) {
    cin >> x[i];
    if (s[i] == '0') xm.push_back(x[i]);
  }
  sort(xm.begin(),xm.end());

  ll ans = 0;
  REP(i,n) if (s[i] == '1') {
    int id1 = upper_bound(xm.begin(),xm.end(),x[i]) - xm.begin() - 1;
    int id2 = upper_bound(xm.begin(),xm.end(),x[i] + t * 2) - xm.begin() - 1;
    ans += id2 - id1;
  }
  cout << ans << endl;
  return 0;
}