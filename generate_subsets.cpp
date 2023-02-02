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

vt<vt<ll>> subsets;

void generate_subsets(vt<ll> &subset,ll i,ll n,ll a[]){
  if(i==n){
    subsets.pb(subset);
    return;
  }
  //ith element not considered
  generate_subsets(subset,i+1,n,a);
  //ith element is considered
  subset.pb(a[i]);
  generate_subsets(subset,i+1,n,a);
  subset.pop_back();
}

void solve(){
   ll n,i;
   cin>>n;
   ll a[n];
   for(i=0;i<n;i++){
    cin>>a[i];
   }
   vt<ll> subset;
   generate_subsets(subset,0,n,a);
   //1st subset is empty subset so nothing is printed
   each(subset,subsets){
    each(x,subset){
      cout<<x<<" ";
    }
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
1 2 3
*/