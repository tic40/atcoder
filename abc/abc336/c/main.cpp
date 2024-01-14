#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

const vector<int> x = {0,2,4,6,8};
int main() {
  ll n; cin >> n;
  n--;

  string ans = "";
  while(n > 0) {
    ans += char(x[n % 5] + '0');
    n /= 5;
  }
  reverse(ans.begin(),ans.end());
  cout << (ans.size() == 0 ? "0" : ans) << endl;
  return 0;
}