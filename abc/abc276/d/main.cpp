#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
const int INF = numeric_limits<int>::max();

map<int,int> prime_factorize(int n) {
  map<int,int> res;
  for(int a = 2; a*a <= n; a++) {
    if (n%a != 0) continue;
    int ex = 0;
    while(n%a == 0) { ex++; n /= a; }
    res[a] = ex;
  }
  if (n != 1) res[n] = 1;
  return res;
}

int main() {
  int n; cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  vector<map<int,int>> memo(n);
  vector<int> m(4,INF);
  REP(i,n) {
    auto pf = prime_factorize(a[i]);
    memo[i] = pf;
    m[2] = min(m[2],pf[2]);
    m[3] = min(m[3],pf[3]);
  }

  int ans = 0;
  REP(i,n) {
    auto pf = memo[i];
    REP(j,2) {
      int now = 2+j;
      int d = pf[now] - m[now];
      a[i] /= pow(now,d);
      ans += d;
    }
  }

  bool ok = true;
  REP(i,n-1) if (a[i] != a[i+1]) ok = false;
  cout << (ok ? ans : -1) << endl;
  return 0;
}