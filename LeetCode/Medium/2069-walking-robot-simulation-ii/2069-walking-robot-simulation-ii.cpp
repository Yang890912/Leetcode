class Robot {
public:
    vector<int> dx = {1, 0, -1, 0};
    vector<int> dy = {0, 1, 0, -1};
    int x, y;
    int m, n;
    int dir;

    Robot(int width, int height) {
        x = 0, y = 0;
        m = height;
        n = width;
        dir = 0;
    }
    
    void step(int num) {
        int perimeter = 2 * (m + n - 2);
        num %= perimeter;
        if (num == 0) num = perimeter;
        
        while (num--) {
            if (x + dx[dir] < 0 || x + dx[dir] >= n 
                || y + dy[dir] < 0 || y + dy[dir] >= m) {
                dir = (dir + 1) % 4;
            }
            x += dx[dir];
            y += dy[dir];
        }
    }
    
    vector<int> getPos() {
        return {x, y};
    }
    
    string getDir() {
        if (dir == 0) return "East";
        if (dir == 1) return "North";
        if (dir == 2) return "West";
        return "South";
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */