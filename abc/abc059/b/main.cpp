#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
  string a,b;
  cin >> a >> b;
  if (a.size() > b.size()) {
    cout << "GREATER";
  } else if (a.size() < b.size()) {
    cout << "LESS";
  } else {
    if (a > b) cout << "GREATER";
    else if (a==b) cout << "EQUAL";
    else cout << "LESS";
  }
  cout << endl;
  return 0;
}