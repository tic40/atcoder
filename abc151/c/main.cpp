#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
typedef long long ll;

int main() {
  int n,m;
  cin>>n>>m;
  int p; string s;
  map <int, string> x;
  REP(i,m) {
    cin >> p >> s;
    x[p-1] += (s == "AC" ? "A" : "W");
  }
  int ans1=0,ans2=0;
  REP(i,n) {
    int tmp=0;
    REP(j,x[i].size()) {
      if (x[i][j] == 'A') {
        ans2+=tmp;
        ans1++;
        break;
      } else { tmp++; }
    }
  }

  cout << ans1 << " " << ans2 << endl;
}