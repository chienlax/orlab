#pragma once
#ifndef INSTANCE_H
#define INSTANCE_H

#include <vector>
#include <string>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <iostream>
using namespace std;

class Instance {
public:
	//string instanceName;

	int num_nodes; //done
	int num_drones; //done
	int speed_drone; //done
	int speed_truck; //done

	vector<vector<int>> nodes; //done
	set<int> drone_only; //done
	vector<vector<int>> distance_man; // round to nearest integer - done
	vector<vector<int>> distance_eucl; // round to nearest integer - done
	vector<vector<int>> time_truck; // round to nearest integer - done
	vector<vector<int>> time_drone; // round to nearest integer - done

	Instance(string instanceFile);
	int get_time_drone_flying(int a);
	int get_distance_drone_flying(int a);
	int get_time_truck(int a, int b);
	int get_distance_truck(int a, int b);
	bool is_drone_eligible(int a);

private:
	void read_input(string inputFile);
	int get_euclid_distance(int x1, int y1, int x2, int y2);
	int get_man_distance(int x1, int y1, int x2, int y2);
};


#endif