class Solution {
public:
    int takeCharacters(string s, int k) {
        int ca = 0, cb = 0, cc = 0, ans = -1;
        int n = s.size();
        for(int i = 0; i<s.size(); i++){
            if(s[i] == 'a') ca++;
            if(s[i] == 'b') cb++;
            if(s[i] == 'c') cc++;
        }
        
        if(ca < k || cb < k || cc < k) return -1;
        ca -= k; cb -= k; cc -= k;
        
        int cca = 0, ccb = 0, ccc = 0;
        int j = 0;
        
        for(int i = 0; i<n; i++){
            if(s[i] == 'a'){
               cca++; 
            }
            else if(s[i] == 'b'){
               ccb++; 
            }
            else{
               ccc++; 
            }
            
            while(cca > ca){
                if(s[j] == 'a'){
                    cca--;
                    j++;
                }
                else{
                    if(s[j] == 'b'){
                        ccb--;
                    }
                    else{
                        ccc--;
                    }
                    j++;
                }
            }
            
            while(ccb > cb){
                if(s[j] == 'b'){
                    ccb--;
                    j++;
                }
                else{
                    if(s[j] == 'a'){
                        cca--;
                    }
                    else{
                        ccc--;
                    }
                    j++;
                }
            }
            
            while(ccc > cc){
                if(s[j] == 'c'){
                    ccc--;
                    j++;
                }
                else{
                    if(s[j] == 'b'){
                        ccb--;
                    }
                    else{
                        cca--;
                    }
                    j++;
                }
            }
            
            ans = max(ans, i - j + 1);
        }
        
        return n - ans;
    }
};