#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int h,w,n; cin >> h >> w >> n;
  vector<int> cnt(26); // cnt[i] := 2^i * 2^1 の板チョコの数
  REP(i,n) { int a; cin >> a; cnt[a]++; }
  REP(i,26) {
    int x = 2;
    for(int j = i-1; j >= 0; j--) {
      cnt[j] += cnt[i] * x * x;
      x *= 2;
    }
  }

  auto f = [&]() {
    ll x = 1;
    REP(i,26) {
      ll tot = (h/x) * (w/x) * (x*x); // 2^i * 2^1 の板チョコを取る場合の最大の面積
      ll s = x*x*cnt[i]; // 2^i * 2^1 の板チョコの合計面積
      if (tot < s) return false;
      x *= 2;
    }
    return true;
  };

  cout << (f() ? "Yes" : "No") << endl;
  return 0;
}