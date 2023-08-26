#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];
  sort(a.begin(),a.end());
  REP(i,n-1) {
    if (a[i+1] - a[i] == 1) continue;
    cout << a[i]+1 << endl;
    break;
  }

  return 0;
}