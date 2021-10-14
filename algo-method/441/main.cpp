#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  for (int i = 1; i < n; i++) {
    int pos = i;
    while (0 < pos && a[pos] < a[pos-1]) {
      swap(a[pos], a[pos-1]);
      pos--;
    }
    REP(i,n) cout << a[i] << " ";
    cout << endl;
  }
  return 0;
}