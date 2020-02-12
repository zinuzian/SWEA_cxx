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
        int palen;
        cin >> palen;
        char board[8][8];

        cin.get();
        for (int y = 0; y < 8; y++)
        {
            for (int x = 0; x < 8; x++)
            {
                board[y][x] = (char)cin.get();
            }
            cin.get();
        }

        for (int y = 0; y < 8; y++)
        {
            for (int x = 0; x < 8; x++)
            {
                int k;
                //x
                if (x <= 8 - palen)
                {
                    for (k = 0; k < palen / 2; k++)
                    {
                        if (board[y][x + k] != board[y][x + palen - 1 - k])
                            break;
                    }
                    if (k == palen / 2)
                    {
                        answer += 1;
                    }
                }

                //y
                if (y <= 8 - palen){
                    for (k = 0; k < palen / 2; k++)
                    {
                        if (board[y + k][x] != board[y + palen - 1 - k][x])
                            break;
                    }
                    if (k == palen / 2)
                    {
                        answer += 1;
                    }
                }
            }
        }

        cout << "#" << test_case << " " << answer << endl;
    }
    return 0;
}