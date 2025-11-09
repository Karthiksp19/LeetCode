class Solution {
public:
    vector<int> constructRectangle(int area) {
        int L = sqrt(area);
        for (int i = L; i >= 1; i--){
            if(area % i == 0){
                return {area/ i, i};
            }
        }
        return {area, 1};

    }
};