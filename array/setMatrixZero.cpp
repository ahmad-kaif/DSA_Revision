// brute force
class Solution {
public:
    void markRow(int i,vector<vector<int>>& mat,int &n, int &m){
        for(int j = 0 ; j<m ; j++){
            if(mat[i][j] != 0){
                mat[i][j] = -1;
            }
        }
    }
    void markCol(int j,vector<vector<int>>& mat,int &n, int &m){
        for(int i = 0 ; i<n ; i++){
            if(mat[i][j] != 0){
                mat[i][j] = -1;
            }
        }
    }
    void setZeroes(vector<vector<int>>& mat) {
        brute force
        int n = mat.size();
        int m = mat[0].size();
        for(int i = 0 ; i<n ; i++){
            for(int j = 0; j<m ; j++){
                if(mat[i][j] == 0){
                    markRow(i,mat,n,m);
                    markCol(j,mat,n,m);
                }
            }
        }
        for(int i = 0 ; i<n ; i++){
            for(int j = 0 ; j<m ; j++){
                if(mat[i][j] == -1){
                    mat[i][j] = 0;
                }
            }
        }
    }
};