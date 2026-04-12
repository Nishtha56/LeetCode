class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n));
        int top=0;
        int bottom=n-1;
        int left=0;
        int right=n-1;
        int a=1;

        //it starts filling the matrix top: left to right 1,2,3
        //then right to bottom 3,4,5
        ///then bottom to left 5,6,7
        //then bottom left to right 7, 8,9

        while(top<=bottom && left<=right){
            //top row : traverse left to right
            for(int i=left;i<=right;i++){
                matrix[top][i]=a;
                a++;
            }
            top++;

            //goes top right to bottom right
            for(int i=top; i<=bottom;i++){
                matrix[i][right]=a;
                a++;
            }
            right--;

            //goes bottom right to left bottom4
            if(top<=bottom){
                for(int i=right;i>=left;i--){
                matrix[bottom][i]=a;
                a++;
                }
                bottom--;
            }
            

            //goes bottom left to top left 
            if(left<=right){
                for(int i=bottom;i>=top;i--){
                matrix[i][left]=a;
                a++;
            }
            left++;
            }
        }
        return matrix;

    }
};