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
        int answer=0;
        int len;
        cin >> len;
        vector<char> op;
        vector<char> postfix;
        for(int i=0;i<len;i++){
            char c;
            cin >> c;

            if(c == '+'){
                char top = op.back();
                
                while(!op.empty() && top != '('){
                    op.pop_back();
                    postfix.push_back(top);
                    top = op.back();    
                }
                op.push_back(c);

            }else if(c == '*'){
                char top = op.back();
                
                while(!op.empty() && (top != '+' && top != '(')){
                    op.pop_back();
                    postfix.push_back(top);
                    top = op.back();    
                }
                op.push_back(c);
            }else if(c == '('){
                op.push_back(c);
            }else if(c == ')'){
                char top = op.back();
                while(top != '('){
                    op.pop_back();
                    postfix.push_back(top);
                    top = op.back();    
                }
                op.pop_back();
            }else{
                postfix.push_back(c);
            }
        }
        
        vector<int> stack;
        // char top = postfix[0];
        for(int i=0;i<postfix.size();i++){
            if(postfix[i] == '+'){
                int a,b;
                a = stack.back();
                stack.pop_back();
                b = stack.back();
                stack.pop_back();
                stack.push_back(a+b);
            }else if(postfix[i] == '*'){
                int a,b;
                a = stack.back();
                stack.pop_back();
                b = stack.back();
                stack.pop_back();
                stack.push_back(a*b);
            }else{
                stack.push_back(postfix[i] - '0');
            }
        }

        answer = stack[0];

        cout << "#" << test_case << " " << answer << endl;
	}
	return 0;
}