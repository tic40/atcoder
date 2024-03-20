#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using P = pair<int,int>;
const int INF = numeric_limits<int>::max();
const ll LINF = numeric_limits<ll>::max();
const int MOD = 1e9+7;
// using mint = modint998244353; // modint1000000007;

int main() {
  string s; cin >> s;
  auto f = [&](string s) {
    int res = 0;
    for(auto c: s) {
      if (c == 'a') res++;
      else break;
    }
    return res;
  };

  int l = f(s);
  reverse(s.begin(),s.end());
  int r = f(s);

  s = s + string(max(0,r-l),'a');
  auto t = s;
  reverse(t.begin(),t.end());
  cout << (t == s ? "Yes" : "No") << endl;
  return 0;
}