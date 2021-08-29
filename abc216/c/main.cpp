#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

ll n;
int main() {
  cin >> n;

  string ans = "";
  while(1) {
    if (n == 0) break;
    if (n % 2) {
      n--;
      ans += "A";
    } else {
      n /= 2;
      ans += "B";
    }
  }
  reverse(ans.begin(), ans.end());
  cout << ans << endl;
  return 0;
}