#include <iostream>
#include <vector>
#include <thread>
#include <list>
#include <random>
#include "Struct.h"
using namespace std;

void f1(vector<vector<int>>& vec, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            for (int k = 0; k < n - 1 - j; k++)
            {
                if (vec[i][k] > vec[i][k + 1])
                {
                    swap(vec[i][k], vec[i][k + 1]);
                }
            }
        }
    }
}
void f2(list<int>& l, vector<int> vec)
{
    list<int> l2;
    int iv = 0;
    for (auto i = l.begin(); i != l.end(); i++)
    {
        if (*i != vec[iv])
        {
            l2.push_back(*i);
        }
        else
        {
            auto j = i;
            bool flag = true;
            for (int jv = 0; jv < vec.size(); jv++, j++)
            {
                if (*j == vec[jv])
                {
                    flag = true;
                }
                else
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                i = j;
                i--;
            }
            else
            {
                l2.push_back(*i);
            }
        }
    }
    l.erase(l.begin(), l.end());
    for (auto i = l2.begin(); i != l2.end(); i++)
    {
        l.push_back(*i);
    }
}

void srt(vector<int>& vec, bool flag)
{
    for (int i = 0; i < vec.size() - 1; i++)
    {
        for (int j = 0; j < vec.size() - 1 - i; j++)
        {
            if (flag && vec[j] > vec[j + 1])
            {
                swap(vec[j], vec[j + 1]);
            }
            if (!flag && vec[j] < vec[j + 1])
            {
                swap(vec[j], vec[j + 1]);
            }
        }
    }
}
void f3()
{
    vector<int> vec = { 74,7,2,9,2,6,4,42,26,842,794 };
    thread t1(srt, ref(vec), true);
    thread t2(srt, ref(vec), false);
    thread t3(srt, ref(vec), true);
    t1.join();
    t2.join();
    t3.join();
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << ' ';
    }
}

void f4(list<student>& l)
{
    for (auto i = l.begin(); i != l.end(); i++)
    {
        int t = i->h;
        cout << t << ' ';
    }
    auto max = l.begin(), min = l.begin();

    for (auto i = l.begin(); i != l.end(); i++)
    {
        int maxh = max->h, minh = min->h, h = i->h;
        if (h > maxh) max = i;
        if (h < minh) min = i;
    }
    swap(max, min);
    for (auto i = l.begin(); i != l.end(); i++)
    {
        int t = i->h;
        cout << t << ' ';
    }
}

int main()
{


}
