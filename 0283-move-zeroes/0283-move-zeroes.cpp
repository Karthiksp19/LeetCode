class Solution {
public:
    void moveZeroes(vector<int>& arr) {
        int n = arr.size();
        int i = 0, j;
        for ( i = 0; i < n; i++){
            if (arr[i] == 0){
                j  = i;
                break;
            }
        }

        for(i = j + 1; i < n; i++){
            if(arr[i] != 0){
                swap(arr[j++], arr[i]);
            }
        }
    }
};