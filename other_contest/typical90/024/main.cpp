#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

int main() {
  int n,k; cin >> n >> k;
  vector<int> a(n),b(n);
  REP(i,n) cin >> a[i];
  REP(i,n) cin >> b[i];

  REP(i,n) k -= abs(a[i]-b[i]);
  if (k < 0) {
    cout << "No" << endl;
  } else {
    cout << (k%2 == 0 ? "Yes" : "No") << endl;
  }
  return 0;
}