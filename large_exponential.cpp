//https://www.codechef.com/problems/FEXP
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
const ll M=(ll)(1e18)+7;
ll binary_multiplication(ll a,ll b){
    ll ans=0;
    while(b>0){
        if(b&1){
            ans=(ans+a)%M;
        }
        a=(a+a)%M;
        b>>=1;
    }
    return ans;
}

ll large_exponential_iterative(ll a,ll b){
   ll ans=1;
   while(b){
      if(b&1){
         ans=binary_multiplication(ans,a);
      }
      a=binary_multiplication(a,a);
      b>>=1;//right shift
   }
   return ans;
}

void solve(){
   ll x,y;
   cin>>x>>y;
   cout<<large_exponential_iterative(x,y);
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
    ll t;
    // ll i=1;
    cin>>t;
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