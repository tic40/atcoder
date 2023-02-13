#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
const int MOD = 1e4;

int main() {
  int n; cin >> n;
  ll now = 0;
  REP(i,n) {
    char c; cin >> c;
    int a; cin >> a;
    if (c == '+') now += a;
    if (c == '-') now -= a;
    if (c == '*') now *= a;

    now = (now % MOD + MOD) % MOD;
    cout << now << endl;
  }
  return 0;
}