#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; string s;
  cin >> n >> s;
  for(int i = 1; i < n; i++) {
    int ans = 0;
    for(int j = i; j < n; j++) {
      if (s[j-i] == s[j]) break;
      ans++;
    }
    cout << ans << endl;
  }

  return 0;
}