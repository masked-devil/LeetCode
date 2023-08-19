/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        long unsigned int l=1;
        long unsigned int mid=(l+n)/2;
        long unsigned int j=n;
        while(l<n){
            if(guess(mid)==0) return mid;
            else if(guess(mid)==-1) j=mid-1;
            else l=mid+1;


            mid=(l+j)/2;


        }
        return mid;
        
    }
};