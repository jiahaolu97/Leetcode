class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char min = 'z';
        char next = target;
        char cur;
        for(int i=0;i<letters.size();i++){
            cur = letters[i];
            if(min > cur)   min = cur;
            if(cur > target){
                if(next != target) next = (next <= cur? next: cur);
                else next = cur;
            } 
        }
        if(next == target) return min;
        return next;
    }
};
