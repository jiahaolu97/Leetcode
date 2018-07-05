class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res;
        for(int i=1;i<=n;i++){
            if(i%3 && i%5){
                string s(to_string(i));
                res.push_back(s);
            }else if(i%3){
                string s("Buzz");
                res.push_back(s);
            }else if(i%5){
                string s("Fizz");
                res.push_back(s);
            }else{
                string s("FizzBuzz");
                res.push_back(s);
            }
        }
        return res;
    }
};
