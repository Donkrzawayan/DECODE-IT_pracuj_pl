//
#include <iostream>
#include "jawBreakerSolver.h"
#include <vector>

void fill_arr(std::vector<std::vector<unsigned>> &arr, size_t row_size, size_t column_size) {
	for (size_t i = 0; i < row_size; ++i) {
		arr[i].resize(column_size);
		for (size_t j = 0; j < column_size; ++j) {
			unsigned temp;
			std::cin >> temp;
			arr[i][j] = temp;
		}
	}
}

int main()
{
	size_t t;
	std::cin >> t;

	for (size_t i = 0; i < t; ++i) {
		size_t h, w;
		unsigned c;
		std::cin >> h >> w >> c;
		std::vector<std::vector<unsigned>> arr(h);
		fill_arr(arr, h, w);
		JawBreakerSolver jb_solver(std::move(arr));
		jb_solver.shootPoints();
	}
}
