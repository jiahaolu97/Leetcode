typedef pair<int,int> period;
class MyCalendar {
public:
    list<period> l;
    list<period>::iterator it;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        end --;
        for(it=l.begin();it!=l.end();it++){
            int ss = (*it).first;
            int ee = (*it).second;
            if(ss>=start && ss<= end) return false;
            if(ee>=start && ee<= end) return false;
            if(start>=ss && start<=ee) return false;
            if(end>=ss && end <= ee) return false;
        }
        period p;
        p.first = start;
        p.second = end;
        l.push_back(p);
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * bool param_1 = obj.book(start,end);
 */
