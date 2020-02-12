#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int visited[101];
vector<vector<int>> queue;
vector<vector<int>> contact;
vector<int> last;

void init(){
    memset(visited, 0, sizeof(int)*101);
    contact.clear();
    contact = vector<vector<int>>(101);
}
int bfs(){
    int depth_max = 0;
    while(!queue.empty()){
        vector<int> me = queue[0];
        // cout << me[0] << endl;
        if(depth_max < me[1]){
            if(me[1] == 4){
                // cout << endl;
            }
            depth_max = me[1];
        }
        vector<int> neighbor = contact[me[0]];
        for(int i=0;i<neighbor.size();i++){
            if(visited[neighbor[i]] == 0){
                vector<int> node(2);
                node[0] = neighbor[i];
                node[1] = me[1] + 1;
                visited[node[0]] = node[1];
                queue.push_back(node);
            }
            
        }
        queue.erase(queue.begin());
    }
    return depth_max;
    
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
        int n,start;
        int answer;
        cin >> n >> start;
        
        for(int i=0;i<n/2;i++){
            int s, e;
            cin >> s >> e;
            bool found = false;
            for(int nei:contact[s]){
                if(nei == e){
                    found = true;
                }
            }
            if(!found){
                contact[s].push_back(e);
            }
            
        }
        vector<int> start_node;
        start_node.push_back(start);
        start_node.push_back(1);
        queue.push_back(start_node);
        visited[start] = 1;
        int max = bfs();
        for(int i=0;i<101;i++){
            if(visited[i] == max){
                answer = i;
            }
        }
        cout << "#" << test_case << " " << answer << endl;
    }
}