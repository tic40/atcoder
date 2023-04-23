#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using mint = modint998244353;

mint f(ll base, ll n) {
  if (n == 0) return 1;
  mint x = f(base, n/2);
  x *= x;
  if (n % 2 == 1) x *= base;
  return x;
}

int main() {
  int q; cin >> q;
  deque<int> dq = { 1 };
  mint now = 1;
  REP(i,q) {
    int t; cin >> t;
    if (t == 1) {
      int x; cin >> x;
      dq.push_back(x);
      now *= 10;
      now += x;
    } else if (t == 2) {
      int v = dq.front();
      dq.pop_front();
      now -= f(10,(int)dq.size()) * v;
    } else {
      cout << now.val() << endl;
    }
  }

  return 0;
}