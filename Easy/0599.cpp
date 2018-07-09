class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        map<string,int> m;
        for(int i=0;i<list1.size();i++){
            m[list1[i]] = -(i+1);
        }
        for(int i=0;i<list2.size();i++){
            if(m.count(list2[i])>0){
                m[list2[i]] = -m[list2[i]];
                m[list2[i]] += i;
            }
        }
        int min = 1e7;
        vector<string> result;
        map<string,int>::iterator it = m.begin();
        for(;it!=m.end();it++){
            string k = it->first;
            int v = it->second;
            if(v<0) continue;
            else{
                if(v==min){
                    result.push_back(k);
                }
                if(v<min){
                    min = v;
                    result.clear();
                    result.push_back(k);
                }

            }
        }
        return result;
    }
};
