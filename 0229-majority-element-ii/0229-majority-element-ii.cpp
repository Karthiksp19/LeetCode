class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int ele1 = nums[0];
        int ele2 = INT_MIN;
        int count1 = 1;
        int count2 = 0;

        int n = nums.size();

        for (int i = 1; i < n; i++){
            if (ele1 == nums[i]){
                count1++;
            }
            else if(count1 == 0 && nums[i] != ele2){
                ele1 = nums[i];
                count1 = 1;
            }
            else if(ele2 == nums[i]){
                count2++;
            }
            else if(count2 == 0 && nums[i] != ele1){
                ele2 = nums[i];
                count2 = 1;
            }
            else{
                count1--;
                count2--;
            }
        }

        count1 = 0;
        count2 = 0;
        for (int x : nums){
            if (ele1 == x) count1++;
            else if(ele2 == x) count2++;
        }

        vector<int> ans;

        cout << count1;
        if (count1 > n / 3) ans.push_back(ele1);
        if (count2 > n / 3) ans.push_back(ele2);

        return ans;
    }
};