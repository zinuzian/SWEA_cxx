#include <iostream>
#include <vector>
#include <map>
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
        int answer=1;
        int n;
        fflush(stdin);
        cin >> n;
        char* str = new char[n+1];
        map<char, char> mapping = {
            {'{', '}'},
            {'[',']'},
            {'(',')'},
            {'<','>'}
        };
        vector<char> stack;
        cin >> str;
        
        for(int i=0;i<n;i++){
            char c = str[i];
            if(c == '(' || c == '{' || c == '[' || c == '<'){
                stack.push_back(c);
            }else{
                if(stack.size()>0 && mapping[stack.back()] == c){
                    stack.pop_back();
                }else{
                    answer = 0;
                    break;
                }
            }
        }
        if(stack.size() != 0) answer = 0;
        cout << "#" << test_case << " " << answer << endl;
	}
	return 0;
}