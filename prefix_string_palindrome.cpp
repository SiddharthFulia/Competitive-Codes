//https://web.archive.org/web/20210215025640/https://www.hackerearth.com/practice/basic-programming/implementation/basics-of-implementation/practice-problems/algorithm/ispalin/
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
const ll N=(ll)(1e5)+10;
ll hash_value[N][26];
void solve(){
   ll n,i,j,q;
   cin>>n>>q;
   string s;
   cin>>s;
   for(i=0;i<=n;i++){
    for(j=0;j<26;j++){
        hash_value[i][j]=0;
    }
   }
   for(i=0;i<n;i++){
    hash_value[i+1][s[i]-'a']++;
   }
   for(i=1;i<=n;i++){
    for(j=0;j<26;j++){
        hash_value[i][j]+=hash_value[i-1][j];
    }
   }
   while(q--){
    ll l,r;
    cin>>l>>r;
    ll odd_count=0;
    for(i=0;i<26;i++){
        if((hash_value[r][i]-hash_value[l-1][i])%2) odd_count++;
    }
    if(odd_count>1){
        cout<<"NO";
    }
    else{
        cout<<"YES";
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
/*INPUT
2
5 5
abcec
1 2
2 5
3 5
1 5
1 4
5 5
aabbc
1 2
2 5
3 5
1 5
1 4
*/