#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
typedef long long ll;

int main() {
  string s; cin >> s;
  cout << 1+s.rfind("Z")-s.find("A") << endl;
}
