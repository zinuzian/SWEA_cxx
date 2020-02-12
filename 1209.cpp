#include<iostream>

using namespace std;
int main(int argc, char** argv)
{
	int test_case;
	int T=10;
	// freopen("input.txt", "r", stdin);
	// cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int answer = 0;
        int t;
        // int map[100][100];
        int sum[202] = {0,};
        cin >> t;
        for(int y=0;y<100;y++){
            for(int x=0;x<100;x++){
                cin >> t;
                sum[y] += t;
                sum[100+x] += t;
                if(x == y)
                    sum[200] += t;
                else if(x+y==99)
                    sum[201] += t;
            }
        }

        
        for(int it:sum){
            if(answer < it)
                answer = it;
        }
        
        cout << "#" << test_case << " " << answer << endl;
	}
	return 0;
}