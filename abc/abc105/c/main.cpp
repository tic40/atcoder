#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  string ans = "";
  while(n != 0) {
    if (n%2 != 0) {
      n--;
      ans += "1";
    } else {
      ans += "0";
    }
    n /= -2;
  }

  if (ans.size() == 0) ans = "0";
  reverse(ans.begin(),ans.end());
  cout << ans << endl;

  return 0;
}