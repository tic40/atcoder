#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  string s; cin >> s;
  int i = s[0] - '0';
  int j = s[2] - '0';
  j++;
  if (j > 8) cout << i+1 << "-" << 1 << endl;
  else cout << i << "-" << j << endl;
  return 0;
}