class Solution {
public:
    string removeOccurrences(string s, string part) {
        int n = part.size();
        size_t pos;
        while((pos = s.find(part)) != string::npos) {
            s.erase(pos, n);
        }

        return s;
    }
};