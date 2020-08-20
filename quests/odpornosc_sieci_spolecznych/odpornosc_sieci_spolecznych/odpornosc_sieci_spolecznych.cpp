//
#include <iostream>
#include <tuple>
#include "networkMember.h"
#include <algorithm>

void addFriends(std::vector<NetworkMember *> &connected, const std::vector<NetworkMember *> &toAdd) {
	for (const auto &i : toAdd)
		if (std::find(connected.begin(), connected.end(), i) == connected.end())
			connected.push_back(i);
}

void addFriends(std::vector<NetworkMember *> &connected, NetworkMember * toAdd) {
	if (std::find(connected.begin(), connected.end(), toAdd) == connected.end())
		connected.push_back(toAdd);
}

int main()
{
	unsigned n;
	std::cin >> n;
	std::vector<NetworkMember> members;
	members.reserve(n);
	for (unsigned i = 0; i < n; ++i) {
		std::string name;
		int w;
		std::cin >> name >> w;
		members.push_back(std::move(NetworkMember(std::move(name), w)));
	}

	unsigned m;
	std::cin >> m;
	for (unsigned i = 0; i < m; ++i) {
		std::string name1, name2;
		std::cin >> name1 >> name2;
		auto it1 = std::find(members.begin(), members.end(), name1);
		auto it2 = std::find(members.begin(), members.end(), name2);
		it1->addFriend(&(*it2));
		it2->addFriend(&(*it1));
	}

	std::vector<NetworkMember *> answer;
	unsigned int sum = static_cast<unsigned>(-1);

	for (unsigned i = 0; i < n; ++i) {
		std::vector<NetworkMember *> tempAnswer;
		unsigned int tempSum = 0;
		std::vector<NetworkMember *> connected;
		for (unsigned j = i; j < n; ++j) {
			tempAnswer.push_back(&(members[j]));
			tempSum += members[j].getCost();
			if (tempSum >= sum) {
				tempAnswer.clear();
				break;
			}
			addFriends(connected, &(members[j]));
			addFriends(connected, members[j].getFriends());
			if (members.size() == connected.size()) {
				answer = std::move(tempAnswer);
				sum = tempSum;
				break;
			}
		}
	}

	std::cout << answer.size() << "\n";
	for (auto i : answer)
		std::cout << (*i).getName() << "\n";
	std::cout << sum << "\n";
}

//132.87
