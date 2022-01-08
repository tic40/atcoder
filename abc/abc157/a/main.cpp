#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
  int n;
  cin >> n;
  if (n % 2 == 1) {
    cout << n / 2 + 1 << endl;
  } else {
    cout << n / 2 << endl;
  }
  return 0;
}
