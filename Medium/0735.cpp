class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        stack<int> s;   //right
        vector<int> result;
        vector<int> tail;
        for(int i=0;i<ast.size();++i){
            bool live = true;
            if(ast[i]<0){   // left
                while(s.size()){
                    if( 0-ast[i] > s.top()){
                        s.pop();
                    }else if(ast[i] == 0 - s.top()){
                        s.pop();
                        live = false;
                        break;
                    }else{
                        live = false;
                        break;
                    }
                }
                if(live){   //now stack is empty
                    result.push_back(ast[i]);
                }
            }else{  //right
                s.push(ast[i]);
            }
        }
        while(s.size()){
            tail.push_back(s.top());
            s.pop();
        }
        for(int i=tail.size()-1;i>=0;i--){
            result.push_back(tail[i]);
        }
        return result;
    }
};
