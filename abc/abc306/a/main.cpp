#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; string s;
  cin >> n >> s;
  REP(i,n) cout << s[i] << s[i];
  cout << endl;
  return 0;
}