//https://leetcode.com/problems/generate-parentheses/submissions/889828916/
#include <bits/stdc++.h>
using namespace std;
// using namespace std::chrono;
// #pragma GCC target ("avx2")
// #pragma GCC optimization ("O3")
// #pragma GCC optimization ("unroll-loops")
//if RE then remove above 3 lines
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long 
#define ull unsigned long long 
#define ld long double
#define vt vector
#define ml multiset
#define pb push_back
#define mp make_pair
#define pob pop_back
#define all(c) c.begin(),c.end()
#define each(x,a) for(auto &x:a)
#define sz(x) (ll)(x).size()
// const ll M=(ll)(1e9)+7;
// const ll N=(ll)(1e5)+10;

vt<string> valid;

void generate(string &s,ll open,ll close){
  if(open==0 && close==0){
    valid.pb(s);
    return;
  }
  if(open>0){
    s.pb('(');
    generate(s,open-1,close);
    s.pop_back();//backtrack or pop the last letter to maintain the state of string in current function
  }
  if(close>0){
    if(open<close){
      s.pb(')');
      generate(s,open,close-1);
      s.pop_back();
    }
  }
}

void solve(){
   ll n,i;
   cin>>n;
   string s;
   generate(s,n,n);
   each(x,valid){
    cout<<x;
    cout<<"\n";
   }
}
int main(){
    // auto start = high_resolution_clock::now();
    // cout<<fixed<<setprecision(2);
    #ifndef ONLINE_JUDGE
    freopen("ip.txt","r",stdin);
    freopen("op.txt","w",stdout);
    #endif
    FastIO;
    ll t=1;
    // ll i=1;
    // cin>>t;
    while(t--){
    // cout<<"Case #"<<i<<": ";
    solve();
    // cout<<"\n";
    // i++;
    }
    //  auto stop = high_resolution_clock::now();
    //   auto duration = duration_cast<microseconds>(stop - start);cout << "Time taken by function: "
    //      << duration.count() << " microseconds" << endl;
    return 0;
}
/*INPUT
2
*/