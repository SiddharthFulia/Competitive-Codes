//https://www.hackerrank.com/challenges/balanced-brackets/problem
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
const ll M=(ll)(1e9)+7;
const ll N=(ll)(1e5)+10;
unordered_map<char,int> symbols={{'[',-1},{'{',-2},{'(',-3},{']',1},{'}',2},{')',3}};
string isBalanced(string s) {
  stack<char> st;
  ll i;
  each(bracket,s){
    if(symbols[bracket]<0){
      st.push(bracket);
    }
    else{
      if(st.empty()) goto aaa;
      if((symbols[bracket]+symbols[st.top()])!=0) goto aaa;
      st.pop();
    }
  }
  if(st.empty()) return "YES";
  aaa:
  return "NO";
}
void solve(){
   ll n,i,k;
   cin>>n;
   while(n--){
    string s;
    cin>>s;
    cout<<isBalanced(s);
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
3               
{[()]}          
{[(])}          
{{[[(())]]}}  
*/