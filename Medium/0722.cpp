class Solution {
public:
    int locateLine(string src){
        int size = src.size();
        for(int i=0;i<size-1;i++){
            if(src[i] == '/' && src[i+1] == '/') return i;
        }
        return -1;
    }
    
    int locateLeft(string src){
        int size = src.size();
        for(int i=0;i<size-1;i++){
            if(src[i] == '/' && src[i+1] == '*') return i;
        }
        return -1;
    }
    
    int locateRight(string src){
        int size = src.size();
        for(int i=0;i<size;i++){
            if(src[i] == '*' && src[i+1] == '/') return i;
        }
        return -1;
    }
    string processLine(string line,bool& inblock){
        string res;
        int id, lid;
        if(inblock){
            id = locateRight(line);
            if(id == -1) return res;
            else{
                inblock = false;
                if(id+2 == line.size()) return res;
                line = line.substr(id+2,line.size()-id-2);
                return processLine(line,inblock);
            }
        }else{  // not in block , first check if it contains a /* , then // then */
            id = locateLeft(line);
            lid = locateLine(line);
            if(id != -1){   // found /* 
                if(lid == -1 || lid > id){  // not found // or // in the right
                    inblock = true;
                    string right =  processLine(line.substr(id+2,line.size()-id-2),inblock);
                    return line.substr(0,id).append(right);
                }else{  //find // and // in the left
                    res = line.substr(0,lid);
                }
            }else{
                if(lid != -1)
                    res = line.substr(0,lid);
                else{
                    res = line;
                }
            }
        }
        // cout << res << endl;
        return res;
    }
    
    vector<string> removeComments(vector<string>& source) {
        vector<string> res;
        string line;
        string batch;
        bool inblock = false;
        int id;
        for(int s=0;s<source.size();s++){
            line = source[s];
            line = processLine(line,inblock);
            if(inblock) batch.append(line);
            else{
                if(batch.size()){
                    batch.append(line);
                    res.push_back(batch);
                    batch.clear();
                }else{
                    if(line.size())  res.push_back(line);
                }
            }
        }
        return res;
    }
    
};
/*
    int main()
    { 
        // variable declaration  sfsddf  
        int a, b, c;
        / * This is a test
            multiline  
            comment for 
            testing * /
        a = b + c;
    }
*/



