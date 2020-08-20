#ifndef NETWORK_MEMBER
#define NETWORK_MEMBER

#include <string>
#include <cstdint> //uint_fast8_t
#include <vector>

class NetworkMember
{
	std::string name;
	uint_fast8_t w;
	std::vector<NetworkMember *> friends;
public:
	NetworkMember(std::string &&name, uint_fast8_t w) : name(std::move(name)), w(w) {}
	void addFriend(NetworkMember *frnd) { friends.push_back(frnd); }
	friend bool operator==(const NetworkMember &nm, const std::string &name) { return nm.name == name; }
	const std::string &getName()const { return name; }
	uint_fast8_t getCost() { return w; }
	const std::vector<NetworkMember *> &getFriends() { return friends; }
};

#endif // !NETWORK_MEMBER
