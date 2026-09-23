#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; string s;
  cin >> n >> s;
  REP(i,n-(int)s.size()) cout << "o";
  cout << s << endl;
  return 0;
}
