#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];
   
  REP(i,n) {
    int ans = -1;
    for(int j = i-1; j >= 0; j--) {
      if (a[i] < a[j]) { ans = j+1; break; }
    }
    cout << ans << endl;
  }
  return 0;
}