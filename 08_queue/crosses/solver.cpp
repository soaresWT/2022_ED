#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<char> time;
    int time1, time2;

    for (char i = 'A'; i < 'Q'; i++)
        time.push(i);

    for (int i = 0; i < (int)time.size(); i++)
    {
        cin >> time1 >> time2;

        if (time1 > time2)
        {
            time.push(time.front());
            time.pop();
            time.pop();
        }
        else
        {
            time.pop();
            time.push(time.front());
            time.pop();
        }
    }

    cout << time.front() << endl;

    return 0;
}