#include <fstream>
#include <iostream>
#include "parser.h"

using namespace std;

vector<vector<vector<int>>> parse_preference_lists(string fileName)
{
    int n = 0;
    string s;
    ifstream Input(fileName);
    
    getline(Input, s);

    n = stoi(s);

    vector<vector<vector<int>>> wrapper;

    vector<vector<int>> hospitalPrefs;
    vector<vector<int>> studentPrefs;

    for(int i = 0; i < n; i++)
    {
        getline(Input, s);
        vector<int> current;
        for(int j = 0; j < n; j++)
        {
            current.push_back(s[2*j]-'0');
        }
        hospitalPrefs.push_back(current);
    }

    for(int i = 0; i < n; i++)
    {
        getline(Input, s);
        vector<int> current;
        for(int j = 0; j < n; j++)
        {
            current.push_back(s[2*j]-'0');
        }
        studentPrefs.push_back(current);
    }

    wrapper.push_back(hospitalPrefs);
    wrapper.push_back(studentPrefs);
    
    return wrapper;
}
