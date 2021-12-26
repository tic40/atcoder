#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
using ll = long long;
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9+7;

int main() {
  string x; cin >> x;
  int n = x.size();
  ll tot = 0;
  REP(i,n) tot += x[i]-'0';

  ll c = 0;
  vector<int> ans;
  reverse(x.begin(),x.end());

  for(int i = 0; i < n || c > 0; i++) {
    c += tot;
    ans.push_back(c%10);
    c /= 10;
    tot -= x[i]-'0';
  }

  reverse(ans.begin(),ans.end());
  for(int v: ans) cout << v;
  cout << endl;
  return 0;
}