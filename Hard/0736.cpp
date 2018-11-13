class Solution {
    
public:
    int evaluate(string ex) {   
        map<string,int> m;
        return parse(ex.substr(1,ex.size()-2),m);
    }
    
    int parse(string ex,map<string,int>& upm){     //remove the ( and )   parse an order, whatever add/mult/let
        map<string,int> m = upm;
        //cout << ex << endl;
        int result;
        vector<string> arr = split(ex);
        string e1 = arr[1], e2 = arr[2];
        if(arr[0].compare("add") == 0){
            int v1,v2;
            if(e1[0] == '(') v1 = parse(e1.substr(1,e1.size()-2),m);
            else v1 = getValue(e1,m);
            if(e2[0] == '(') v2 = parse(e2.substr(1,e2.size()-2),m);
            else v2 = getValue(e2,m);
            result =  v1+v2;
        }else if(arr[0].compare("mult") == 0){
            int v1,v2;
            if(e1[0] == '(') v1 = parse(e1.substr(1,e1.size()-2),m);
            else v1 = getValue(e1,m);
            if(e2[0] == '(') v2 = parse(e2.substr(1,e2.size()-2),m);
            else v2 = getValue(e2,m);
            result = v1*v2;
        }else{  // let
            int len = arr.size();   // return the value of arr[len]
            string name;
            int value;
            for(int i=1;i<len-1;i++){ //pairs
                if(i%2) name = arr[i];
                else{
                    if(arr[i][0] == '(') value = parse(arr[i].substr(1,arr[i].size()-2),m);
                    else value = getValue(arr[i],m);
                    m[name] = value;
                }
            }
            if(arr[len-1][0] == '(') result = parse(arr[len-1].substr(1,arr[len-1].size()-2),m);
            else result = getValue(arr[len-1],m);
        }
        //printMap(m);
        //cout << "return " << result << endl;
        return result;
    }
    
    int getValue(string k,map<string,int>& m){   //get value from a number or a variable ; not scope
        int res = 0;
        if(k[0] == '-'){
            for(int i=1;i<k.size();i++){
                res *= 10;
                res += (k[i] - '0');
            }
            res = 0 - res;
        }else if(k[0] >= '0' && k[0] <= '9'){
            for(int i=0;i<k.size();i++){
                res *= 10;
                res += (k[i] - '0');
            }
        }else{  //variable
            res = m[k];
        }
        
        return res;
    }
    
private:
    vector<string> split(string src){
        vector<string> res;
        string token;
        int ptr = 0;
        int para = 0;
        while(ptr < src.size()){
            if(src[ptr] == '(') para++;
            else if(src[ptr] == ')') para--;
            if(src[ptr] == ' ' && !token.empty() && para == 0){
                res.push_back(token);
                token.clear();
            }else{
                token.push_back(src[ptr]);
            }
            ptr++;
        }
        if(token.size())
            res.push_back(token);
        return res;
    }
    
    void printMap(map<string,int> m){
        for(pair<string,int>p : m){
            cout << p.first << "," << p.second << endl;
        }
    }
};
