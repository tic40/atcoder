#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
typedef long long ll;

int n, k, t[5][5];

bool solve(int i=0, int j=0, int cur=0) {
  if (i >= n) return cur != 0;
  REP(_j, k) {
    int next_cur = i == 0 ? t[i][_j] : cur ^ t[i][_j];
    if (!solve(i+1, _j, next_cur)) return false;
  }
  return true;
}

int main() {
  cin >> n >> k;
  REP(i, n) { REP(j, k) { cin >> t[i][j]; } }
  if (solve()) cout << "Nothing" << endl;
  else cout << "Found" << endl;
}
