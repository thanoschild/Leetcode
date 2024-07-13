/**
 * @param {number[]} positions
 * @param {number[]} healths
 * @param {string} directions
 * @return {number[]}
 */
class Robot {
    constructor(pos, health, direction, index) {
        this.position = pos;
        this.health = health;
        this.direction = direction;
        this.index = index;
    }
}

var survivedRobotsHealths = function(positions, healths, directions) {
    let n = positions.length;
    let robots = [];
    for (let i = 0; i < n; i++) {
        let curr = new Robot(positions[i], healths[i], directions[i], i);
        robots.push(curr);
    }

    robots.sort((a, b) => a.position - b.position);

    let stack = [];
    for (let robot of robots) {
        if (robot.direction === 'R') {
            stack.push(robot);
            continue;
        }

        let flag = false;
        while (stack.length > 0 && stack[stack.length - 1].health <= robot.health && stack[stack.length - 1].direction === 'R') {
            if (stack[stack.length - 1].health === robot.health) {
                stack.pop();
                flag = true;
                break;
            }
            robot.health--;
            stack.pop();
        }

        if (!flag && stack.length > 0 && stack[stack.length - 1].direction === 'R' && stack[stack.length - 1].health > robot.health) {
            stack[stack.length - 1].health--;
            flag = true;
        }

        if (!flag) stack.push(robot);
    }

    stack.sort((a, b) => a.index - b.index);

    let ans = stack.map(robot => robot.health);
    return ans;
};