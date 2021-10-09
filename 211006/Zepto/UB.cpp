// Unrobust Robot
// @author Zepto
// 09 Oct 2021

#include <bits/stdc++.h>
using namespace std;

const int maxn = 22;

int N, M, K;
int maze[maxn][maxn];
int next_x[4] = {1, -1, 0, 0};
int next_y[4] = {0, 0, 1, -1};

int find_next(int x, int y, int (&cur_maze)[maxn][maxn]){
    int res = -1, local_max = -1;
    for (int i = 0 ; i < 4 ; ++i){
        int pot_x = x + next_x[i];
        int pot_y = y + next_y[i];
        if (pot_x < 1 || pot_x > N) continue;
        if (pot_y < 1 || pot_y > M) continue;
        if (cur_maze[pot_x][pot_y] > local_max){
            local_max = cur_maze[pot_x][pot_y];
            res = i;
        }
        else if (cur_maze[pot_x][pot_y] == local_max){
            res = -1;
        }
    }
    return res;
}

void refresh(int (&cur_maze)[maxn][maxn]){
    for (int i = 1 ; i <= N ; ++i)
        for (int j = 1 ; j <= M ; ++j)
            cur_maze[i][j] = maze[i][j];
}

int initiate(int x, int y){
    int res = 0;
    int cur_maze[maxn][maxn];
    refresh(cur_maze);
    for (int i = 1 ; i <= K ; ++i){
        res += cur_maze[x][y];
        cur_maze[x][y] = 0;
        int direction = find_next(x, y, cur_maze);
        if (direction == -1) break;
        x += next_x[direction];
        y += next_y[direction];
    }
    return res;
}

int main(){
    scanf("%d%d%d", &N, &M, &K);
    for (int i = 1 ; i <= N ; ++i)
        for (int j = 1 ; j <= M ; ++j)
            scanf("%d", &maze[i][j]);
    
    int ans = 0;
    for (int i = 1 ; i <= N ; ++i)
        for (int j = 1 ; j <= M ; ++j)
            ans = max(ans, initiate(i, j));

    printf("%d\n", ans);
    return 0;
}