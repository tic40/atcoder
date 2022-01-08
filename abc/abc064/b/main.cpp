#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
  int n; cin >> n;
  int a[n];
  REP(i,n) cin >> a[i];
  sort(a, a+n);
  cout << a[n-1] - a[0] << endl;
  return 0;
}
