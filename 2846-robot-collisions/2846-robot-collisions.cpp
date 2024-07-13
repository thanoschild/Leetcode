class Robot {
public:
    int position;
    int health;
    char direction;
    int index;

    Robot(int pos, int h, char dir, int idx) {
        position = pos;
        health = h;
        direction = dir;
        index = idx;
    }
};

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<Robot> robots;
        for(int i = 0; i<n; i++) {
            Robot curr = Robot(positions[i], healths[i], directions[i], i);
            robots.push_back(curr);
        }

        sort(robots.begin(), robots.end(), [](const Robot &a, const Robot &b) {
            return a.position < b.position;
        });

        vector<Robot> stack;
        for(auto robot : robots) {
            if(robot.direction == 'R') {
                stack.push_back(robot);
                continue;
            }

            bool flag = false;
            while(!stack.empty() && stack.back().health <= robot.health && stack.back().direction == 'R') {
                if(stack.back().health == robot.health) {
                    stack.pop_back();
                    flag = true;
                    break;
                }
                robot.health--;
                stack.pop_back();
            }

            if(!flag && !stack.empty() && stack.back().direction == 'R' && stack.back().health > robot.health) {
                stack.back().health--;
                flag = true;
            }

            if(!flag) stack.push_back(robot);
        }

        sort(stack.begin(), stack.end(), [](const Robot &a, const Robot &b) {
            return a.index < b.index;
        });

        vector<int> ans;
        for(auto robot : stack) {
            ans.push_back(robot.health);
        }

        return ans;
    }
};