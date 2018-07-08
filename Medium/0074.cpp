class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int h = matrix.size();
        if(h==0) return false;
        int w = matrix[0].size();
        if(w==0) return false;
        int row = h-1;
        for(int i=0;i<h;i++){
            // cout << matrix[i][0] << endl;
            if(matrix[i][0]==target) return true;
            if(matrix[i][0]>target){
                row = i-1;
                break;
            }
        }
        cout << row << endl;
        if(row==-1) return false;
        int res = bisearch(matrix[row],0,w,target);
        if(res>=0) return true;
        return false;
    }
    
    int bisearch(vector<int>& vec,int l,int r,int target){
        if(l>r){
            return -1;
        }
        int m = (l+r)/2;
        if(vec[m]==target) return m;
        if(vec[m]<target) return bisearch(vec,m+1,r,target);
        return bisearch(vec,l,m-1,target);
    }
};
