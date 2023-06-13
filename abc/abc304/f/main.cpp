#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using mint = modint998244353;

int main() {
  int n; string s; cin >> n >> s;

  mint ans;
  // b[i] := 周期 i の総数
  vector<mint> b(n+1);
  // ds[i] := 重複分の周期が i になる j の集合
  vector ds(n+1,vector<int>());
  for(int m = 1; m < n; m++) {
    if (n%m) continue;
    mint a = 1;
    REP(i,m) {
      int x = 2;
      for(int j = i; j < n; j+=m) if (s[j] == '.') x = 1;
      a *= x;
    }

    for(int d: ds[m]) a -= b[d]; // 重複分を取り除く
    ans += a;
    b[m] = a;

    // 重複分を記録する
    for(int i = m*2; i < n; i+=m) ds[i].push_back(m);
  }

  cout << ans.val() << endl;
  return 0;
}