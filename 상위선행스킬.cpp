#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> tree[100002];
int child[100002];
bool visited[100002];

int n;
int total;

int dfs(int node) {
    if (tree[node].size() == 0) {
        child[node] = 1;
        total++;
        return 1;
    }

    for (int i = 0; i < tree[node].size(); ++i) {
        int next_node = tree[node][i];
        child[node] += dfs(next_node);
    }

    total += child[node];
    return child[node];
}
vector<int> solution(int total_sp, vector<vector<int>> skills) {
    n = skills.size()+1;
    total = 0;

    for (int i = 0; i < skills.size(); ++i) {
        tree[skills[i][0]].push_back(skills[i][1]);
        visited[skills[i][1]] = true;
    }

    int root;
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            root = i;
            break;
        }
    }

    dfs(root);

    int sp = total_sp / total;

    vector<int> ans;

    for (int i = 1; i <= n; ++i) {
        ans.push_back(child[i]*sp);
    }

    return ans;

}
int main() {
    vector<vector<int>> skills = {{1, 2}, {1, 3}, {3, 6}, {3, 4}, {3, 5}};
    vector<int> v = solution(121, skills);

    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << ' ';
    }
}