#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

int q;
vector<int> l,r;

vector<int> eratosthenes(int n) {
  vector<int> primes(n+1);
  for(int i=2; i<=n; i++) {
    if(0 <= primes[i]) {
      for(int j=2*i; j<=n; j+=i) primes[j] = -1;
      primes[i] = 1;
    }
  }
  return primes;
}

void solve() {
  vector<int> e = eratosthenes(100000);
  vector<int> dp(100005, 0);
  for (int i = 3; i <= 100000; i+=2) {
    dp[i+2] = dp[i];
    if (e[i] == 1 && e[(i+1)/2] == 1) dp[i+2]++;
  }

  REP(i,q) cout << dp[r[i]+2] - dp[l[i]] << endl;
  return;
}

int main() {
  cin >> q;
  l.resize(q); r.resize(q);
  REP(i,q) cin >> l[i] >> r[i];

  solve();
  return 0;
}