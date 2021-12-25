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

  ll s = 0;
  REP(i,n) s += x[i]-'0';

  reverse(x.begin(),x.end());
  vector<int> vs;

  ll c = 0;
  for(int i = 0; (i < n || c != 0); i++) {
    c += s;
    vs.push_back(c % 10);
    c /= 10;
    s -= x[i]-'0';
  }

  reverse(vs.begin(),vs.end());
  for(int v: vs) cout << v;
  cout << endl;
  return 0;
}