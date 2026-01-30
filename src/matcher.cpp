#include <iostream>
#include <vector>
#include <set>
#include "matcher.h"

using namespace std;


//Returns true if choice1 preceeds choice2 in preferences
bool pref_hospital(vector<int> &preferences, int choice1, int choice2)
{
    for(int i = 0; i < preferences.size(); i++)
    {
        if(preferences[i] == choice1)
        {
            return true;
        }
        
        if(preferences[i] == choice2)
        {
            return false;
        }
    }
    return false;
}


void print_matching(vector<int>& matching)
{
    for(int i = 0; i < matching.size(); i++)
    {
        cout << matching[i] << " " << i+1 << endl;
    }
}



vector<int> get_stable_matching(int n, vector<vector<int>> hospital_prefs, vector<vector<int>> student_prefs)
{
    //Vector keeps track of current matching - indices are students
    vector<int> matching(n, -1);

    //Vector keeps track of the most preferred applicant that hospital has yet to propose to
    vector<int> highest_proposal(n, 0);
    
    //Maintain a list of unmatched hospitals - initialized to 1-n
    set<int> unmatchedHospitals;
    for(int i = 1; i <= n; i++)
    {
        unmatchedHospitals.insert(i);
    }

    //While loop
    while(!unmatchedHospitals.empty())
    {
        //Get an unmatched hospital
        int h = *(unmatchedHospitals.begin());

        

        //Get the highest preferred applicant hospital has yet to propose to
        int a = hospital_prefs[h-1][highest_proposal[h-1]];

        
        //If applicant is free, match the hospital to applicant
        if(matching[a-1] == -1)
        {
            matching[a-1] = h;
            unmatchedHospitals.erase(h);

        }

        //If applicant prefers hospital to current, unmatch current, assign new, remove h from unmatched
        else if(pref_hospital(student_prefs[a-1], h, matching[a-1]))
        {
                unmatchedHospitals.insert(matching[a-1]);
                matching[a-1] = h;
                unmatchedHospitals.erase(h);
        }
        
        highest_proposal[h-1]++;
    }
    
    return matching;

}
