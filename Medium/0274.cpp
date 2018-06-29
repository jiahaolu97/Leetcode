class Solution {
public:
    int hIndex(vector<int>& citations) {
        if(citations.size()==0) return 0;
        multimap<int,int> m;
        for(int i=0;i<citations.size();i++){
            m.insert(pair<int,int>(citations[i],i));
        }
        multimap<int,int>::reverse_iterator it = m.rbegin();
        int pos = 0;
        while(it!=m.rend()){
            pos++;
            int cite = it->first;
            cout << cite << endl;
            if(cite<pos) break;
            it++;
        }
        if(it == m.rend()) return pos;
        return pos-1;
    }
};
