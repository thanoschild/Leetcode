class Node {
   public:
   int val; int row; int idx;
   Node(int val, int row, int idx) {
      this -> val = val;
      this -> row = row;
      this -> idx = idx;
   }
};

struct Compare {
    bool operator()(Node const& a, Node const& b) {
        return a.val > b.val; 
    }
};


class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<Node, vector<Node>, Compare> pq;

        int low = INT_MAX, high = INT_MIN, range = INT_MAX;
        int n = nums.size();
        vector<int> ans(2);

        for(int i = 0; i<n; i++) {
            int val = nums[i][0];
            high = max(val, high);
            pq.push(Node(val, i, 0));
        }

        while(!pq.empty()) {
            Node t = pq.top();
            int currVal = t.val, currRow = t.row, currIdx = t.idx;
            pq.pop();

            low = currVal;
            if(range > high - low) {
                range = high - low;
                ans[0] = low;
                ans[1] = high;
            }

            currIdx++;
            if(currIdx >= nums[currRow].size()) break;

            int newVal = nums[currRow][currIdx];
            high = max(high, newVal);
            pq.push(Node(newVal, currRow, currIdx));
        } 

        return ans;
    }
};