class Info {
public:
    char c;
    int freq;

    Info(char c, int freq) {
        this->c = c;
        this->freq = freq;
    }
};

class Compare {
public:
    bool operator()(Info a, Info b) { return a.freq < b.freq; }
};

class Solution {
public:
    string reorganizeString(string s) {
        priority_queue<Info, vector<Info>, Compare> maxHeap;
        unordered_map<char, int> mp;
        string ans = "";
        for (auto x : s) {
            mp[x]++;
            // if (mp[x] > (s.length() + 1) / 2) {
            //     return "";
            // }
        }


        for (auto x : mp) {
            Info temp(x.first, x.second);
            maxHeap.push(temp);
        }

        while (maxHeap.size()>1) {
            Info top1 = maxHeap.top();
            maxHeap.pop();
            Info top2 = maxHeap.top();
            maxHeap.pop();
            
            ans.push_back(top1.c);
            ans.push_back(top2.c);

            top1.freq--;
            top2.freq--;

            if(top1.freq > 0){
                maxHeap.push(top1);
            }
            if(top2.freq > 0){
                maxHeap.push(top2);
            }
        }

        if (maxHeap.size()) {
            Info maxi = maxHeap.top();
            if(maxi.freq > 1){
                return "";
            }
            ans.push_back(maxi.c);
        }

        return ans;
    }
};