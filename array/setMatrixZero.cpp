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

//better approach
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
        //brute force
        // int n = mat.size();
        // int m = mat[0].size();
        // for(int i = 0 ; i<n ; i++){
        //     for(int j = 0; j<m ; j++){
        //         if(mat[i][j] == 0){
        //             markRow(i,mat,n,m);
        //             markCol(j,mat,n,m);
        //         }
        //     }
        // }
        // for(int i = 0 ; i<n ; i++){
        //     for(int j = 0 ; j<m ; j++){
        //         if(mat[i][j] == -1){
        //             mat[i][j] = 0;
        //         }
        //     }
        // }


        //better approach
        int n = mat.size();
        int m = mat[0].size();
        vector<int> row(n,0);
        vector<int> col(m,0);
        for(int i = 0 ; i<n ; i++){
            for(int j = 0; j<m ; j++){
                if(mat[i][j] == 0){
                    row[i] =1;
                    col[j]=1;
                }
            }
        }
        for(int i = 0; i<n ; i++){
            for(int j = 0; j<m ; j++){
                if(row[i]==1 || col[j]==1){
                    mat[i][j] = 0;
                }
            }
        }

    }
};




 //optimal approach
        int n = mat.size();
        int m = mat[0].size();
        
        // int row[n] = {0}; --> matrix[..][0]
        // int col[m] = {0}; --> matrix[0][..]

    int col0 = 1;
    // step 1: Traverse the matrix and
    // mark 1st row & col accordingly:
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == 0) {
                // mark i-th row:
                mat[i][0] = 0;

                // mark j-th column:
                if (j != 0)
                    mat[0][j] = 0;
                else
                    col0 = 0;
            }
        }
    }

    // Step 2: Mark with 0 from (1,1) to (n-1, m-1):
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (mat[i][j] != 0) {
                // check for col & row:
                if (mat[i][0] == 0 || mat[0][j] == 0) {
                    mat[i][j] = 0;
                }
            }
        }
    }

    //step 3: Finally mark the 1st col & then 1st row:
    if (mat[0][0] == 0) {
        for (int j = 0; j < m; j++) {
            mat[0][j] = 0;
        }
    }
    if (col0 == 0) {
        for (int i = 0; i < n; i++) {
            mat[i][0] = 0;
        }
    }
    }