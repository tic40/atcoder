#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using ull = unsigned long long;

mt19937_64 rng(58); // 64bit 乱数生成
const ull mod = (1LL<<61) - 1; // 素数

int main() {
  int n,q; cin >> n >> q;
  vector<int> a(n), b(n);
  REP(i,n) cin >> a[i];
  REP(i,n) cin >> b[i];

  const int MX = 2e5+5;
  vector<ull> h(MX);
  // 各要素に足してランダムな値を割り当てる
  REP(i,MX) h[i] = rng() % mod;

  // a,b の累積和を取る
  vector<ull> sa(n+1), sb(n+1);
  REP(i,n) sa[i+1] = (sa[i]+h[a[i]]) % mod;
  REP(i,n) sb[i+1] = (sb[i]+h[b[i]]) % mod;

  REP (_,q) {
    int la, ra, lb, rb;
    cin >> la >> ra >> lb >> rb;
    la--; lb--;
    bool ok = (sa[ra] - sa[la] + mod) % mod == (sb[rb] - sb[lb] + mod) % mod;
    cout << (ok ? "Yes" : "No") << endl;
  }

  return 0;
}
