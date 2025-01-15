class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int x = 0;
        int count1 = __builtin_popcount(num1);
        int count2 = __builtin_popcount(num2);
        if(count1 == count2){
            return num1;
        }
        
        if(count2 > count1){
           int diff = count2 - count1;
           x = num1;
           int idx = 0;
           while(diff > 0){
               int bit = 1 << idx;
               if((bit & num1) == 0){
                   x ^= bit;
                   diff--;
               }
               idx++;
           }
        }
        else{
            int diff = count1 - count2;
            x = num1;
            int idx = 0;
            while(diff > 0){
                int bit = 1 << idx;
                if((bit & num1) > 0){
                    x ^= bit;
                    diff--;
                }
                idx++;
            }
        }
        
        return x;
    }
};