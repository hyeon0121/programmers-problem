#include <vector>

using namespace std;

bool gi[101][101] = {};
bool bo[101][101] = {};

bool check_gi(int x, int y, int n) {
    if (y == 0) return 1;
    if (gi[x][y - 1]) return 1;
    if (x > 0 && bo[x - 1][y]) return 1;
    if (x < n && bo[x][y]) return 1;

    return 0;
}

bool check_bo(int x, int y, int n) {
    if (gi[x][y - 1]) return 1;
    if (x < n && gi[x + 1][y - 1]) return 1;
    if (x > 0 && x < n && bo[x + 1][y] && bo[x - 1][y]) return 1;

    return 0;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;

    for (int i = 0; i < build_frame.size(); i++) {
        int x, y, a, b;
        x = build_frame[i][0];
        y = build_frame[i][1];
        a = build_frame[i][2];
        b = build_frame[i][3];

        // 기둥 설치
        if (a == 0 && b == 1) {
            if (check_gi(x, y, n)) {
                gi[x][y] = 1;
            }
        }
        // 보 설치
        else if (a == 1 && b == 1) {
            if (check_bo(x, y, n)) {
                bo[x][y] = 1;
            }
        }
        // 기둥 삭제
        else if (a == 0 && b == 0) {
            bool can = 1;
            gi[x][y] = 0;

            if (y < n && gi[x][y + 1] && !check_gi(x, y + 1, n)) can = 0;
            else if (y < n && bo[x][y + 1] && !check_bo(x, y + 1, n)) can = 0;
            else if (x > 0 && bo[x - 1][y + 1] && y < n && !check_bo(x - 1, y + 1, n)) can = 0;

            if (!can) gi[x][y] = 1;
        }
        // 보 삭제
        else if (a == 1 && b == 0) {
            bool can = 1;
            bo[x][y] = 0;

            if (gi[x][y] && !check_gi(x, y, n)) can = 0;
            else if (x < n && gi[x + 1][y] && !check_gi(x + 1, y, n)) can = 0;
            else if (x > 0 && bo[x - 1][y] && !check_bo(x - 1, y, n)) can = 0;
            else if (x < n && bo[x + 1][y] && !check_bo(x + 1, y, n)) can = 0;

            if (!can) bo[x][y] = 1;
        }
    }

    // answer에 기둥과 보 상태 넣기
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            if (gi[i][j]) {
                answer.push_back({ i, j, 0 });
            }
            if (bo[i][j]) {
                answer.push_back({ i, j, 1 });
            }
        }
    }

    return answer;
}