//https://www.spoj.com/problems/EKO/
//https://www.youtube.com/watch?v=JAfJssvFgDI&list=PLauivoElc3ggagradg8MfOZreCMmXMmJ-&index=53
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
const ll N=(ll)(1e6)+10;
ll trees[N];

bool isWoodSufficient(ll h,ll n,ll m){
  ll i,ans=0;
  for(i=0;i<n;i++){
    if(trees[i]>=h){
    ans+=trees[i]-h;
    }
  }
  return ans>=m;
}

void solve(){
   ll n,i,m;
   cin>>n>>m;
   for(i=0;i<n;i++){
    cin>>trees[i];
   }
   ll lo=0,hi=1e9,mid;
   while(hi-lo>1){
    mid=(hi+lo)/2;
    //predicate function
    //T T T T T F F F F F F 
    if(isWoodSufficient(mid,n,m)){
      lo=mid;
    }
    else hi=mid-1;
   }
   if(isWoodSufficient(hi,n,m)){
    cout<<hi;
   }
   else cout<<lo;
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
2 3
*/