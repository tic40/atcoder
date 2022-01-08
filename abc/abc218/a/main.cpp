#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

int main() {
  int n;
  string s;
  cin >> n >> s;
  cout << (s[n-1] == 'o' ? "Yes" : "No") << endl;
  return 0;
}