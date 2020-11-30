class Solution {
public:
    priority_queue<int> q;
    long long mod = 1e9+7;
    
    long long ans = 0;
    long long cal(long long  bei, long long a, long long  b) {
        long long x = 0;
        if( (b - a) % 2) {
            x = bei * (b + a + 1) * ( (b-a)/2 );
            x += bei * (b+a+1)/2; 
        }
        else {
            x =  ((b-a+1)/2) * bei * (b+a+1); 
        }
        return x;
    }
    int maxProfit(vector<int>& inventory, int orders) {
        int n = inventory.size();
        sort(inventory.begin(), inventory.end());
        long long a,b;
        long long bei = 1;
        long long x = 0;;
        for(int i = n-1; i > 0; i --) {
            b = inventory[i];
            a = inventory[i-1];
            if(a == b) {
                bei++;
            }
            else {
                
                if( bei * (b - a ) <= orders) {
                    orders -= bei * (b - a );
                    x = cal(bei, a, b);
                    x %= mod;
                }
                else {
                    int now = orders/bei;
                    a = b - 1ll*now;
                    x = cal(bei, a, b);
                    now = orders%bei;
                    x%=mod;
                    x += a*now;
                    x%=mod;
                    orders = 0;
                }
                ans = (ans+x)%mod;
                bei++;
            }
        }
        if(orders) {
        
            int now = orders/bei;
            a = inventory[0] - 1ll*now;
            x = cal(bei, a, inventory[0]);
            now = orders%bei;
            x%=mod;
            x += a*now;
            x%= mod;
            ans = (ans+x)%mod;
        }
        
        int res = ans;
        return res;
    }
 };