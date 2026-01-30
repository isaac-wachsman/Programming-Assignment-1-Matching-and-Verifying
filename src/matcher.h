#include <vector>

using namespace std;

bool pref_hospital(vector<int> &preferences, int choice1, int choice2);
void print_matching(vector<int>& matching);
vector<int> get_stable_matching(int n, vector<vector<int>> hospital_prefs, vector<vector<int>> student_prefs);
