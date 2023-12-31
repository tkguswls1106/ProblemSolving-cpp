// < 시간초과 FAIL 코드 >
// 예시에 대한 답은 맞게 나옴. 하지만 채점을 하면 틀리다고 뜸.

#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

int n,m;
vector<vector<int>> board;  // -1값이면 최종결정난 cctv가 바라본좌표임.

map<int, vector<pair<int,int>>> map1;

// 차례대로 하,우,상,좌
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

vector<pair<int,int>> dirGo(int x, int y, pair<int,int> dirCur) {
    vector<pair<int, int>> tempVisited;
    int nx = x, ny = y;
    while(true) {
        nx += dirCur.first;
        ny += dirCur.second;

        if(nx < 0 || nx >= n || ny < 0 || ny >= m) break;
        if(board[nx][ny] == 6) break;

        if(board[nx][ny] == 0) tempVisited.push_back({nx,ny});
    }

    return tempVisited; 
}

void visiting(vector<pair<int,int>> visited) {
    for(auto p : visited) {
        board[p.first][p.second] = -1;
    }
}

void cam1(pair<int,int> p) {
    vector<int> vSize;
    for(int i=0; i<4; i++) {
        vSize.push_back(dirGo(p.first, p.second, {dx[i],dy[i]}).size());
    }
    int max_index = max_element(vSize.begin(), vSize.end()) - vSize.begin();

    visiting(dirGo(p.first, p.second, {dx[max_index],dy[max_index]}));
}

void cam2(pair<int,int> p) {
    vector<pair<int,int>> up, down, left, right;  // 상,하,좌,우
    up = dirGo(p.first, p.second, {dx[2],dy[2]});
    down = dirGo(p.first, p.second, {dx[0],dy[0]});
    left = dirGo(p.first, p.second, {dx[3],dy[3]});
    right = dirGo(p.first, p.second, {dx[1],dy[1]});

    int ud, lr;  // 상하,좌우
    ud = up.size() + down.size();
    lr = left.size() + right.size();
    vector<int> vSize = {ud, lr};
    int max_index = max_element(vSize.begin(), vSize.end()) - vSize.begin();

    if(max_index == 0) {  // 만약 '상하'의 경우라면
        visiting(up);
        visiting(down);
    }
    else {  // 만약 '좌우'의 경우라면
        visiting(left);
        visiting(right);
    }
}

void cam3(pair<int,int> p) {
    vector<pair<int,int>> up, down, left, right;  // 상,하,좌,우
    up = dirGo(p.first, p.second, {dx[2],dy[2]});
    down = dirGo(p.first, p.second, {dx[0],dy[0]});
    left = dirGo(p.first, p.second, {dx[3],dy[3]});
    right = dirGo(p.first, p.second, {dx[1],dy[1]});

    int ul, ur, dl, dr;  // 상좌,상우,하좌,하우
    ul = up.size() + left.size();
    ur = up.size() + right.size();
    dl = down.size() + left.size();
    dr = down.size() + right.size();
    vector<int> vSize = {ul, ur, dl, dr};
    int max_index = max_element(vSize.begin(), vSize.end()) - vSize.begin();

    if(max_index == 0) {  // 만약 '상좌'의 경우라면
        visiting(up);
        visiting(left);
    }
    else if(max_index == 1) {  // 만약 '상우'의 경우라면
        visiting(up);
        visiting(right);
    }
    else if(max_index == 2) {  // 만약 '하좌'의 경우라면
        visiting(down);
        visiting(left);
    }
    else {  // 만약 '하우'의 경우라면
        visiting(down);
        visiting(right);
    }
}

void cam4(pair<int,int> p) {
    vector<pair<int,int>> up, down, left, right;  // 상,하,좌,우
    up = dirGo(p.first, p.second, {dx[2],dy[2]});
    down = dirGo(p.first, p.second, {dx[0],dy[0]});
    left = dirGo(p.first, p.second, {dx[3],dy[3]});
    right = dirGo(p.first, p.second, {dx[1],dy[1]});

    int u, d, l, r;  // 상빼고,하빼고,좌빼고,우빼고
    u = down.size() + left.size() + right.size();
    d = up.size() + left.size() + right.size();
    l = up.size() + down.size() + right.size();
    r = up.size() + down.size() + left.size();
    vector<int> vSize = {u, d, l, r};
    int max_index = max_element(vSize.begin(), vSize.end()) - vSize.begin();

    if(max_index == 0) {  // 만약 '상빼고'의 경우라면
        visiting(down);
        visiting(left);
        visiting(right);
    }
    else if(max_index == 1) {  // 만약 '하빼고'의 경우라면
        visiting(up);
        visiting(left);
        visiting(right);
    }
    else if(max_index == 2) {  // 만약 '좌빼고'의 경우라면
        visiting(up);
        visiting(down);
        visiting(right);
    }
    else {  // 만약 '우빼고'의 경우라면
        visiting(up);
        visiting(down);
        visiting(left);
    }
}

void cam5(pair<int,int> p) {
    for(int i=0; i<4; i++) {
        vector<pair<int,int>> visited(dirGo(p.first, p.second, {dx[i],dy[i]}));
        visiting(visited);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    board.resize(n, vector<int>(m));

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            int input;
            cin >> input;
            board[i][j] = input;

            if(1 <= input && input <= 5) {
                map1[input].push_back({i, j});
            }
        }
    }

    // 주변에 바로 6벽이 붙어있는 캠부터 우선순위를 높여 처리하기.
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(board[i][j] == 6) {
                for(int k=0; k<4; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if(!(1 <= board[nx][ny] && board[nx][ny] <= 5)) continue;

                    map1[6].push_back({nx,ny});
                    int num = board[nx][ny];
                    auto iter = find(map1[num].begin(), map1[num].end(), make_pair(nx,ny));
                    if (iter != map1[num].end()) {
                        map1[num].erase(iter);
                    }
                }
            }
        }
    }
    for(auto p : map1[6]) {
        int num = board[p.first][p.second];

        if(num == 1) cam1(p);
        else if(num == 2) cam2(p);
        else if(num == 3) cam3(p);
        else if(num == 4) cam4(p);
        else cam5(p);
    }

    // 방향이 가장 많고 이미 확정되어있기에 cam5부터 실시.
    for(auto p : map1[5]) cam5(p);

    // 그 다음으로 방향이 많은 cam4 실시.
    for(auto p : map1[4]) cam4(p);

    // 그 다음으로 방향이 많은 cam2와 cam3가 동일하지만, 방법의 수가 더 다양한 cam3부터 실시.
    for(auto p : map1[3]) cam3(p);

    // cam2 실시.
    for(auto p : map1[2]) cam2(p);

    // cam1 실시.
    for(auto p : map1[1]) cam1(p);

    int cnt = 0;
    for (auto row : board) {
        cnt += count(row.begin(), row.end(), 0);
    }
    cout << cnt;


    return 0;
}