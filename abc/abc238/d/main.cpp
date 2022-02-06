#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
using ll = long long;

int t;
vector<ll> a,s;

// x + y = (x XOR y) + 2*(x AND y) であることを利用する解法
void solve1() {
  REP(i,t) {
    bool ok = false;
    // x + y = (x XOR y) + 2*(x AND y)
    // x + y = s, x AND y = a より、
    // s = (x XOR y) + 2*a

    ll diff = s[i] - 2*a[i];
    if (0 <= diff) { // マイナスになるケースを考慮
      if ( (diff & a[i]) == 0) ok = true;
    }
    cout << (ok ? "Yes" : "No") << endl;
  }

  return;
}

void solve2() {
  return;
}

int main() {
  cin >> t;
  a.resize(t);
  s.resize(t);
  REP(i,t) cin >> a[i] >> s[i];

  solve1();
  return 0;
}