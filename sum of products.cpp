/// Given a number N,
/// find the sum of all products x * y
///such that N / x = y (integer division)

/// Spoj problem - (SUMPRO - SUM OF PRODUCT)


#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
typedef long long int ll;


using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define mod 1000000007

ll lcm(ll a,ll b)
{
    return (a*b)/__gcd(a,b);
}


ll binExp(ll a,ll b)
{
    if(b==0)
        return 1;

    ll res=binExp(a,b/2);

    if(b&1)
    {
        return (a*res*res)%mod;

    }
    else
    {
        return (res*res)%mod;
    }
}

ll rangeSum(ll high,ll low)
{
    ll x=(high*(high+1))/2;
    ll y=(low*(low+1))/2;

    return x-y;
}


void solve()
{
   ll n;
   cin>>n;

   ll root = sqrt(n);


   ll ans=0;

   for(ll i=1; i<=root; i++)
   {
       ll low=max(root,(n/(i+1)));
       ll high=(n/i);

       ans+=(i*rangeSum(high,low))%mod;
       ans+=(i*(n/i))%mod;
   }


   cout<<(ans%mod)<<endl;



}
















int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);







    ll t;

    cin>>t;
    //t=1;





    ll caseNo=1;



    while(t--)
    {
        //  cout<<"Case "<<caseNo<<": ";
        // caseNo++;

        solve();


    }




    return 0;

}
