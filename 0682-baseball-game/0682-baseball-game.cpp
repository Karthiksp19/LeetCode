class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> s;
        int n = operations.size();
        for(int i = 0; i < n; i++){
            string str = operations[i];
            if(str == "+"){
                int a = s.top(); s.pop();
                int b = s.top(); s.pop();
                s.push(b);
                s.push(a);
                s.push(a + b);
            }
            else if(str == "D"){
                int a = s.top(); s.pop();
                s.push(a);
                s.push(2 * a);
            }
            else if(str == "C"){
                s.pop();
            }
            else{
                s.push(stoi(str));
            }
        }

        int sum = 0;
        while(!s.empty()){
            sum += s.top();
            s.pop();
        }

        return sum;
    }
};