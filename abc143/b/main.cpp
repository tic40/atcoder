#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define FOR(i, m, n) for(int i = m; i < n; i++)

int main() {
  int n, sum = 0;
  cin >> n;
  int d[n];
  REP(i, n) cin >> d[i];
  REP(i, n-1) {
    FOR(j, i+1, n) sum += d[i]*d[j];
  }
  cout << sum << endl;
}