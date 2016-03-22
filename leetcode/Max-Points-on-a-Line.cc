/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
private:
    static double calcSlope(const Point& p1, const Point& p2) {
        // point in the same position, slope => -infinity
        // this is very important.
        if (p1.x == p2.x && p1.y == p2.y) return -numeric_limits<double>::infinity();
        if (p1.y == p2.y) return 0;
        if (p1.x == p2.x) return numeric_limits<double>::infinity();
        return (p1.y - p2.y) * 1.0 / (p1.x - p2.x);
    }
    static bool lessPoint(const Point& p1, const Point& p2) {
        if (p1.y < p2.y ||
                (p1.y == p2.y && p1.x < p2.x))
            return true;
        return false;
    }

public:
    int maxPoints(vector<Point>& points) {
        if (points.empty()) return 0;
        
        using namespace std::placeholders;
        sort(points.begin(), points.end(), lessPoint);

        int n = points.size();
        int maxNum = 1;
        for (int i = 1; i < n; i++) {

            vector<double> slopes(n-i, 0);
            transform(points.begin()+i, points.end(), slopes.begin(), bind(calcSlope, points[i-1], _1));
            sort(slopes.begin(), slopes.end());
            
            int base = 1;
            int j = 0;
            // handle points in the same position.
            for (; j < slopes.size(); j++) {
                if (slopes[j] == -numeric_limits<double>::infinity()) base++;
                else break;
            }
            int equalCount = base;
            for ( ; j < slopes.size(); j++) {
                if (slopes[j] == slopes[j-1]) 
                    equalCount++;
                else {
                    if (maxNum < equalCount) 
                        maxNum = equalCount;
                    equalCount = base+1;
                }
            }
            if (maxNum < equalCount) 
                maxNum = equalCount; 
        }
        return maxNum;
    }
};