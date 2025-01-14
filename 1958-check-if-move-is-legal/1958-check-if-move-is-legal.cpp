class Solution {
public:
    bool checkMove(vector<vector<char>>& board, int rMove, int cMove, char color) {
        vector<pair<int, int>> directions = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
        vector<pair<pair<int, int>, int>> move;
        int i = 0;
        for (auto [dx, dy] : directions) {
            int nx = rMove + dx;
            int ny = cMove + dy;
            while (nx >= 0 && ny >= 0 && nx < 8 && ny < 8 && board[nx][ny] != '.' && board[nx][ny] != color) {
                move.push_back({{nx, ny}, i});
                nx += dx;
                ny += dy;
            }
            i++;
        }
        for (auto [it, dir] : move) {
            int x = it.first;
            int y = it.second;
            while (x >= 0 && y >= 0 && x < 8 && y < 8) {
                x += directions[dir].first;
                y += directions[dir].second;
                if (x >= 0 && y >= 0 && x < 8 && y < 8 && board[x][y] == color) {
                    return true;
                }
                if (x >= 0 && y >= 0 && x < 8 && y < 8 && board[x][y] == '.') {
                    break;
                }
            }
        }
        return false;
    }
};
