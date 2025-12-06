#include "day4.h"
#include "files.h"

static std::vector<std::vector<char>> parse_input(const char* filename) {
    std::vector<std::string> input = read_file(filename);

    std::vector<std::vector<char>> grid;

    for (size_t i = 0; i < input.size(); i++) {
	   std::vector<char> row; 
   
	   size_t c = 0;
	   while (input[i][c]) {
		  row.push_back(input[i][c]);
		  c++;
	   }
	   grid.push_back(row);
    }
    return grid;
}

static bool valid_index(std::vector<std::vector<char>> &grid, int r, int c) {
    return (r >= 0 && r < (int)grid.size() && c >= 0 && c < (int)grid[0].size());
}

static int count_neighbors(std::vector<std::vector<char>> &grid, int r, int c) {
    int count = 0;

    std::vector<std::pair<int, int>> neigh_idxs = 
    { {-1,-1}, {0,-1}, {1,-1}, 
      {-1, 0},         {1, 0},
      {-1, 1}, {0, 1}, {1, 1} };

    for (size_t n = 0; n < neigh_idxs.size(); n++) {
	   if (!valid_index(grid, r + neigh_idxs[n].first, c + neigh_idxs[n].second)) continue;
	   if (grid[r + neigh_idxs[n].first][c + neigh_idxs[n].second] == '@') count++;
    }

    return count;
}

static void print_grid(std::vector<std::vector<char>> &grid) {
    for (size_t r = 0; r < grid.size(); r++) {
	   for (size_t c = 0; c < grid[r].size(); c++) {
		  std::cout << grid[r][c];
	   }
	   std::cout << "\n";
    }
}

void solution_4_1(const char *filename) {
    std::vector<std::vector<char>> grid = parse_input(filename);
    int forkliftable = 0;

    for (size_t r = 0; r < grid.size(); r++) {
	   for (size_t c = 0; c < grid[r].size(); c++) {
		  if (grid[r][c] != '@') continue; 

		  int neighbors = count_neighbors(grid, r, c);

		  if (neighbors < 4) {
			 forkliftable++;
		  }
	   }
    }

    std::cout << "\n\nforkliftable papers are " << forkliftable << "\n"; 
}

static void remove_forks(std::vector<std::vector<char>> &grid, std::vector<std::pair<int, int>> &indices) {

    while (!indices.empty()) {
	   std::pair<int, int> coords = indices.back();
        grid[coords.first][coords.second] = 'x';
        indices.pop_back();
    }
}

static int count_forks(std::vector<std::vector<char>> &grid, std::vector<std::pair<int, int>> &indices) {
    int forkliftable = 0;
    for (size_t r = 0; r < grid.size(); r++) {
	   for (size_t c = 0; c < grid[r].size(); c++) {
		  if (grid[r][c] != '@') continue; 

		  int neighbors = count_neighbors(grid, r, c);

		  if (neighbors < 4) {
			 indices.push_back({r,c});
			 forkliftable++;
		  }
	   }
    }

    return forkliftable;
}

void solution_4_2(const char *filename) {
    std::vector<std::vector<char>> grid = parse_input(filename);
    int forkliftable = 0;
    std::vector<std::pair<int, int>> indices;

    forkliftable += count_forks(grid, indices);

    while (!indices.empty()) {
	   remove_forks(grid, indices);
	   forkliftable += count_forks(grid, indices);
    }

    std::cout << "\n\nforkliftable papers are " << forkliftable << "\n"; 
}
