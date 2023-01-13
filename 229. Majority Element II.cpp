//Apporach
//Extended of Boyer Moore's Voting Algorithm 

    vector<int> majorityElement(vector<int>& nums) {
        int num1=-1;
        int num2=-1;

        int cnt1=0;
        int cnt2=0;

        for(int i=0; i<nums.size(); i++){
            if(nums[i]==num1) cnt1++;
            else if(nums[i]==num2) cnt2++;
            else if(cnt1==0){
                num1=nums[i];
                cnt1=1;
            }
            else if(cnt2==0){
                num2=nums[i];
                cnt2=1;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }
    
        float num1Cnt=0;
        float num2Cnt=0;
        for(auto i:nums){
            if(i==num1) num1Cnt++;
            else if(i==num2) num2Cnt++;
        }
        vector<int> ans;
        if(num1Cnt>float(nums.size())/3){
            ans.push_back(num1);
        } 
        if(num2Cnt>float(nums.size())/3){
            ans.push_back(num2);
        } 
        return ans;
    }
