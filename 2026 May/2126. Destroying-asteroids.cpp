#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        long long a = mass;
        sort(asteroids.begin(), asteroids.end());
        for (int x : asteroids){
            if (a < x) return false;
            a += x;
        }
        return true;
    }
};
