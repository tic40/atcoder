#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
  int n,r;
  cin >> n >> r;
  if (n >= 10) {
    cout << r << endl;
  } else {
    cout << r + (100 * (10 - n)) << endl;
  }
  return 0;
}