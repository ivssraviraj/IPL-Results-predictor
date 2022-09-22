#include <bits/stdc++.h>
using namespace std;

vector<pair<string, pair<int, int>>> table;

bool comp(pair<string, pair<int, int>> p1, pair<string, pair<int, int>> p2)
{
    if (p1.second.first == p2.second.first)
        return p1.second.second < p2.second.second;

    return p1.second.first > p2.second.first;
}

void print(vector<pair<string, pair<int, int>>> table)
{
    cout << "Team Name - Points" << endl;
    for (int i = 0; i < 8; i++)
    {
        cout << i + 1 << " " << table[i].first << "-------" << table[i].second.first << endl;
    }
    cout << "\n\n";
}

string bin(unsigned n)
{
    unsigned i;
    string res = "";
    for (i = 1 << 6; i > 0; i = i / 2)
        (n & i) ? res += '1' : res += '0';

    return res;
}

int main()
{
    int n = 8;

    while (n--)
    {
        string team;
        cin >> team;
        int points;
        cin >> points;
        int rank;
        cin >> rank;
        table.push_back(make_pair(team, make_pair(points, rank)));
    }

    vector<pair<string, string>> m;
    int matches = 0;
    while (1)
    {
        string team1, team2;
        cout << "Enter the teams playing:" cout << "Team1!:";
        cin >> team1;
        cout << "Team2!:";
        cin >> team2;
        m.push_back(make_pair(a, b));
        matches++;
    }

    int thop = 0;
    for (thop; thop < 128; thop++)
    {
        vector<pair<string, pair<int, int>>> vtable;
        vtable = table;
        string s = bin(thop);
        for (int i = 0; i < matches; i++)
        {

            if (s[i] == '0')
            {
                for (int e = 0; e < 8; e++)
                {
                    if (vtable[e].first == m[i].first)
                    {
                        vtable[e].second.first += 2;
                        break;
                    }
                }
            }
            else
            {
                for (int e = 0; e < 8; e++)
                {
                    if (vtable[e].first == m[i].second)
                    {
                        vtable[e].second.first += 2;
                        break;
                    }
                }
            }
        }

        sort(vtable.begin(), vtable.end(), comp);
        cout << thop << endl;
        print(vtable);
    }
}