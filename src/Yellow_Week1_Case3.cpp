//============================================================================
// Name        : Algorithmic_toolbox_Week1_Sum_of_two.cpp
// Author      : grec88
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <map>
#include <vector>
using namespace std;

enum class Lang {
	DE, FR, IT
};

struct Region {
	string std_name;
	string parent_std_name;
	map<Lang, string> names;
	int64_t population;
};

auto GetTuple(const Region &reg) {
	return tie(reg.std_name, reg.parent_std_name, reg.names, reg.population);
}

bool operator<(const Region &reg1, const Region &reg2) {
	return (GetTuple(reg1) < GetTuple(reg2));
}

int FindMaxRepetitionCount(const vector<Region> &regions) {
	if (regions.size() == 0) {
		return 0;
	}
	map<Region, int> counters;
	int res = 0;
	for (const auto& c : regions) {
	res = max(res, ++counters[c]);
	}
	if (res == 0) {
		return 1;
	}
	return res;
}

int main() {
	cout << FindMaxRepetitionCount( { { "Moscow", "Russia", { { Lang::DE,
			"Moskau" }, { Lang::FR, "Moscou" }, { Lang::IT, "Mosca" } }, 89 }, {
			"Russia", "Eurasia", { { Lang::DE, "Russland" }, { Lang::FR,
					"Russie" }, { Lang::IT, "Russia" } }, 89 }, { "Moscow",
			"Russia", { { Lang::DE, "Moskau" }, { Lang::FR, "Moscou" }, {
					Lang::IT, "Mosca" } }, 89 }, { "Moscow", "Russia",
			{ { Lang::DE, "Moskau" }, { Lang::FR, "Moscou" }, { Lang::IT,
					"Mosca" } }, 89 } }) << endl;

	cout
			<< FindMaxRepetitionCount( { { "Moscow", "Russia", { { Lang::DE,
					"Moskau" }, { Lang::FR, "Moscou" }, { Lang::IT, "Mosca" } },
					89 }, { "Russia", "Eurasia", { { Lang::DE, "Russland" }, {
					Lang::FR, "Russie" }, { Lang::IT, "Russia" } }, 89 }, {
					"Moscow", "Russia", { { Lang::DE, "Moskau" }, { Lang::FR,
							"Moscou deux" }, { Lang::IT, "Mosca" } }, 89 }, {
					"Moscow", "Toulouse", { { Lang::DE, "Moskau" }, { Lang::FR,
							"Moscou" }, { Lang::IT, "Mosca" } }, 89 }, {
					"Moscow", "Russia", { { Lang::DE, "Moskau" }, { Lang::FR,
							"Moscou" }, { Lang::IT, "Mosca" } }, 31 }, })
			<< endl;
	return 0;
}
