#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  string s; cin >> s;
  int n = s.size();
  for(int i = 1; i <= n/2; i++) swap(s[2*i-2], s[2*i-1]);
  cout << s << endl;
  return 0;
}