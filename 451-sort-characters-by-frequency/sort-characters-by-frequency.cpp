class Comp {
public:
    bool operator()(pair<char, int> a, pair<char, int> b) {
        return a.second < b.second;
    }
};

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        priority_queue<pair<char, int>, vector<pair<char,int>>, Comp> pq;
        string ans;

        for (auto c : s) {
            freq[c]++;
        }

        for (auto x:freq){
            pq.push(x);
        }

        while(!pq.empty()){
            auto front = pq.top();
            pq.pop();

            string str(front.second,front.first);
            ans+=str;
        }
        return ans;
    }
};