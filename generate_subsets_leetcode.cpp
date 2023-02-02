//https://leetcode.com/problems/subsets/submissions/889893976/
class Solution {
public:
vector<vector<int>> subsetss;

void generate_subsets(vector<int> &subset,int i,int n,vector<int>& nums){
  if(i==n){
    subsetss.push_back(subset);
    return;
  }
  //ith element not considered
  generate_subsets(subset,i+1,n,nums);
  //ith element is considered
  subset.push_back(nums[i]);
  generate_subsets(subset,i+1,n,nums);
  subset.pop_back();
}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subset;
        generate_subsets(subset,0,size(nums),nums);
        return subsetss;
    }
};