#include <iostream>

using namespace std;
int main(int argc, char **argv)
{
    int test_case;
    int T = 10;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // cin>>T;
    for (test_case = 1; test_case <= T; ++test_case)
    {
        int answer = 0;
        int palen, t;
        cin >> t;
        char board[100][100];

        cin.get();
        for (int y = 0; y < 100; y++)
        {
            for (int x = 0; x < 100; x++)
            {
                board[y][x] = (char)cin.get();
            }
            cin.get();
        }



        for (int y = 0; y < 100; y++)
        {
            for (int x = 0; x < 100; x++)
            {
                for(int palen=1;palen<=100;palen++){

                    int k;
                    //x
                    if (x <= 100 - palen)
                    {
                        for (k = 0; k < palen / 2; k++)
                        {
                            if (board[y][x + k] != board[y][x + palen - 1 - k])
                                break;
                        }
                        if (k == palen / 2)
                        {
                            answer = (answer > palen)? answer:palen;
                        }
                    }

                    //y
                    if (y <= 100 - palen){
                        for (k = 0; k < palen / 2; k++)
                        {
                            if (board[y + k][x] != board[y + palen - 1 - k][x])
                                break;
                        }
                        if (k == palen / 2)
                        {
                            answer = (answer > palen)? answer:palen;
                        }
                    }
                }
            }
        }

        cout << "#" << test_case << " " << answer << endl;
    }
    return 0;
}