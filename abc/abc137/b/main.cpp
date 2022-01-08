#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
typedef long long ll;


int main() {
  int k,x;
  int low = -1000000, high = 1000000;
  cin >> k >> x;
  k--;
  int l = max(x - k, low);
  int h = min(x + k, high);
  for (int i = l; i <= h; i++) {
    if (i > l) cout << " ";
    cout << i;
  }
  cout << endl;
}