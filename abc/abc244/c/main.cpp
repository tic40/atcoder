#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)

int main() {
  int n; cin >> n;
  vector<bool> used(2005);

  int cur = 1;
  while(1) {
    while(used[cur]) cur++;
    cout << cur << endl;
    used[cur] = true;

    int x; cin >> x;
    if (x == 0) break;
    used[x] = true;
  }
  return 0;
}