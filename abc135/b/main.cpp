#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
typedef long long ll;

int main() {
  int n;
  cin >> n;
  vector<int> p(n), sorted(n);
  REP(i, n) cin >> p[i];
  sorted = p;
  sort(sorted.begin(), sorted.end());
  int count = 0;
  REP(i, n) {
    if (p[i] != sorted[i]) count++;
    if (count > 2) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
}