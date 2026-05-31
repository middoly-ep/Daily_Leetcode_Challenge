#include <string>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    struct node{
        unordered_map<char, node*> next_char;
        int best_idx = INT_MAX;
    };

    int better_idx(int a, int b, vector<string> &wordsContainer){
        if (a == INT_MAX) return b;
        if (a == b) return a;
        if (wordsContainer[a].size() == wordsContainer[b].size()){
            if (a < b) return a;
            return b;
        }
        if (wordsContainer[a].size() < wordsContainer[b].size()) return a;
        return b;
    }

    void add_string(node* start, string s, int s_idx, vector<string> &wordsContainer){
        int idx = s.size() - 1;
        while (idx >= 0){
            if (start->next_char.count(s[idx]) == 0) start->next_char[s[idx]] = new node;
            start->best_idx = better_idx(start->best_idx, s_idx, wordsContainer);
            start = start->next_char[s[idx]];
            idx--;
        }
        start->best_idx = better_idx(start->best_idx, s_idx, wordsContainer);
    }

    int find_ans(vector<string> &wordsContainer, string s, node* start){
        int idx = s.size() - 1;
        while (idx >= 0){
            if (start->next_char.count(s[idx]) == 0) break;
            start = start->next_char[s[idx]];
            idx--;
        }
        return start->best_idx;
    }

    void clear_trie(node* start){
        if (start == nullptr) return;
        for (auto p : start->next_char) clear_trie(p.second);
        delete(start);
    }

    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        vector<int> res;
        node* start = new node;
        for (int i = 0; i < wordsContainer.size(); i++){
            add_string(start, wordsContainer[i], i, wordsContainer);
        }

        for (string s : wordsQuery){
            res.push_back(find_ans(wordsContainer, s, start));
        }
        clear_trie(start);
        return res;
    }
};
