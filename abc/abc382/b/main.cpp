#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,d; string s; cin >> n >> d >> s;
  for(int i = n-1; i >= 0; i--) if (s[i] == '@' && d) s[i] = '.', d--;
  cout << s << endl;
  return 0;
}