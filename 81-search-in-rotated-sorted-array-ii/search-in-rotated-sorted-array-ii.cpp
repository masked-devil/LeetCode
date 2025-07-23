class Solution {
public:
    int getPivotIndex(vector<int>& nums){
        int n=nums.size()-1;
        int pivotIndex=n;
        int start=nums[0];

        int low=0;
        int high=n;

        while(low<=high){
            int mid=low+(high-low)/2;

            if(mid<n && nums[mid]>nums[mid+1]){
                pivotIndex=mid;
                break;
            }
            else if(nums[mid]<start){
                high=mid-1;
            }
            else if(nums[mid]>start){
                low=mid+1;
            }
            else if(low<=n && high>=0){
                if(nums[high]==nums[low]){
                    if(low<n && nums[low]>nums[low+1]){
                        pivotIndex=low;
                        break;
                    }
                    else if(high<n && nums[high]>nums[high+1]){
                        pivotIndex=high;
                        break;
                    }
                    high--;
                    low++;
                }
                else if(nums[low]==start){
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }
            }
        }
        return pivotIndex;
    }
    bool binarySearch(vector<int>& nums, int target, int low, int high){
        while(low<=high){
            int mid=low+(high-low)/2;

            if(nums[mid]==target){
                return true;
            }
            else if(nums[mid]<target){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
            
        }
        return false;
    }
    bool search(vector<int>& nums, int target) {
        bool  ans;

        int pivotIndex=getPivotIndex(nums);

        int low, high;

        if(target<nums[0]){
            low=pivotIndex+1;
            high=nums.size()-1;
        }
        else if(target>nums[0]){
            low=0;
            high=pivotIndex;
        }
        else{
            return true;
        }

        ans=binarySearch(nums,target,low, high);

        return ans;
        
    }
};