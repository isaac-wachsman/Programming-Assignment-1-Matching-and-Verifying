#include "parser.h"
#include "matcher.h"
#include "random_input.h"
#include <iostream>
#include <string>
#include <vector>
#include <chrono>

using namespace std;

int main(int argc, char* argv[])
{
    //Read from input file if filePath is passed in command line
    if(argc > 1)
    {
        //Get Preference Lists from input file
        vector<vector<vector<int>>> input = parse_preference_lists(argv[1]);

        //Get Stable Matching
        vector<int> stable_matching = get_stable_matching(input[0].size(), input[0], input[1]);

        print_matching(stable_matching);
    }

    else
    {
        string s;
        cout << "Enter the number of hospitals/students you want to generate a random preference lists for: " << endl;
        cin >> s;
        int a = stoi(s);

        vector<vector<int>> pref1 = generate_random_preference_list(a);
        vector<vector<int>> pref2 = generate_random_preference_list(a);
        
        //auto start = std::chrono::steady_clock::now();

        vector<int> matching = get_stable_matching(a, pref1, pref2);

        //auto end = std::chrono::steady_clock::now();
        //auto diff = end - start;
        

        print_matching(matching);

        //std::cout << std::chrono::duration_cast<std::chrono::microseconds>(diff).count() << " microseconds" << std::endl;

    }
    
}
