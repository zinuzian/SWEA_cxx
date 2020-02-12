#include <iostream>
#include <vector>
// #include <queue>
// #include <stack>
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
        int n;
        cin >> n;
        vector<char> stack;

        for(int i=0;i<n;i++){
            char c;
            cin >> c;
            if(stack.empty()){
                stack.push_back(c);
            }else{
                char top = stack.back();
                if(top == c){
                    stack.pop_back();
                }else{
                    stack.push_back(c);
                }
            }
            
        }



        cout << "#" << test_case << " ";
        for(auto i:stack){
            cout << i;
        }
        cout << endl;

    }
}