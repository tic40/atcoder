#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  vector<int> a;

  REP(i,n) {
    int x; cin >> x;
    a.push_back(x);
    while(a.size() > 1) {
      if (a[a.size()-1] != a[a.size()-2]) break;
      a.pop_back();
      a.back() += 1;
    }
  }
  cout << a.size() << endl;
  return 0;
}