#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
typedef long long ll;

int main() {
  int a[26],ans;
  string w; cin>>w;
  REP(i,26) a[i]=0;
  REP(i,w.size()) a[w[i]-'a']++;
  REP(i,26) if(a[i]%2) { cout << "No" <<endl; return 0;};
  cout << "Yes" << endl;
}
