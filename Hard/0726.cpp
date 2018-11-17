#include <string>
#include <iostream>
#include <map>
using namespace std;
class Solution {
public:
    string countOfAtoms(string formula) {
        map<string,int> m;
        count(formula,m);
        string res;
        for(pair<string,int> p : m){
            //cout << "Pair : " << p.first << " " << p.second << endl;
            res.append(p.first);
            if(p.second != 1) res.append(to_string(p.second));
        }
        return res;
    }
    void count(string formula,map<string,int> &m){   // take inside a ( )
        int ptr = 0;
        int num = 0;
        string name;
        int left = 0;
        bool hasPara = false;
        string x;
        while(ptr < formula.size()){
            //ptr++;
            if(formula[ptr] <= 'Z' && formula[ptr] >= 'A'){
                if(name.size()!=0){
                    if(m.count(name) == 0) m[name] = 1;
                    else m[name] ++;
                    name.clear();
                }
                name.push_back(formula[ptr]);
            }else if(formula[ptr] <= 'z' && formula[ptr] >= 'a'){
                name.push_back(formula[ptr]);
            }else if(formula[ptr] == '('){
                num = 0;
                left = 1;
                while(left != 0 || formula[ptr] != ')') {
                        ptr++;
                        x.push_back(formula[ptr]);
                        if(formula[ptr] == '(') left++;
                        else if(formula[ptr] == ')') left--;
                }
                x = x.substr(0,x.size()-1);
                //cout << "x :" << x << endl;
                map<string,int> mp;
                count(x,mp);
                x.clear();
                ptr++;
                while(ptr < formula.size() && formula[ptr] <= '9' && formula[ptr]>='0'){
                    hasPara = true;
                    num *= 10;
                    num += formula[ptr] - '0';
                    ptr ++;
                }
                ptr--;
                if(!hasPara) {
                    //cout << "number is 1 !" << endl;
                    num = 1;
                }
                for(pair<string,int> p : mp){
                    if(m.count(p.first) == 0) m[p.first] = num*(p.second);
                    else m[p.first] += num*(p.second);
                }
                hasPara = false;
                left = 0;
            }else{
                num = 0;
                while(ptr < formula.size() && formula[ptr] <= '9' && formula[ptr] >= '0'){
                    num *= 10;
                    num += (formula[ptr] - '0');
                    ptr++;
                }
                ptr--;
                if(m.count(name)) m[name] += num;
                else m[name] = num;
                name.clear();
            }
            ptr++;
        }
        if(name.size()){
            if(m.count(name) == 0) m[name] = 1;
            else m[name] ++;
        }
    }
};

