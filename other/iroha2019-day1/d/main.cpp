#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
typedef long long ll;

int main() {
  int n, x, y;
  cin >> n >> x >> y;
  vector<int> a(n);
  REP(i, n) cin >> a[i];

  sort(a.begin(), a.end(), greater<int>());
  REP(i, n) {
    if ((i + 1) % 2) x += a[i];
    else y += a[i];
  }
  if (x == y) cout << "Draw";
  else if (x > y) cout << "Takahashi";
  else cout << "Aoki";
  cout << "\n";
}