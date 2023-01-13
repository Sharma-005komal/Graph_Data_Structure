class Solution {
public:
    bool judgeCircle(string moves) {
        int n = moves.length(), x = 0, y = 0;
        for(int i=0; i<n; i++)
        {
            if(moves[i] == 'U')
            {
                x++;
            }
            else if(moves[i] == 'D')
            {
                x--;
            }
            else if(moves[i] == 'L')
            {
                y++;
            }
            else if(moves[i] == 'R')
            {
                y--;
            }
        }
        if(x == 0 && y == 0)
        {
            return true;
        }
        return false;
    }
};
