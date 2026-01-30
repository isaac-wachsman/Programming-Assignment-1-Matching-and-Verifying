#include "random_input.h"


vector<vector<int>> generate_random_preference_list(int n)
{
    vector<vector<int>> out;

    random_device rd;
    mt19937 g(rd());

    for(int i = 0; i < n; i++)
    {
        vector<int> list;
        for(int j = 1; j <=n; j++)
        {
            list.push_back(j);
        }
        shuffle(list.begin(), list.end(), g);
        out.push_back(list);
    }

    return out;
}