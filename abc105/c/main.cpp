#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

int main() {
  int n; cin >> n;
  vector<int> ans;

  while (n != 0) {
    if (n%2 != 0) {
      ans.push_back(1);
      n--;
    } else {
      ans.push_back(0);
    }
    n /= -2;
  }

  reverse(ans.begin(), ans.end());
  if (ans.size()) for(int v: ans) cout << v;
  else cout << 0;
  cout << endl;

  return 0;
}