//
#include <iostream>
#include "disjointSet.h"
#include <tuple>
#include <stdexcept> //out_of_range
#include <algorithm> //find
#include <cstdint> //uint_fast8_t
#include <string>

void checkSameComponent(const DisjointSet &disjoint, unsigned long e1, unsigned long e2) {
	try {
		if (disjoint.Find(e1) == disjoint.Find(e2))
			std::cout << "T\n";
		else
			std::cout << "N\n";
	}
	catch (std::out_of_range) {
		std::cout << "N\n";
	}
}

unsigned long readIP() {
	uint_fast8_t a, b, c, d;
	scanf("%hhu.%hhu.%hhu.%hhu", &a, &b, &c, &d);
	return (unsigned long)(a * 16777216 + b * 65536 + c * 256 + d);
}

int main()
{
	std::vector<unsigned long> arr;
	std::vector<std::tuple<unsigned long, unsigned long>> unions;
	std::string operation;
	DisjointSet disjoint;
	while (std::cin >> operation) {
		unsigned long e1 = readIP();
		unsigned long e2 = readIP();
		
		if (operation == "B") {
			if (std::find(arr.begin(), arr.end(), e1) == arr.end())
				arr.push_back(e1);
			if (std::find(arr.begin(), arr.end(), e2) == arr.end())
				arr.push_back(e2);
			unions.push_back(std::make_tuple(std::move(e1), std::move(e2)));
		}
		else {
			
			disjoint.makeSet(std::move(arr));
			arr.clear();
			for (auto &i : unions)
				disjoint.Union(std::get<0>(i), std::get<1>(i));
			unions.clear();
			checkSameComponent(disjoint, e1, e2);
		}
	}
}

// 96
