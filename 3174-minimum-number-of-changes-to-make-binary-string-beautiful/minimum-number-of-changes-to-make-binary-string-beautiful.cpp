class Solution {
public:
    int minChanges(string s) {
        int change = 0;
        int n = s.size();

        int i = 0;
        int j = 1;

        while(i < n-1 && j < n){
            if(s[i] != s[j]){
                change++;
            }
            i = i+2;
            j = j + 2;
        }

        return change;
    }
};