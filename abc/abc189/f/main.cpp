#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

struct L {
  double a,b;
  L(double a=0, double b=0): a(a),b(b) {}
  L operator+(const L& x) const {
    return L(a+x.a, b+x.b);
  }
  L operator-(const L& x) const {
    return L(a-x.a, b-x.b);
  }
  L operator/(int x) const {
    return L(a/x, b/x);
  }
};

int main() {
  int n,m,k; cin >> n >> m >> k;
  // f[i] := i がふりだしに戻るマスかどうか
  vector<bool> f(n+1);
  REP(i,k) {
    int p; cin >> p;
    f[p] = true;
  }

  // dp[i] := i からゴールまでの期待値
  vector<L> dp(n+1);
  L s;
  for(int i = n-1; i >= 0; i--) {
    if (f[i]) dp[i] = L(1,0);
    else dp[i] = s/m+L(0,1);
    s = s+dp[i];
    if (i+m <= n) s = s-dp[i+m];
  }

  double a = dp[0].a;
  double b = dp[0].b;
  // 誤差対処
  if (a+1e-6 > 1) {
    cout << -1 << endl;
  } else {
    double ans = b/(1-a);
    printf("%.10f\n",ans);
  }
  return 0;
}