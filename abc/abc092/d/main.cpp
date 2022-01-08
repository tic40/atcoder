#include <bits/stdc++.h>
using namespace std;
#define COUT(x) cout<<(x)<<"\n"
#define REP(i,n) for(int i=0;i<n;i++)

int a,b;
const int h=100,w=100;
char g[h][w];

int main() {
  cin >> a >> b;
  a--; b--;

  REP(i,h) REP(j,w) g[i][j] = i<h/2 ? '#' : '.';

  for (int i=0; i<h; i+=2) {
    if (h/2+(h/2)%2+2 == i) swap(a,b);
    for (int j=0; j<w; j+=2) {
      if (a==0) break;
      g[i][j] = g[i][j] == '.' ? '#' : '.';
      a--;
    }
  }

  cout << h << " " << w << endl;
  REP(i,h) REP(j,w) {
    cout << g[i][j];
    j == w-1 && cout << endl;
  }
  return 0;
}