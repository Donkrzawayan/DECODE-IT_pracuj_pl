//
#include <iostream>
#include <vector>
#include <cstdint>
#include <string>

void processString() {
	unsigned n;
	std::cin >> n;
	std::cin.get(); //clear input
	std::vector<uint_fast8_t> str(4 * n);
	for (unsigned j = 0; j < 4 * n; ++j)
		str[j] = std::cin.get() - '0';
	std::cin.get(); //clear input

	std::string answer;
	for (unsigned j = 0; j < 4 * n; j += 4)
		answer += (str[j] * 10 + str[j + 2]) + (str[j + 1] * 10 + str[j + 3]);
	std::cout << answer << "\n";
}

int main()
{
	unsigned t;
	std::cin >> t;

	for (unsigned i = 0; i < t; ++i)
		processString();
}

// 100
