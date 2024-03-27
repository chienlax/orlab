#include "instance.h"
#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <map>
#include <string>
#include <vector>

using namespace std;

Instance::Instance(string instanceFile) {
    read_input(instanceFile);
}

void Instance::read_input(string inputFile)
{
    ifstream instream(inputFile);
    if (!instream.is_open()) {
        cout << "Unable to open file \n";
        exit(0);
    }
    int base_speed = 40;
    string line;

    //read num_drone
     if (getline(instream, line)) {
         stringstream ss(line);
         vector<string> all;
         string token;
         char delimiter = ',';
         while (getline(ss, token, delimiter)) {
             all.push_back(token);
         }
         num_drones = stoi(all[1]);
         //cout << num_drones;
     }

     //read speed_truck
     if (getline(instream, line)) {
         stringstream ss(line);
         vector<string> all;
         string token;
         char delimiter = ',';
         while (getline(ss, token, delimiter)) {
             all.push_back(token);
         }
         speed_truck = base_speed * stoi(all[1]);
         //cout << speed_truck;
     }

     //read speed_drone
     if (getline(instream, line)) {
         stringstream ss(line);
         vector<string> all;
         string token;
         char delimiter = ',';
         while (getline(ss, token, delimiter)) {
             all.push_back(token);
         }
         speed_drone = base_speed * stoi(all[1]);
         //cout << speed_drone;
     }

     //read nodes
     while (getline(instream, line)) {
         stringstream ss(line);
         vector<int> all;
         string token;
         while (ss >> token) {
             int temp = stoi(token);
             //cout << temp << " ";
             all.push_back(temp);
         }
         
         nodes.push_back(all);
     }

     num_nodes = nodes.size();

     /*for (int i = 0; i < nodes.size(); i++) {
         for (int j = 0; j<nodes[i].size(); j++) {
             cout << nodes[i][j] << " ";
         }
         cout << endl;
     }
     cout << endl;*/

     // calculate manhattan distance
     for (int i = 0; i < nodes.size(); i++) {
         vector<int> man_distance;
         for (int j = 0; j < nodes.size(); j++) {
             int x1 = nodes[i][1];
             int y1 = nodes[i][2];
             int x2 = nodes[j][1];
             int y2 = nodes[j][2];
             int man_dist = get_man_distance(x1, y1, x2, y2);
             man_distance.push_back(man_dist);
         }
         int x1 = nodes[0][1];
         int y1 = nodes[0][2];
         int x2 = nodes[i][1];
         int y2 = nodes[i][2];
         int man_dist = get_man_distance(x1, y1, x2, y2);
         man_distance.push_back(man_dist);

         distance_man.push_back(man_distance);
     }
     vector<int> vector_zero(num_nodes + 2, 0);
     distance_man.push_back(vector_zero);

     // calculate euclid distance
     for (int i = 0; i < nodes.size(); i++) {
         vector<int> euclid_distance;
         for (int j = 0; j < nodes.size(); j++) {
             int x1 = nodes[i][1];
             int y1 = nodes[i][2];
             int x2 = nodes[j][1];
             int y2 = nodes[j][2];
             int euclid_dist = get_euclid_distance(x1, y1, x2, y2);
             euclid_distance.push_back(euclid_dist);
         }
         int x1 = nodes[0][1];
         int y1 = nodes[0][2];
         int x2 = nodes[i][1];
         int y2 = nodes[i][2];
         int euclid_dist = get_euclid_distance(x1, y1, x2, y2);
         euclid_distance.push_back(euclid_dist);

         distance_eucl.push_back(euclid_distance);
     }
     distance_eucl.push_back(vector_zero);

     // calculate time truck (manhattan time)
     for (int i = 0; i < distance_man.size(); i++) {
         vector<int> time_each_node;
         for (int j = 0; j < distance_man[i].size(); j++) {
             int time = distance_man[i][j] / speed_truck;
             time_each_node.push_back(time);
         }
         time_truck.push_back(time_each_node);
     }

     // calculate time drone (euclid time)
     for (int i = 0; i < distance_eucl.size(); i++) {
         vector<int> time_each_node;
         for (int j = 0; j < distance_eucl[i].size(); j++) {
             int time = distance_eucl[i][j] / speed_drone;
             time_each_node.push_back(time);
         }
         time_drone.push_back(time_each_node);
     }

     //for (int i = 0; i < time_drone.size(); i++) {
     //    for (int j = 0; j < time_drone[i].size(); j++) {
     //        cout << time_drone[i][j] << " ";
     //        //continue;
     //    }
     //    cout << endl;
     //}

     //cout << endl;

     // confirm a customer is drone-eligible
     vector<int> can_use_drone;
     for (int i = 0; i < nodes.size(); i++) {
         if (nodes[i][3]) {
             can_use_drone.push_back(nodes[i][0]);
         }
     }

     for (int x : can_use_drone) {
         if (is_drone_eligible(time_drone[0][x])) {
             drone_only.insert(nodes[x][0]);
         }
     }

     /*for (auto x : drone_only) {
         cout << x << " ";
     }*/

     //cout << endl << num_nodes << endl;
}

int Instance::get_euclid_distance(int x1, int y1, int x2, int y2) {
    return int(sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

int Instance::get_man_distance(int x1, int y1, int x2, int y2) {
    return int((abs(x2 - x1) + abs(y2 - y1)));
}

bool Instance::is_drone_eligible(int a) {
    return a*2 <= 50; //total time do not exceed 40 mins
}