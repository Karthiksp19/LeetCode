class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int n = nums.size();
        long long l1 = LLONG_MIN, l2 = LLONG_MIN, l3 = LLONG_MIN;
        for (int i = 0; i < n; i++){
            int largest = nums[i];
            if(largest > l1){
                l3 = l2;
                l2 = l1;
                l1 = largest;
            }
            else if(largest > l2 && largest != l1){
                l3 = l2;
                l2 = largest;
            }
            else if(largest > l3 && largest != l2 && largest != l1){
                l3 = largest;
            }
        }

        return (l3 == LLONG_MIN ? l1 : l3);
    }
};