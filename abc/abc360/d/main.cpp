#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n,t; cin >> n >> t;
  string s; cin >> s;
  vector<int> pos,neg;
  REP(i,n) {
    int x; cin >> x;
    if (s[i] == '0') neg.push_back(x);
    else pos.push_back(x);
  }
  sort(neg.begin(),neg.end());

  ll ans = 0;
  for(auto v: pos) {
    auto lt = lower_bound(neg.begin(),neg.end(),v);
    auto rt = upper_bound(neg.begin(),neg.end(),(ll)v+t*2);
    ans += rt-lt;
  }
  cout << ans << endl;
  return 0;
}