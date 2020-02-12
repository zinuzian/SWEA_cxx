#include <iostream>
#include <vector>
#include <cstring>
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
        int t;
        vector<int> q;
        cin >> t;
        int min = 2147483647;
        for(int i=0;i<8;i++){
            int c;
            cin >> c;
            if(min > c){
                min = c;
            }
            q.push_back(c);
        }
        int loop = min / 15 - 1; // 1+2+3+4+5
        
        for(int i=0;i<8;i++){
            q[i] -= loop*15;
        }
        int l=0;
        while(q[7] != 0){
            l = l%5+1;
            int temp = q[0] - l;
            q.erase(q.begin());
            temp = temp>0? temp:0;
            q.push_back(temp);
        }

        cout<<"#"<<test_case<< " ";
        for(int i:q){
            cout << i << " ";
        }
        cout << endl;

    }
    return 0;
}