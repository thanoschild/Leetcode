/**
 * @param {number[]} skill
 * @return {number}
 */
var dividePlayers = function(skill) {
    skill.sort((a, b) => a - b);
    const n = skill.length;
    const totalSkill = skill[0] + skill[n-1];
    let ans = 0;

    for(let i = 0; i<Math.floor(n/2); i++) {
        if(skill[i] + skill[n - i - 1] != totalSkill) return -1;
        ans += skill[i] * skill[n - i - 1];
    }

    return ans;
};