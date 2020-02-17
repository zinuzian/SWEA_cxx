#include <iostream>
#include <vector>
#include <cstring>
#include <string>

using namespace std;

vector<char*> nodes;
vector<vector<int>> arr;

void init(int n){
    nodes.clear();
    arr.clear();
    nodes = vector<char*>(n+1);
    arr = vector<vector<int>>(1);
}
float inorder(vector<vector<int>>& arr, int idx){
    
    if( !strcmp(nodes[idx], "+") ) return inorder(arr,arr[idx][0]) + inorder(arr,arr[idx][1]);
    else if( !strcmp(nodes[idx], "-") ) return inorder(arr,arr[idx][0]) - inorder(arr,arr[idx][1]);
    else if( !strcmp(nodes[idx], "*") ) return inorder(arr,arr[idx][0]) * inorder(arr,arr[idx][1]);
    else if( !strcmp(nodes[idx], "/") ) return inorder(arr,arr[idx][0]) / inorder(arr,arr[idx][1]);
    else return atoi(nodes[idx]);
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
        int n;
        cin >> n;
        string sinput;
        getline(cin, sinput);
        init(n);
        for(int i=0;i<n;i++){
            vector<int> row(2,0);
            char input[30] = {0,};
            cin.getline(input, sizeof(char)*30);
            int j=0, idx;            
            char* token = strtok(input, " ");
            while(token != NULL){
                switch(j){
                case 0:
                    idx = atoi(token);
                    break;
                case 1:
                    nodes[idx] = strdup(token);
                    break;
                case 2:
                    row[0] = atoi(token);
                    break;
                case 3:
                    row[1] = atoi(token);
                    break;
                }
                ++j;
                token = strtok(NULL, " ");
            }
            arr.push_back(row);
            

        }
        int answer = (int)inorder(arr, 1);

        cout << "#" << test_case << " " << answer << endl;
	}
	return 0;
}