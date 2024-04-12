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

    // n, T
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
        T = tokens[1];

        //cout << n << " " << T << endl;
    }

    if (getline(instream, line)) {
        istringstream iss(line);
        vector<int> tokens;
        string token;
        while (iss >> token) {
            int tmp = stoi(token);
            required_worker.push_back(tmp);
        }
        //for (auto x : required_worker) cout << x << " ";

    }

    if (getline(instream, line)) {
        istringstream iss(line);
        vector<int> tokens;
        string token;
        while (iss >> token) {
            int tmp = stoi(token);
            wage.push_back(tmp);
        }
    }

    for (int i = 0; i < T; i++) {
        if (getline(instream, line)) {
            istringstream iss(line);
            vector<int> tokens;
            string token;
            while (iss >> token) {
                int tmp = stoi(token);
                tokens.push_back(tmp);
            }
            covered.push_back(tokens);
        }
    }

}