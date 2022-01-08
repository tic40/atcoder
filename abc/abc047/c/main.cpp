#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
typedef long long ll;

int main() {
  string s;
  cin >> s;
  int ans;
  for (int i = 1; i < s.size(); i++) {
    if (s[i] != s[i-1]) ans++;
  }
  cout << ans << endl;
}