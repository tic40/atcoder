#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n; cin >> n;
  vector<ll> s(n+1);
  REP(i,n) {
    int a; cin >> a;
    s[i+1] = s[i] + a;
  }
  ll init = -min(0LL, *min_element(s.begin(),s.end()));
  ll ans = s[n] + init;
  cout << ans << endl;
  return 0;
}