#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
using ll = long long;
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9+7;

vector<bool> eratosthenes(int n) {
  vector<bool> primes(n+1, true);

  primes[0] = false;
  primes[1] = false;
  for (int i = 2; i <= n; i++) {
    if (!primes[i]) continue;
    for (int j = 2*i; j <= n; j+=i) primes[j] = false;
  }
  return primes;
}

int a,b,c,d;

int main() {
  cin >> a >> b >> c >> d;

  // 素数列挙
  auto pn = eratosthenes(300);

  // takahashiくんが勝てるかどうか = 最終的に素数にできるかどうか
  for(int i = a; i <= b; i++) {
    bool impossible_pn = true;
    for(int j = c; j <= d; j++) {
      if (pn[i + j]) {
        impossible_pn = false;
        break;
      }
    }

    if (impossible_pn) {
      cout << "Takahashi" << endl;
      return 0;
    }
  }

  cout << "Aoki" << endl;
  return 0;
}