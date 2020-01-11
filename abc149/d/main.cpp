#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)

int n,k,r,s,p;
string t;

int getP(char c) {
  if (c == 'r') return r;
  else if (c == 'p') return p;
  else return s;
}

int main() {
  cin>>n>>k>>r>>s>>p>>t;
  int ans = 0;
  char hands[n];
  REP(i, n) {
    if (t[i] == 'r'){
      ans+=p; hands[i] = 'p';
    } else if (t[i] == 's') {
      ans+=r; hands[i] = 'r';
    } else {
      ans+=s; hands[i] = 's';
    }
  }

  for(int i = k; i < n; i++) {
    char last = hands[i-k];
    char hand = hands[i];
    if (hand != last) continue;

    int curP = getP(hand), lastP = getP(last);
    if (curP > lastP) { ans -= lastP; }
    else { ans -= curP; hands[i] = '_'; }
  }
  cout << ans << endl;
}