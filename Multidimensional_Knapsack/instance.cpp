#include "instance.h"
#include <random>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

Instance::Instance(string instanceFile) {  
    read_input(instanceFile);
}

void Instance::read_input(const string& inputFile)
{
    ifstream instream(inputFile);
    if (!instream.is_open()) {
        cout << "Unable to open file \n";
        exit(0);
    }

    string line;
 
    // n, m, ans
    if (getline(instream, line)) {
        istringstream iss(line);
        vector<int> tokens;
        string token;
        while (iss >> token) {
            int tmp = stoi(token);
            //cout << tmp;
            tokens.push_back(tmp);
        }

        n = tokens[0];
        m = tokens[1];
        ans = tokens[2];

        //cout << n << " " << m << " " << ans << endl;
    }

    // profit
    if (getline(instream, line)) {
        istringstream iss(line);
        vector<int> tokens;
        string token;
        while (iss >> token) {
            int tmp = stoi(token);
            //cout << tmp;
            profit.push_back(tmp);
        }

        
        /*for (auto x : profit) {
            cout << x << " ";
        }
        cout << endl;*/
    }


    // resource_needed (A_ij)
    int load = m;
    while (load--)
    {
        if (getline(instream, line)) {
            istringstream iss(line);
            vector<int> tokens;
            string token;
            vector<int> needed;
            while (iss >> token) {
                int tmp = stoi(token);
                needed.push_back(tmp);
            }
            resource_need.push_back(needed);

            
        }
    }
    
    /*for (auto x : resource_need) {
        for (auto y : x) {
            cout << y << " ";
        }
        cout << endl;
    }*/

    // capacity
    if (getline(instream, line)) {
        istringstream iss(line);
        vector<int> tokens;
        string token;
        while (iss >> token) {
            int tmp = stoi(token);
            //cout << tmp;
            capacity.push_back(tmp);
        }


        /*for (auto x : capacity) {
            cout << x << " ";
        }
        cout << endl;*/
    }


}