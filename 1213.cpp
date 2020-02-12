#include<iostream>

using namespace std;
int main(int argc, char** argv)
{
	int test_case;
	int T=10;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	// freopen("input.txt", "r", stdin);
	// cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int answer=0;
        int t;
        char query[11];
        char str[1001];
        cin >> t;
        cin >> query;
        cin >> str;
        
        string q(query);
        string s(str);
        int found = s.find(q,found+1);
        while(found != s.npos){
            found = s.find(q,found+1);
            answer += 1;
        }
        cout << "#" << test_case << " " << answer << endl;
	}
	return 0;
}