#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
typedef long long ll;

int r, D;
ll x, tmpX;

int main() {
  cin >> r >> D >> x;
  tmpX = x;
  REP (i, 10) {
    tmpX = r * tmpX - D;
    cout << tmpX << "\n";
  }
}