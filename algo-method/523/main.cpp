#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9+7;

ll divisor_num(ll n) {
  int res = 0;
  for (int i = 1; i*i <= n; i++) {
    if (n % i == 0) {
      res++;
      res += i != n/i;
    }
  }
  return res;
}

int main() {
  int i = 0;
  int n = 6;
  while(i < 5) {
    if (divisor_num(n) == 6) {
      cout << n << endl;
      i++;
    }
    n++;
  }
  return 0;
}