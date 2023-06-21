void hashn_solve(int grid[N][N], int i ,int j ,vector<vector<int>>& rowhash , vector<vector<int>> & columnhash, vector<vector<int>>& box_hash)
    {
        if(i==9) 
        {
          for(int i=0 ; i<N ; i++)
        {
            for(int j=0 ; j<N ; j++)
            {
                cout << grid[i][j] << " ";
            }
        }  
            return;
        }
        
        if(grid[i][j]!=0)
            {
                hashn_solve(grid, i+(j+1)/9 , (j+1)%9 ,rowhash,columnhash , box_hash);
            }
            
        else{    
        for(int num =1 ; num<10 ; num++)
        {
            int box_num = 3*((i>2) + (i>5)) + (j>2) + (j>5);
            int condition = rowhash[i][num]==0 && columnhash[j][num]==0 && box_hash[box_num][num] ==0;
            if(!condition) continue;
            
            rowhash[i][num]++;
            columnhash[j][num]++;
            box_hash[box_num][num]++;
            grid[i][j] = num;
            hashn_solve(grid, i+(j+1)/9 , (j+1)%9 ,rowhash,columnhash , box_hash);
            
            grid[i][j] = 0;
            rowhash[i][num] = 0;
            columnhash[j][num] = 0;
            box_hash[box_num][num] = 0;
        }
        }
    }
    bool SolveSudoku(int grid[N][N])  
    { 
        vector<vector<int>> rowhash(9, vector<int>(10,0));
        vector<vector<int>> columnhash(9, vector<int>(10,0));
        vector<vector<int>> box_hash(9, vector<int>(10,0));
        
        for(int i=0; i<N ; i++)
        {
            for(int j=0 ; j<N ; j++)
            {
                if(grid[i][j] == 0) continue;
                
                if(rowhash[i][grid[i][j]] != 0) return false;
                rowhash[i][grid[i][j]]++;
                
                if(columnhash[j][grid[i][j]] != 0) return false;
                columnhash[j][grid[i][j]]++;
                
                int box_num = 3*((i>2) + (i>5)) + (j>2) + (j>5);
                
                if(box_hash[box_num][grid[i][j]]!= 0 ) return false;
                box_hash[box_num][grid[i][j]]++;
            }
        }
         hashn_solve(grid ,0,0, rowhash ,columnhash , box_hash);
        return true;
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        
    }
