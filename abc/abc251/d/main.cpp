#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)

int main() {
  int w; cin >> w;
  vector<int> ans;
  for(int i = 1; i <= 99; i++) ans.push_back(i);
  for(int i = 100; i <= 9900; i+=100) ans.push_back(i);
  for(int i = 10000; i <= 990000; i+=10000) ans.push_back(i);
  ans.push_back(10000);

  cout << ans.size() << endl;
  for(int v: ans) cout << v << " ";

  return 0;
}