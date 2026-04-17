#include<bits/stdc++.h>
using namespace std;
// int main(){
//     int t;cin>>t;
//     while(t--){
//         int n;cin>>n;
//         vector<int>a(n);
//         for(int &i:a)cin>>i;
//         int ans=0;
//         for(int i=0;i<n;i++){
//             for(int j=i+1;j<n;j++){
//                 ans=max(ans,a[i]^a[j]);
//             }
//         }cout<<ans<<endl;
//     }
// }
const int maxN=3e5*31;
vector<int>a;
int trie[maxN][2];
int nCnt=1;

struct TrieNode{
    int child[2];
    TrieNode(){
        child[0]=child[1]=-1;
    }
};
struct BinaryTrie{
    vector<TrieNode>trie;
    BinaryTrie(){
        trie.push_back(TrieNode());
    }
    void insert(int v){
        int nd=0;
        for(int i=30;i>=0;i--){
            int bit=(v>>i)&1;
            if(trie[nd].child[bit]==-1){
                trie[nd].child[bit]=trie.size();
                trie.push_back(TrieNode());
            }
            nd=trie[nd].child[bit];
        }
    }
    int maxXor(int v){
        int nd=0;
        int ans=0;
        for(int i=30;i>=0;i--){
            int bit=(v>>i)&1;
            int want=1-bit;
            if(trie[nd].child[want]!=-1){
                ans|=(1<<i);
                nd=trie[nd].child[want];
            }else{
                nd=trie[nd].child[bit];
            }
        }
        return ans;
    }
};


int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        a.assign(n,0);
        for(int&i:a)cin>>i;
        BinaryTrie bt;
        bt.insert(a[0]);
        int ans=0;
        for(int i=1;i<n;i++){
            ans=max(ans,bt.maxXor(a[i]));
            bt.insert(a[i]);
        }
        cout<<ans<<endl;
    }
    return 0;
}