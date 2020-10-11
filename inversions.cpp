#include <bits/stdc++.h>

using namespace std;
#define pb push_back
#define fo(i, n) for (i = 0; i < n; i++) 
typedef pair<char,char> pcc;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vector<int> > vii;
typedef long long ll;
ll merge(ll arr[], ll temp[], ll left, ll mid, ll right) 
{ 
    ll i, j, k; 
    ll inv_count = 0; 
    i = left; 
    j = mid; 
    k = left; 
    while ((i <= mid - 1) && (j <= right)) { 
        if (arr[i] <= arr[j]) { 
            temp[k++] = arr[i++]; 
        } 
        else { 
            temp[k++] = arr[j++]; 
            inv_count = inv_count + (mid - i); 
        } 
    } 
    while (i <= mid - 1) 
        temp[k++] = arr[i++]; 
  
    while (j <= right) 
        temp[k++] = arr[j++]; 
  
    for (i = left; i <= right; i++) 
        arr[i] = temp[i]; 
  
    return inv_count; 
}
int _mergeSort(ll arr[], ll temp[], ll left, ll right) 
{ 
    int mid, inv_count = 0; 
    if (right > left) { 
        
        mid = (right + left) / 2; 
        inv_count += _mergeSort(arr, temp, left, mid); 
        inv_count += _mergeSort(arr, temp, mid + 1, right); 
        inv_count += merge(arr, temp, left, mid + 1, right); 
    } 
    return inv_count; 
}
ll inv(ll arr[], ll array_size) 
{ 
    ll temp[array_size]; 
    return _mergeSort(arr, temp, 0, array_size - 1); 
}
int main(){
    #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  
    int t; cin>>t;

    while(t--){
        ll i,j,n,k;
        cin>>n;
        ll arr[n];
        fo(i,n){
            cin>>arr[i];
        }
        cout<<inv(arr,n)<<"\n";
    }
    return 0;
}