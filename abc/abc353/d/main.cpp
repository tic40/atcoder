#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using mint = modint998244353;

int get_digit(int x) {
  return to_string(x).size();
}

int main() {
  int n; cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  vector<ll> s(n+1);
  REP(i,n) s[i+1] = s[i]+a[i];
  vector<ll> digits(11), ad(n);
  REP(i,n) ad[i] = get_digit(a[i]);
  REP(i,n) digits[ad[i]]++;

  vector<ll> x(11);
  x[0] = 1;
  REP(i,10) x[i+1] = x[i] * 10;

  mint ans = 0;
  REP(i,n-1) {
    digits[ad[i]]--;
    ans += s[n] - s[i+1];
    REP(j,11) ans += (mint)a[i] * x[j] * digits[j];
  }
  cout << ans.val() << endl;
  return 0;
}