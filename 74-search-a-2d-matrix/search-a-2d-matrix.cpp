class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size();
        int col=matrix[0].size();
        int low=0;
        int high=row*col-1;
        int mid= low+(high-low)/2;

        while(low<=high){
            int rowIndex=mid/col;
            int colIndex=mid%col;
            int currNumber=matrix[rowIndex][colIndex];

            if(currNumber==target){
                return true;
            }
            else if(currNumber<target){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
            mid=low+(high-low)/2;
        }
        return false;
        
    }
};