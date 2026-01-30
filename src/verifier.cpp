#include "verifier.h"

int get_index(int num, vector<int>& vec)
{
    int i = 0;
    while(i < vec.size())
    {
        if(vec[i] == num)
        {
            return i;
        }
        i++;
    }
    return -1;
}

bool stable(int hospital, int student, vector<int>& matching, vector<vector<int>>& hospitalPrefs, vector<vector<int>>& studentPrefs)
{
    vector<int> hospitalPrefList = hospitalPrefs[hospital-1];
    vector<int> studentPrefList = studentPrefs[student-1];

    int student_match = matching[student-1];

    int hospital_match = 0;
    while(hospital_match < matching.size())
    {
        if(matching[hospital_match] == hospital)
        {
            break;
        }
        hospital_match++;
    }
    hospital_match++;

    return !((get_index(student, hospitalPrefList) < get_index(hospital_match, hospitalPrefList)) && (get_index(hospital, studentPrefList) < get_index(student_match, studentPrefList)));
}

bool verify(vector<int>& matching, vector<vector<int>>& hospitalPrefs, vector<vector<int>>& studentPrefs)
{
    int n = matching.size();

    set<int> hospitals;

    //Check if matching is valid matching
    for(int i = 0; i < n; i++)
    {
        if(matching[i] < 1 || matching[i] > n)
        {
            cout << "INVALID - Hospital " << matching[i] << " is not a valid hospital." << endl;
            return false;
        }

        else if(hospitals.count(matching[i]) > 0)
        {
            cout << "INVALID - Hospital " << matching[i] << " matched to multiple students." << endl;
            return false;
        }

        else
        {
            hospitals.insert(matching[i]);
        }
    }


    //Check if matching is stable
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(!stable(i,j, matching, hospitalPrefs, studentPrefs))
            {
                cout << "UNSTABLE - Hospital " << i << " and Student " << j << " are an unstable pair." << endl;
                return false;
            }
        }
    }

    //Return true if all checks pass
    return true;

}
