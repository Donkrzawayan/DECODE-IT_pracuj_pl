#include "jawBreakerSolver.h"
#include <iostream>

void JawBreakerSolver::shootPoints()
{
	std::cout << "Y\n";
	for (unsigned i = 0U; i < MAX_ATTEMPTS; ++i) {
		unsigned randomX = generator() % MAX_X;
		unsigned randomY = generator() % MAX_Y;
		bool isGroup = inspectPoint(randomX, randomY);
		if (isGroup)
			i = 0;
	}
	searchEntire();
	std::cout << "-1 -1\n";
}

bool JawBreakerSolver::inspectPoint(unsigned x, unsigned y)
{
	if (m_arr[x][y] != EMPTY) {
		bool isGroup = searchNeighborhood(x, y, m_arr[x][y]);
		if (isGroup) {
			std::cout << x << " " << y << "\n";
			searchForMoveDown();
			return true;
		}
	}
	return false;
}

bool JawBreakerSolver::searchNeighborhood(unsigned x, unsigned y, unsigned point)
{
	bool group = false;
	if (x - 1 != OUT_OF_INDEX && m_arr[x - 1][y] == point) {
		m_arr[x][y] = m_arr[x - 1][y] = TO_MOVE_DOWN;
		searchNeighborhood(x - 1, y, point);
		group = true;
	}
	if (x + 1 < MAX_X && m_arr[x + 1][y] == point) {
		m_arr[x][y] = m_arr[x + 1][y] = TO_MOVE_DOWN;
		searchNeighborhood(x + 1, y, point);
		group = true;
	}
	if (y - 1 != OUT_OF_INDEX && m_arr[x][y - 1] == point) {
		m_arr[x][y] = m_arr[x][y - 1] = TO_MOVE_DOWN;
		searchNeighborhood(x, y - 1, point);
		group = true;
	}
	if (y + 1 < MAX_Y && m_arr[x][y + 1] == point) {
		m_arr[x][y] = m_arr[x][y + 1] = TO_MOVE_DOWN;
		searchNeighborhood(x, y + 1, point);
		group = true;
	}

	return group;
}

void JawBreakerSolver::searchForMoveDown()
{
	for (size_t i = 0; i < MAX_Y; ++i) // clear top row
		if (m_arr[0][i] == TO_MOVE_DOWN)
			m_arr[0][i] = EMPTY;

	for(size_t i = 1; i< MAX_X; ++i)
		for (size_t j = 0; j<MAX_Y; ++j)
			if (m_arr[i][j] == TO_MOVE_DOWN) {
				if (m_arr[i - 1][j] == EMPTY)
					m_arr[i][j] = EMPTY;
				else
					slideDown(i, j);
			}
}

void JawBreakerSolver::slideDown(size_t last_row, size_t column)
{
	for (size_t i = last_row; i > 0; --i)
		m_arr[i][column] = m_arr[i - 1][column];
	m_arr[0][column] = EMPTY;
}

void JawBreakerSolver::searchEntire()
{
	int groupExist = 1;
	while (groupExist) {
		groupExist = 0;
		for (size_t i = 0; i < MAX_X; ++i)
			for (size_t j = 0; j < MAX_Y - 1; j += 2) {
				bool isGroup;
				if (i % 2)
					isGroup = inspectPoint(i, j);
				else
					isGroup = inspectPoint(i, j + 1);
				if (isGroup)
					++groupExist;
			}
	}
	groupExist = 1;
	while (groupExist) {
		groupExist = 0;
		if (MAX_Y % 2)
			for (size_t i = 1; i < MAX_X; i += 2) {
				bool isGroup = inspectPoint(i, MAX_Y - 1);
				if (isGroup)
					groupExist += 1;
			}
	}
}
