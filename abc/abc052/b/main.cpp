#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
typedef long long ll;

int main() {
  int n,x=0,ans=0;
  string s;
  cin >> n >> s;
  for (int i = 0; i < n; i++) {
    s[i] == 'I' ? x++ : x--;
    ans = max(ans, x);
  }
  cout << ans << endl;
}