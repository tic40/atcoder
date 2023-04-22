#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  vector<int> x(n,-1);
  x[0] = 0; x[n-1] = 1;

  int l = 0, r = n;
  while(r-l > 1) {
    int mid = (l+r) / 2;
    cout << "? " << mid+1 << endl;
    fflush(stdout);
    cin >> x[mid];
    if (x[mid] == 0) l = mid;
    else r = mid;
  }

  REP(i,n-1) {
    if (x[i] == -1 || x[i+1] == -1) continue;
    if (x[i] != x[i+1]) {
      cout << "! " << i+1 << endl;
      break;
    }
  }
  return 0;
}