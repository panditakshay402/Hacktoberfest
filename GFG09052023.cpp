

// GFG POTD 09052023

class Solution {
  public:
    int countStrings(long long int N) {
        long long a[2][2] = {{1, 1}, {1, 0}}, b[2][2];
        pow(N+1, a, b);
        return b[0][0];
    }
    
    void pow(long long n, long long a[2][2], long long b[2][2]) {
        if(n == 0) {
            b[0][0] = b[1][1] = 1;
            b[1][0] = b[0][1] = 0;
            return;
        }
        long long c[2][2];
        pow(n/2, a, c);
        mul(c, c, b);
        if(n&1) {
            copy(c, b);
            mul(a, c, b);
        }
    }
    
    void mul(long long a[2][2], long long b[2][2], long long c[2][2]) {
        int d = 1e9 + 7;
        for(int e = 0; e < 2; e++) {
            for(int f = 0; f < 2; f++) {
                c[e][f] = 0;
                for(int g = 0; g < 2; g++) {
                    c[e][f] = (c[e][f] + (a[e][g]*b[g][f]) % d) % d;
                }
            }
        }
    }
    
    void copy(long long a[2][2], long long b[2][2]) {
        for(int h = 0; h < 2; h++) for(int i = 0; i < 2; i++) a[h][i] = b[h][i];
    }
};
