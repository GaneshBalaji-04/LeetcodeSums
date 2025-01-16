// DP loop solution - Bottom up approach
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        vector<int> prevRows;
        for(int i=0;i<numRows;i++){
            vector<int> currRows(i+1,1);
            for(int j=1;j<i;j++){
                currRows[j] = prevRows[j-1] +  prevRows[j];
            }
            result.push_back(currRows);
            prevRows = currRows;
        }
        return result;
    }
};

// DP loop solution - Top down approach
