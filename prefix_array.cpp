//https://www.hackerrank.com/challenges/crush/problem
//https://www.youtube.com/watch?v=4wqDE1zNUwc
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
const ll N=(ll)(1e7)+10;
ll prefix[N];
void solve(){
   ll n,i,q;
   cin>>n>>q;
   while(q--){
      ll a,b,d;
      cin>>a>>b>>d;
      prefix[a]+=d;
      prefix[b+1]-=d;
   }
   for(i=1;i<=n;i++){
         prefix[i]+=prefix[i-1];
   }
   ll max1=INT_MIN;
   for(i=1;i<=n;i++){
      max1=max(max1,prefix[i]);
   }
   cout<<max1;
   cout<<"\n";
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
5 3
1 2 100
2 5 100
3 4 100
*/