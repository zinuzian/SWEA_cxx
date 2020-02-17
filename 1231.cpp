#include <iostream>
#include <vector>
#include <cstring>
#include <string>

using namespace std;
void inorder(vector<vector<int>>& arr, int idx, const vector<char>& alphabets){
    
    if(arr[idx][0] != 0)
        inorder(arr, arr[idx][0], alphabets);
    cout << alphabets[idx];
    if(arr[idx][1] != 0)
        inorder(arr, arr[idx][1], alphabets);
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
        vector<vector<int>> arr(1);
        vector<char> alphabets(n+1);
        string sinput;
        getline(cin, sinput);
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
                    alphabets[idx] = token[0];
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


        cout << "#" << test_case << " ";
        inorder(arr, 1, alphabets);
        cout << endl;
	}
	return 0;
}