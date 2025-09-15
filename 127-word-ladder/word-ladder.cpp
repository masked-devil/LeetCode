class Solution {
public:

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> dict(wordList.begin(), wordList.end());
    if (!dict.count(endWord)) return 0;

    unordered_set<string> beginSet{beginWord}, endSet{endWord};
    unordered_set<string> visited;

    int level = 1;
    int L = beginWord.size();

    while (!beginSet.empty() && !endSet.empty()) {
        
        if (beginSet.size() > endSet.size())
            swap(beginSet, endSet);

        unordered_set<string> nextSet;

        for (const string& word : beginSet) {
            string curr = word;
            for (int i = 0; i < L; ++i) {
                char orig = curr[i];
                for (char c = 'a'; c <= 'z'; ++c) {
                    if (c == orig) continue;
                    curr[i] = c;

                    if (endSet.count(curr)) return level + 1;

                    if (dict.count(curr) && !visited.count(curr)) {
                        visited.insert(curr);
                        nextSet.insert(curr);
                    }
                }
                curr[i] = orig;
            }
        }

        beginSet.swap(nextSet);
        ++level;
    }

    return 0;
}

};