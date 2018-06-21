class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        if(hand.size()==0)  return false;
        if(W == 0) return false;
        if(hand.size()%W != 0) return false;
        map<int,int> m;
        for(int i=0;i<hand.size();i++){
            if(m.count(hand[i])){
                m[hand[i]]++;
            }else{
                m[hand[i]] = 1;
            }
        }
        while(m.size()){
            map<int,int>::iterator it = m.begin();
            int a = it->first;
            for(int i=1;i<W;i++){
                if(m.count(a+i)==0) return false;
            }
            for(int i=0;i<W;i++){
                if(--m[a+i]==0) m.erase(a+i);
            }
        }
        return true;
    }
};
