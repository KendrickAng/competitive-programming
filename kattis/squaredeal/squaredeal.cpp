#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

struct Rectangle {
    int h;
    int w;
};

// Assumes left-right combining
bool canCombine(Rectangle &a, bool isFlatA, Rectangle &b, bool isFlatB) {
    int aHori = a.h;
    int aVerti = a.w;
    int bHori = b.h;
    int bVerti = b.w;
    if (isFlatA) swap(aHori, aVerti);
    if (isFlatB) swap(bHori, bVerti);
    return aVerti == bVerti;
}

// Assumes left-right combining
Rectangle combine(Rectangle &a, bool isFlatA, Rectangle &b, bool isFlatB) {
    int aHori = a.h;
    int aVerti = a.w;
    int bHori = b.h;
    int bVerti = b.w;
    if (isFlatA) swap(aHori, aVerti);
    if (isFlatB) swap(bHori, bVerti);
    if (aVerti > aHori+bHori) {
        return {aVerti, aHori+bHori};
    }
    return {aHori+bHori, aVerti};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    vector<Rectangle> rects;
    for (int i = 0; i < 3; i++) {
        int h, w; cin >> h >> w;
        rects.push_back({h,w});
    }

    vector<tuple<int,int,int>> rectOrders;
    rectOrders.push_back(make_tuple(0,1,2));
    rectOrders.push_back(make_tuple(0,2,1));
    rectOrders.push_back(make_tuple(1,0,2));
    rectOrders.push_back(make_tuple(1,2,0));
    rectOrders.push_back(make_tuple(2,0,1));
    rectOrders.push_back(make_tuple(2,1,0));

    vector<tuple<int,int,int>> rectOrientations;
    rectOrientations.push_back(make_tuple(0,0,0));
    rectOrientations.push_back(make_tuple(0,0,1));
    rectOrientations.push_back(make_tuple(0,1,0));
    rectOrientations.push_back(make_tuple(0,1,1));
    rectOrientations.push_back(make_tuple(1,0,0));
    rectOrientations.push_back(make_tuple(1,0,1));
    rectOrientations.push_back(make_tuple(1,1,0));
    rectOrientations.push_back(make_tuple(1,1,1));

    bool canSquare = false;
    for (auto &[a,b,c]: rectOrders) {
        // try all orientations
        for (auto &[isFlatA, isFlatB, isFlatC]: rectOrientations) {
            // try to combine first two
            if (!canCombine(rects[a], isFlatA, rects[b], isFlatB)) {
                continue;
            }
            Rectangle d = combine(rects[a], isFlatA, rects[b], isFlatB);

            if (canCombine(d, true, rects[c], isFlatC)) {
                Rectangle e = combine(d, true, rects[c], isFlatC);
                if (e.h == e.w) {
                    canSquare = true;
                    goto end;
                }
            }
            if (canCombine(d, false, rects[c], isFlatC)) {
                Rectangle e = combine(d, false, rects[c], isFlatC);
                if (e.h == e.w) {
                    canSquare = true;
                    goto end;
                }
            }
        }
    }

    end:
    if (canSquare) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}