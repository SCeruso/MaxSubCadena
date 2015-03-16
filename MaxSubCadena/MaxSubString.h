#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;
class MaxSubString
{
private:
	string s_;
	string t_;
	vector<vector<int>> table_;
public:
	MaxSubString(string, string);
	string findMaxSubString();
	~MaxSubString();
};

