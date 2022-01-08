#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
typedef long long ll;

int main() {
  int n, sum=0, ans=0;
  string x;
  cin >> n;
  vector<string> s(n);
  vector<int> t(n);
  REP(i,n) { cin >> s[i] >> t[i]; sum+=t[i]; }
  cin >> x;

  REP(i, n) {
    ans+=t[i];
    if (s[i] == x) break;
  }
  cout << sum-ans << endl;
}
