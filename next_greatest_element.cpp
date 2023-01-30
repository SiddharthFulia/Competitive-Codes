//https://www.hackerrank.com/contests/second/challenges/next-greater-element/problem
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
#define pb push_back
#define mp make_pair
#define pob pop_back
#define all(c) c.begin(),c.end()
#define each(x,a) for(auto x:a)
#define sz(x) (ll)(x).size()
const ll M=(ll)(1e9)+7;

vt<ll> next_greatest_element(vt<ll> v){
   //Here nge stores index values and -1 for elements in stack that are left at the end
   ll i;
   ll n=sz(v);
   vt<ll> nge(n);
   stack <ll> st;
   for(i=0;i<n;i++){
      while(!st.empty()&&v[i]>v[st.top()]){
      nge[st.top()]=i;
      st.pop();
      }
      st.push(i);
   }
   while(!st.empty()){
      nge[st.top()]=-1;
      st.pop();
   }
   return nge;
}

void solve(){
   ll n,i;
   cin>>n;
   vt<ll> a(n);
   for(i=0;i<n;i++){
      cin>>a[i];
   }
   vt<ll> nge(n);
   nge=next_greatest_element(a);
   for(i=0;i<n;i++){
      cout<<a[i]<<" "<<(nge[i]==-1 ? -1 : a[nge[i]])<<"\n";
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
    //  cin>>t;
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
4
4 5 2 25
*/