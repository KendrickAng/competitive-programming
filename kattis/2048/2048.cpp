#include <iostream>
#include <vector>

void rotate(int arr[4][4]) {
    int tmp[4][4]{};
    for (int r = 0; r < 4; r++) {
        for (int c = 0; c < 4; c++) {
            tmp[c][3-r] = arr[r][c];
        }
    }
    for (int r = 0; r < 4; r++) {
        for (int c = 0; c < 4; c++) {
            arr[r][c] = tmp[r][c];
        }
    }
}

void print(int arr[4][4]) {
    // print
    for (int r = 0; r < 4; r++) {
        for (int c = 0; c < 4; c++) {
            std::cout << arr[r][c];
            if (c != 3) std::cout << " ";
        }
        std::cout << std::endl;
    }
}

void solve(int arr[4][4]) {
    for (int r = 0; r < 4; r++) {
        int start = -1;
        int end = -1;
        // check from right to left; order matters
        for (int c = 3; c >= 0; c--) {
            if (arr[r][c] != 0) {
                if (start == -1) {
                    start = c;
                    continue;
                }
                else {
                    end = c;
                }
            } else {
                // skip 0s
                continue;
            }
            // calculate start-end
            int startval = arr[r][start];
            int endval = arr[r][end];
            if (startval == endval) {
                for (int c2 = end; c2 <= start; c2++) {
                    if (c2 == start)
                        arr[r][c2] = startval + endval;
                    else
                        arr[r][c2] = 0;
                }
                start = -1;
                end = -1;
            }
            else {
                for (int c2 = end; c2 <= start; c2++) {
                    arr[r][c2] = 0;
                }
                arr[r][start] = startval;
                arr[r][start-1] = endval;
                start = c;
                end = -1;
            }

        }
    }
    // slide everything to the right
    for (int r = 0; r < 4; r++) {
        std::vector<int> nums{};
        for (int c = 0; c < 4; c++) {
            if (arr[r][c] != 0) nums.push_back(arr[r][c]);
        }
        for (int i = 0; i < 4-nums.size(); i++) {
            arr[r][i] = 0;
        }
        int idx = 0;
        for (int i = 4-nums.size(); i < 4; i++) {
            arr[r][i] = nums[idx++];
        }
    }
}

int main() {
    int arr[4][4]{};
    for (int r = 0; r < 4; r++) {
        for (int c = 0; c < 4; c++) {
            int tmp; std::cin >> tmp;
            arr[r][c] = tmp;
        }
    }
    int LEFT = 0;
    int UP = 1;
    int RIGHT = 2;
    int DOWN = 3;
    int dir; std::cin >> dir;
    if (dir == LEFT) {
        rotate(arr); 
        rotate(arr);
        solve(arr);
        rotate(arr);
        rotate(arr);
        print(arr);
    }
    else if (dir == RIGHT) {
        solve(arr);
        print(arr);
    }
    else if (dir == UP) {
        rotate(arr);
        solve(arr);
        rotate(arr);
        rotate(arr);
        rotate(arr);
        print(arr);       
    }
    else if (dir == DOWN) {
        rotate(arr);
        rotate(arr);
        rotate(arr);
        solve(arr);
        rotate(arr);
        print(arr);
    }
}