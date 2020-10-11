class Solution {
public:

    bool check(string s) {
        if(s.size() == 1) return true;

        int n = s.size();
        for(int i = 0; i < n; i ++) {
            if(s[i] != s[n-i-1]) return false;
        }
        return true;
    }
    bool check1(string a, string b) {
        int n = a.size();
        int m = b.size();
        int i = 0, j = m-1;
        while(i < n && j >= 0) {
            if(i == j) return true;
            if(a[i] != b[j]) break;
            if(i == j - 1) return true;
            i++;
            j--;
        }

        while(i <= j) {
            if(b[j] != b[i] && a[i] != a[j]) return false;
            i++;
            j--;
        }
    
        return true;
    }
    bool checkPalindromeFormation(string a, string b) {
        if(check(a)) return true;
        if(check(b)) return true;
        if(check1(a,b)) return true;
        if(check1(b,a)) return true;
        return false;

    }
};