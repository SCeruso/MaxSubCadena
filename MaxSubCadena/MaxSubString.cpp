#include "MaxSubString.h"


MaxSubString::MaxSubString(string s, string t) : s_(s), t_(t)
{
	table_.resize(s_.length() + 1);
	for (int i = 0; i < s_.length() + 1; i++)
		table_[i].resize(t.length() + 1, 0);
}


MaxSubString::~MaxSubString()
{
	for (int i = 0; i < table_.size(); i++)
		table_[i].clear();
	table_.clear();
}

string MaxSubString::findMaxSubString() {
	int i, j;
	stringstream result;
	stringstream fixedResult;
	int ady1, ady2, ady3;


	for (i = 1; i < table_.size(); i++) {
		for (j = 1; j < table_[i].size(); j++) {
			if (s_[i - 1] == t_[j - 1])
				table_[i][j] = 1 + table_[i - 1][j - 1];
			else {
				table_[i][j] = max(max(table_[i - 1][j - 1], table_[i][j - 1]), table_[i- 1][j]);
			}
		}
	}

	i = table_.size() - 1;
	j = table_[0].size() - 1;

	while (table_[i][j] != 0) {
		ady1 = table_[i - 1][j];
		ady2 = table_[i][j - 1];
		ady3 = table_[i - 1][j - 1];

		if (ady3 >= ady1 && ady3 >= ady2) {
			if (ady3 < table_[i][j])
				result << s_[i - 1];
			i--;
			j--;
		}
		else if (ady2 >= ady1 && ady2 >= ady3) {
			j--;
		}
		else if (ady1 >= ady2 && ady1 >= ady3) {
			i--;
		}
	}

	for (i = result.str().length() - 1; i >= 0; i--)
		fixedResult << result.str()[i];
	return fixedResult.str();
}