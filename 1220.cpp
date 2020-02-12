#include<iostream>

using namespace std;
int main(int argc, char** argv)
{
	int test_case;
	int T=10;
	// freopen("input.txt", "r", stdin);
	// cin>>T;
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	
    int DOWN = 1;
    int UP = 2;
    for(test_case = 1; test_case <= T; ++test_case)
	{
        int answer=0;
        int size, t;
        bool blocked[100] = {0};
        cin >> size;

        // 1이 왼쪽 2가 오른쪽
        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                cin >> t;
                if(t == UP){
                    if(!blocked[j])
                        continue;
                    else{
                        answer += 1;
                        blocked[j] = false;
                    }
                }
                if(t == DOWN){
                    blocked[j] = true;
                }
            }
        }

        cout << "#" << test_case << " " << answer << endl;
	}
	return 0;
}