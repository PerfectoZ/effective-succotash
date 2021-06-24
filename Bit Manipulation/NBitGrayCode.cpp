class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans ;
        for(int i=0 ; i<(1<<n); i++)
        {
            int x = i xor (i>>1) ;
            ans.push_back(x);
        }
        return ans ;
    }
};
