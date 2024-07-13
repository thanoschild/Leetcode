class Robot {
    int position;
    int health;
    char direction;
    int index;

    Robot(int position, int health, char direction, int index) {
        this.position = position;
        this.health = health;
        this.direction = direction;
        this.index = index;
    }
}

class Solution {
    public List<Integer> survivedRobotsHealths(int[] positions, int[] healths, String directions) {
        int n = positions.length;
        List<Robot> robots = new ArrayList<>();
        for(int i = 0; i<n; i++) {
            robots.add(new Robot(positions[i], healths[i], directions.charAt(i), i));
        }

        Collections.sort(robots, new Comparator<Robot>() {
            @Override
            public int compare(Robot a, Robot b) {
                return Integer.compare(a.position, b.position);
            }
        });

        List<Robot> stack = new ArrayList<>();
        for(Robot robot : robots) {
            if(robot.direction == 'R') {
                stack.add(robot);
                continue;
            }

            boolean flag = false;
            while(!stack.isEmpty() && stack.get(stack.size()-1).direction == 'R' && stack.get(stack.size()-1).health <= robot.health) {
                if(stack.get(stack.size()-1).health == robot.health) {
                    stack.remove(stack.size() - 1);
                    flag = true;
                    break;
                }
                robot.health--;
                stack.remove(stack.size() - 1);
            }

            if(flag == false && !stack.isEmpty() && stack.get(stack.size()-1).direction == 'R' && stack.get(stack.size()-1).health > robot.health) {
                stack.get(stack.size()-1).health--;
                flag = true;
            }

            if(flag == false) {
                stack.add(robot);
            }
        }

        Collections.sort(stack, new Comparator<Robot>(){
            @Override
            public int compare(Robot a, Robot b) {
                return Integer.compare(a.index, b.index);
            }
        });

        List<Integer> ans = new ArrayList<>();
        for(Robot robot : stack) {
            ans.add(robot.health);
        }

        return ans;
    }
}