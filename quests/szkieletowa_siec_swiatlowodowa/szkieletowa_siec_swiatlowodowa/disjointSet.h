#ifndef DISJOIN_SET_H
#define DISJOIN_SET_H

#include <unordered_map> //parent
#include <vector>

class DisjointSet {
	std::unordered_map<unsigned long, unsigned long> parent;
public:
	//void makeSet(const std::vector<unsigned long> &arr) { for (const auto &i : arr) if (parent.find(i) == parent.end()) parent[i] = i; }
	void makeSet(std::vector<unsigned long> &&arr) { for (const auto &i : arr) if (parent.find(i) == parent.end()) parent[std::move(i)] = i; }
	unsigned long Find(unsigned long edge)const { return (parent.at(edge) == edge) ? edge : Find(parent.at(edge)); }
	void Union(unsigned long e1, unsigned long e2) { parent[Find(e1)] = Find(e2); }
};

#endif // !DISJOIN_SET_H
