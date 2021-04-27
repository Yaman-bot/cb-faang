#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

void convert(string str, int &id, string &operation, int &time)
{
    int i = 0;
    id = time = 0;
    while (str[i] != ':')
    {
        id = id * 10 + str[i] - '0';
        i++;
    }
    i++;
    while (str[i] != ':')
    {
        operation.push_back(str[i]);
        i++;
    }
    i++;
    while (i < str.length())
    {
        time = time * 10 + str[i] - '0';
        i++;
    }
    if (operation == "end")
    {
        time++;
    }
}

vector<int> operation_time(int n, vector<string> &logs)
{
    vector<int> duration(n, 0);
    stack<int> s;
    int prev_time;
    for (int i = 0; i < logs.size(); i++)
    {
        int id, time;
        string operation;
        convert(logs[i], id, operation, time);
        if (!s.empty())
        {
            int functionId = s.top();
            duration[functionId] += (time - prev_time);
        }
        prev_time = time;

        if (operation == "start")
            s.push(id);
        else
            s.pop();
    }
    return duration;
}

int main()
{
}