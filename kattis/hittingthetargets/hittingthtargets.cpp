#include <iostream>
#include <string>
#include <cmath>
#include <vector>

class Target {
public:
    virtual bool contains(int x, int y) = 0;
};

class Circle: public Target {
private:
    int x, y, radius;
public:
    Circle(int x, int y, int radius) {
        this->x = x; // this keyword is the address of the object
        this->y = y;
        this->radius = radius;
    }
    bool contains(int xx, int yy) {
        int xOffset = abs(this->x - xx);
        int yOffset = abs(this->y - yy);
        double distFromCenter = sqrt(xOffset*xOffset + yOffset*yOffset);
        return distFromCenter <= radius;
    }
};

class Rectangle: public Target {
private:
    int x1, y1, x2, y2;
public:
    Rectangle(int x1, int y1, int x2, int y2) {
        if (!(x1 < x2 && y1 < y2)) {
            throw "Incorrect rectangle details";
        }
        this->x1 = x1;
        this->y1 = y1;
        this->x2 = x2;
        this->y2 = y2;
    }
    bool contains(int x, int y) {
        return x >= x1 && x <= x2 && y >= y1 && y <= y2;
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    int N;
    std::cin >> N;
    std::vector<Target*> targets(N);
    std::string type;
    for (int i = 0; i < N; i ++) {
        std::cin >> type;
        if (type == "rectangle") {
            int x1, y1, x2, y2;
            std::cin >> x1 >> y1 >> x2 >> y2;
            // Rectangle rect(x1, y1, x2, y2);
            // targets[i] = &rect;
            targets[i] = new Rectangle(x1, y1, x2, y2);
        } else if (type == "circle") {
            int x, y, r;
            std::cin >> x >> y >> r;
            // Circle circle(x, y, r);
            // targets[i] = &circle;
            targets[i] = new Circle(x, y, r);
        }
    }
    std::cin >> N;
    int x, y;
    for (int i = 0; i < N; i++) {
        int hit = 0;
        std::cin >> x >> y;
        for (int j = 0; j < targets.size(); j++) {
            if ((*targets[j]).contains(x, y)) {
                hit++;
                //std::cout << "Index: " << j << std::endl;
            }
        }
        std::cout << hit << std::endl;
    }
}
