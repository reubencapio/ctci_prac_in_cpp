#include<iostream>
#include<vector>

bool isValidMove(int proposed_row, int proposed_col, std::vector<int>& solution)
{

	for (int i = 0; i < proposed_row; ++i) {
		int old_row = i;
		int old_col = solution[i];

		int diagonal_offset = proposed_row - old_row;
		if (old_col == proposed_col ||
			old_col == proposed_col - diagonal_offset ||
			old_col == proposed_col + diagonal_offset) {
			return false;

		}
	}
	return true;

}


void solveNQueens(int n, std::vector<int>& solution, int row, std::vector<std::vector<int>>& results)
{
	if (row == n) {
		results.push_back(solution);
		return;
	}

	for (int i = 0; i < n; ++i) {
		if (isValidMove(row, i, solution)) {
			solution[row] = i;
			solveNQueens(n, solution, row + 1, results);

		}
	}
}

void solveNQueensWrapper(int n, std::vector<std::vector<int>>& results)
{

	std::vector<int> solution(n);
	solveNQueens(n, solution, 0, results);
}


int main()
{
	int nxnBoard = 4;
	std::vector<std::vector<int>> results;
	solveNQueensWrapper(4, results);
	for (auto column: results) {
		for (auto row: column) {
			std::cout << row << " ";
		}
		std::cout << "\n";
	}
}
