// class Solution {
// public:
//     vector<vector<int>> subsets(vector<int>& nums) {
//         int n=nums.size();
//         vector<vector<int>> res;
//         for(int i=0;i<pow(2,n);i++){
//             vector<int> v;
//            for(int j=0;j<n;j++){
//             if((i>>j)&1 ){
//                 v.push_back(num[j]);
//             }
//            } 
//            res.push_back(v);
//         }
//     }
// };