 vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>v;
        int row=matrix.size();
        int col=matrix[0].size();
        int c=0,total=row*col;
        int sr=0,er=row-1,sc=0,ec=col-1;
        while(c<total){
            for(int i=sc;i<=ec && c<total;i++){
                v.push_back(matrix[sr][i]);
                c++;
            }
            sr++;
            for(int i=sr;i<=er && c<total;i++){
                v.push_back(matrix[i][ec]);
                c++;
            }
            ec--;
            for(int i=ec;i>=sc && c<total;i--){
                v.push_back(matrix[er][i]);
                c++;
            }
            er--;
            for(int i=er;i>=sr && c<total;i--){
                v.push_back(matrix[i][sc]);
                c++;
            }
            sc++;
        }
        return v;
    }
