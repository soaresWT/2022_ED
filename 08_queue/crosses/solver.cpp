#include <iostream>
#include <queue>
using namespace std;

void jogos(queue<char> &time)
{
    int time1 = 0;
    int time2 = 0;

    for (int i = 0; i < (int)time.size(); i++)
    {
        cin >> time1 >> time2;

        if (time1 > time2)
        {
            // cout << time.front() << endl;
            time.push(time.front());
            time.pop();
            time.pop();
        }
        else
        {
            time.pop();
            // cout << time.front() << endl;
            time.push(time.front());
            time.pop();
        }
    }
}
int main()
{
    queue<char> time;
    for (char i = 'A'; i < 'Q'; i++)
        time.push(i);

    jogos(time);
    cout << time.front() << endl;

    return 0;
}