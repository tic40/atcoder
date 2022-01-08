#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
typedef long long ll;

int main() {
  int n, k;
  cin >> n >> k;
  ll ans = k;
  for (int i = 1; i<n; i++) ans *= k-1;
  cout << ans << endl;
}