#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <utility>
#include <algorithm>

using namespace std;

struct Command {
    string cmd;
    int row;
    int col;
};

class Solution {
private:
    vector<vector<int>> maps = {
        {-1, -1},
        {-1, 0},
        {-1, 1},
        {0, -1},
        {0, 1},
        {1, -1},
        {1, 0},
        {1, 1},
        {0, 0}
    };
    // 计算一个基站增加的信号值
    int sumOfSingleStation(const vector<vector<int>>& matrix, const set<pair<int, int>>& stations)
    {
        // 对每一个基站，计算它所增加的信号值
        int res = 0;
        for (const auto& station : stations) {
            // 遍历它周围的点(排除自己)
            int row = station.first;
            int col = station.second;
            for (int i = 0; i < (maps.size() - 1); ++i) {
                int a = row + maps[i][0];
                int b = col + maps[i][1];
                auto p = make_pair(a, b);
                if (a < 0 || a >= matrix.size() || b < 0 || b >= matrix[0].size() || stations.count(p) == 1) {
                    continue;
                }
                res++;
            }
        }
        return res;
    }
public:
    int GetMatrixSum(int rows, int cols, const vector<pair<int, int>>& baseStations, const vector<Command>& cmds)
    {
        // 先初始化基站
        vector<vector<int>> matrix(rows, vector<int>(cols));
        for (const pair<int, int>& p : baseStations) {
            matrix[p.first][p.second] = -1;
        }
        set<pair<int, int>> newStations(baseStations.begin(), baseStations.end());
        for (const Command& c : cmds) {
            if (c.cmd == "add") {
                matrix[c.row][c.col] = -1;
                newStations.insert(make_pair(c.row, c.col));
            } else {
                // 注意删除其附近的基站
                for (int i = 0; i < maps.size(); ++i) {
                    int a = c.row + maps[i][0];
                    int b = c.col + maps[i][1];
                    if (a < 0 || a >= rows || b < 0 || b >= cols) {
                        continue;
                    }
                    auto dummyStation = make_pair(a, b);
                    if (newStations.count(dummyStation)) {
                        newStations.erase(dummyStation);
                        matrix[a][b] = 0;
                    }
                }
            }
        }
        return sumOfSingleStation(matrix, newStations);
    }
};

int main()
{
    cout << "hello" << endl;
    return 0;
}
