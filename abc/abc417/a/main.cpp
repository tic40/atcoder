#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,a,b; cin >> n >> a >> b;
  string s; cin >> s;
  cout << s.substr(a,n-a-b) << endl;
  return 0;
}