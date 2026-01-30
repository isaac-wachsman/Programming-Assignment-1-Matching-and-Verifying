#include <vector>
#include <set>
#include <iostream>

using namespace std;

int get_index(int num, vector<int>& vec);
bool stable(int hospital, int student, vector<int>& matching, vector<vector<int>>& hospitalPrefs, vector<vector<int>>& studentPrefs);
bool verify(vector<int>& matching, vector<vector<int>>& hospitalPrefs, vector<vector<int>>& studentPrefs);