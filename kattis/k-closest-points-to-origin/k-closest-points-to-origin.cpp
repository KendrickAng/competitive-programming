#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        nth_element(points.begin(), points.begin()+k, points.end(), [](vector<int> &a, vector<int> &b) {
            int ax = a[0];
            int ay = a[1];
            double aa = sqrt(ax*ax + ay*ay);
            int bx = b[0];
            int by = b[1];
            double bb = sqrt(bx*bx + by*by);
            return aa < bb;
        });
        points.resize(k);
        return points;
    }
};