#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
typedef long long ll;

int main() {
  int n;
  cin >> n;
  int a[n];
  REP(i,n) cin >> a[i];

  REP(i,n) {
    if (a[i] % 2 == 0) {
      if (a[i] % 3 != 0 && a[i] % 5 != 0) {
        cout << "DENIED" << endl;
        return 0;
      }
    }
  }

  cout << "APPROVED" << endl;
}