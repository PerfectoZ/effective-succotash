 class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[i].size();j++){
                
                 if(j>i)
                     swap(matrix[i][j],matrix[j][i]);
            }
        }
        
        
        for(int i=0;i<matrix.size();i++){
            
            int j=matrix[i].size()-1;
            int k=0;
            while(k<j)
            {
                swap(matrix[i][k],matrix[i][j]);
                j--;
                k++;
            }
        }
        
        
        
    }
};
