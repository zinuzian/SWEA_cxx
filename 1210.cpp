#include<iostream>
#include<vector>
using namespace std;
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
        int answer=0;
        int t;
        int ladder[100][102];
        cin >> t;
        for(int i=99;i>=0;i--){
            ladder[i][0] = 0;
            ladder[i][101] = 0;
            for(int j=1;j<101;j++){
                cin >> ladder[i][j];
            }
        }
        
        vector<int> yaxis;
        for(int i=1;i<101;i++){
            if(ladder[99][i] == 1)
                yaxis.push_back(i);
        }
        
        for(int i=0;i<yaxis.size();i++)
            if (ladder[0][yaxis[i]] == 2){
                answer = i;
                break;
            }
        
        for(int y=0;y<100;y++){
            if(ladder[y][yaxis[answer]-1] == 0 && ladder[y][yaxis[answer]+1] == 0) 
                continue;
            if(ladder[y][yaxis[answer]-1] == 1 && ladder[y][yaxis[answer]+1] == 0) 
                answer -= 1;
            else if(ladder[y][yaxis[answer]-1] == 0 && ladder[y][yaxis[answer]+1] == 1) 
                answer += 1;
        }
        answer = yaxis[answer] - 1;

        cout << "#" << test_case << " " << answer << endl;
	}
	return 0;
}