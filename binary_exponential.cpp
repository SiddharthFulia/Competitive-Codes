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
// const ll N=1e5+10;
// const ll N1=INT_MAX;
const ll M=1e9+7;
// ll bit_arr[32];
// bool vector_second_sort(const pair<ll,ll> &a,const pair<ll,ll> &b){
//     return (a.second<b.second);
// }
// vt<ll> to_binary(vt<ll> v,ll x){
//    while(x){
//       v.pb(x%2);
//       x/=2;
//    }
//    return v;
//    //Not reversed
// }
// ll to_decimal(vt<ll>v){
//    ll x,i;
//    for(i=0;i<sz(v);i++){
//       if(v[i]==1){
//          x+=pow(2,i);
//       }
//    }
//    return x;
//    //Ascending order vector
// }
// ll binary_exponential_reccursive(ll a,ll b){
//    //remove %M if not given in question
//    if(b==0) return 1;
//    ll res=binary_exponential_reccursive(a,b/2);
//    if(b&1){
//       return (a*(res*res)%M)%M;
//    }
//    else{
//       return (res*res)%M;
//    }
// }
ll binary_exponential_iterative(ll a,ll b){
   //remove %M if not given in question
   ll ans=1;
   while(b){
      if(b&1){
         ans*=a;
         ans%=M;
      }
      a=(a*a)%M;
      b>>=1;//right shift
   }
   return ans;
}
void solve(){
   ll x,y;
   cin>>x>>y;
   cout<<binary_exponential_iterative(x,y);
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