#ifndef JAW_BREAKER_SOLVER
#define JAW_BREAKER_SOLVER

#include <vector>
#include <random>
#include <chrono>

class JawBreakerSolver
{
private:
	static constexpr unsigned int EMPTY = static_cast<unsigned int>(-1);
	static constexpr unsigned int OUT_OF_INDEX = static_cast<unsigned int>(-1);
	static constexpr unsigned int TO_MOVE_DOWN = 21U; //first safe number
	static constexpr unsigned int MAX_ATTEMPTS = 5U;
	std::vector<std::vector<unsigned int>> m_arr;
	const size_t MAX_X, MAX_Y;
	std::mt19937 generator;

public:
	JawBreakerSolver(std::vector<std::vector<unsigned int>> &&arr)
		: m_arr(std::move(arr)), MAX_X(m_arr.size()), MAX_Y(m_arr[0].size()),
		generator(std::chrono::system_clock::now().time_since_epoch().count()) {}

	void shootPoints();
private:
	bool inspectPoint(unsigned x, unsigned y);
	bool searchNeighborhood(unsigned x, unsigned y, unsigned point);
	void searchForMoveDown();
	void slideDown(size_t last_row, size_t column);

	void searchEntire();
};

#endif