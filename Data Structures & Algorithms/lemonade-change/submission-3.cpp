class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int> changes(3,0);
        for (int b : bills) {
            if (b == 5) changes[0]++;
            else {
                if (b == 10) {
                    if(changes[0] > 0) {
                        changes[0]--;
                        changes[1]++;
                    } else {
                        return false;
                    }
                } else if (b == 20) {
                    if (changes[0] < 1 || (changes[1]<1 && changes[0] < 3)) {
                        return false;
                    } else {
                        if (changes[1] < 1) {
                            changes[0]-=3;
                        } else {
                            changes[0]--;
                            changes[1]--;
                        }
                        changes[2]++;
                    }
                }
            }
        }
        return true;
    }
};