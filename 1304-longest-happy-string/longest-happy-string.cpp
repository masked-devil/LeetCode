class Info {
public:
    int freq;
    char c;

    Info(char a, int b) {
        c = a;
        freq = b;
    }
};

class Compare {
public:
    bool operator()(Info a, Info b) { return a.freq < b.freq; }
};
class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<Info, vector<Info>, Compare> pq;
        if (a)
            pq.push(Info('a', a));
        if (b)
            pq.push(Info('b', b));
        if (c)
            pq.push(Info('c', c));
        string ans = "";

        while (pq.size() > 1) {
            Info top1 = pq.top();
            pq.pop();
            Info top2 = pq.top();
            pq.pop();

            if(top1.freq > 1){
                ans.push_back(top1.c);
                ans.push_back(top1.c);

                top1.freq -=2;
            }
            else{
                ans.push_back(top1.c);

                top1.freq--;
            }

            if(top2.freq>1 && top2.freq >= top1.freq){
                ans.push_back(top2.c);
                ans.push_back(top2.c);

                top2.freq -=2;
            }
            else{
                ans.push_back(top2.c);

                top2.freq--;
            }

            if(top1.freq) pq.push(top1);
            if(top2.freq) pq.push(top2);
        }

        if (pq.size()) {
            Info top = pq.top();
            pq.pop();
            if(top.freq > 1){
                ans.push_back(top.c);
                ans.push_back(top.c);

                top.freq -=2;
            }
            else{
                ans.push_back(top.c);

                top.freq--;
            }
        }

        return ans;
    }
};