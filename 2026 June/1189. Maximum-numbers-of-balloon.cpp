#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int freq[5];
        for (int i = 0; i < 5; i++) freq[i] = 0;
        for (char x : text){
            if (x == 'b') freq[0]++;
            if (x == 'a') freq[1]++;
            if (x == 'l') freq[2]++;
            if (x == 'o') freq[3]++;
            if (x == 'n') freq[4]++;
        }
        
        int cnt = INT_MAX;
        cnt = min(cnt, min(freq[0], min(freq[1], freq[4])));
        cnt = min(cnt, min(freq[2]/2, freq[3]/2));
        return cnt;
    }
};
