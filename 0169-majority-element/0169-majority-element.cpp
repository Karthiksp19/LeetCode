class Solution {
public:
    int majorityElement(vector<int>& arr) {
        int count = 0;
        int ele = arr[0];
        int n = arr.size();

        for (int i = 0; i < n; i++){
            if (count == 0){
                ele = arr[i];
                count = 1;
            }
            else if(ele != arr[i]){
                count--;
            }
            else{
                count++;
            }
        }

        return ele;
    }
};