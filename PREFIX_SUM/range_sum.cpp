class NumArray {
public:
    vector<int> sum_range;
    NumArray(vector<int>& nums) {
        sum_range.push_back(nums[0]);
        for (int i=1;i<nums.size();i++){
            sum_range.push_back(sum_range[sum_range.size()-1] + nums[i] );
        }

        for (int i=0;i<sum_range.size();i++){
            cout<<sum_range[i]<<" ";
        }
    }
    
    int sumRange(int left, int right) {

     
        if (left==0)
            return sum_range[right];
        else
            return sum_range[right]- sum_range[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */