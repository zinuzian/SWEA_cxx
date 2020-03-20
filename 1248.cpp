#include <iostream>
#include <cstring>
using namespace std;

int parCom, answer;
int tree[10002][2];
int cnt[10002];
int parent[10002];
int v,e,x1,x2;

void init(){
    memset(tree, 0, sizeof(int)*(v+1)*2);
    memset(cnt, 0, sizeof(int)*(v+1));
    memset(parent, 0, sizeof(int)*(v+1));
    answer = 0;
}
int dfs_subtreeCount(int v, bool* found){
    int ret = 1;
    for(int i=0;i<2;i++){
        if(tree[v][i] != 0){
            if(tree[v][i] == x2){
                *found = true;
            }
            ret += dfs_subtreeCount(tree[v][i], found);
        }
    }
    return ret;
}
int main(int argc, char const *argv[])
{
    int T= 10;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);
    cin >> T;
    for(int test_case = 1; test_case <= T; test_case++){
        
        cin >> v >> e >> x1 >> x2;
        init();
        
        for(int i=0;i<e;i++){
            int p,c;
            cin >> p >> c;
            tree[p][cnt[p]] = c;
            cnt[p] += 1;
            parent[c] = p;
        }

        int parents[10000];
        int pCnt=0;
        bool found = false;
        parCom = x1;
        answer += dfs_subtreeCount(parCom, &found);
        do{
            parents[pCnt++] = parent[parCom];
            int temp = parCom;
            parCom = parent[parCom];
            if(cnt[parCom] == 2){
                for(int i=0;i<2;i++){
                    if(tree[parCom][i] != temp){
                        answer += dfs_subtreeCount(tree[parCom][i], &found);
                    }
                }
            }
            answer += 1;
        }while(parCom != 1 && !found);

        cout << "#" << test_case << " " << parCom << " " << answer << endl;
    }
}