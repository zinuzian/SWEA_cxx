 #include <iostream>
#include <vector>
// #include <queue>
// #include <stack>
#include <cstring>

using namespace std;


bool visited[1000] = {false};
vector<vector<int>> vertex;
vector<vector<int>> temp;
vector<int> result;

void init(){
    memset(visited, false, sizeof(bool)*1000);
    for(int i=0;i<vertex.size();i++){
        temp[i].clear();
        vertex[i].clear();
    }
    temp.clear();
    vertex.clear();
    result.clear();
}


void dfs(int x){
    
    for(int i=0;i<vertex[x].size();i++){
        int nx = vertex[x][i];
        if(!visited[nx]){
            visited[nx] = true;
            dfs(nx);
        }
    }
    result.push_back(x+1);
}


int main(int argc, char** argv)
{
	int test_case;
	int T=10;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	freopen("input.txt", "r", stdin);
	// cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        init();
        int v,e;
        cin >> v >> e;
        
        for(int i=0;i<v;i++){
            vector<int> row;
            vector<int> trow;
            vertex.push_back(row);
            temp.push_back(trow);
        }
        for(int i=0;i<e;i++){
            // 반대로 받기
            int s, e;
            cin >> s >> e;
            temp[s-1].push_back(e-1);
        }

        for(int i=0;i<v;i++){
            for(int j=0;j<temp[i].size();j++){
                vertex[temp[i][j]].push_back(i);
            }
        }
        vector<int> cand;
        for(int i=0;i<v;i++){
            if(temp[i].size() == 0){
                cand.push_back(i);
            }
        }
        for(auto i: cand){
            visited[i] = true;
            dfs(i);
        }

        cout << "#" << test_case << " ";
        for(auto i:result){
            cout << i << " ";
        }
        cout << endl;

    }
    return 0;
}