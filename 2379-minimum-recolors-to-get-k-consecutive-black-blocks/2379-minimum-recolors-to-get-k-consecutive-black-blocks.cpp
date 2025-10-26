class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int whiteCount = 0;
        int minChange;

        for(int i=0; i<k; i++){
            if(blocks[i] == 'W') whiteCount++;
        }
        minChange = whiteCount;

        for(int i=k; i < blocks.size(); i++){
            if(blocks[i-k] == 'W') whiteCount--;
            if(blocks[i] == 'W') whiteCount++;

            minChange = min(minChange, whiteCount);
        }
        return minChange;
    }
};