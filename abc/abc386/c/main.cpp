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
  int k; cin >> k;
  string s,t; cin >> s >> t;

  auto f = [&]() -> bool {
    int szs = s.size(), szt = t.size();

    if (abs(szs-szt) > 1) return false;

    if (szs == szt) {
      REP(i,szt) if (s[i] != t[i]) k--;
      return k >= 0;
    }

    if (szs > szt) {
      int si = 0;
      REP(i,szt) {
        while (s[si] != t[i]) {
          si++; k--;
          if (k < 0 || si >= szs) return false;
        }
        si++;
      }
      return true;
    }

    int si = 0;
    REP(i,szt) {
      if (s[si] != t[i]) k--;
      else si++;
    }
    return k >= 0;
  };

  cout << (f() ? "Yes" : "No") << endl;
  return 0;
}