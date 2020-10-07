class Solution {
public:
    struct node {
        int x, y;
        node(int x, int y):x(x), y(y) {};
        bool operator< ( const node &a ) const {
            return a.y < y;
        }
    }; 
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<int> st;
        int ans[100005];
        for(int i = 0; i < k; i ++) ans[i] = 0;
        for(int i = 0; i < k; i ++) st.insert(i);
        priority_queue<node> q;
        int n = arrival.size();
        for(int i = 0; i < n; i ++) {
            
            while( !q.empty() ) {
                //printf("%d ",q.top().y);
                if(q.top().y <= arrival[i]) {
                    st.insert(q.top().x);
                    q.pop();
                }
                else break;
                
            }
            if(st.empty()) continue;
            auto it = st.lower_bound(i%k);
            //printf("%d ",*it);
            if(it == st.end()) it = st.begin();
            ans[*it]++;
            q.push(node(*it,arrival[i] + load[i]));
            st.erase(it);
        }
        vector<int> ansx;
        int maxn = 0;
        for(int i = 0; i < k; i ++) {
            maxn = max(ans[i], maxn);
        }
        for(int i = 0; i < k; i ++) if(ans[i] == maxn) ansx.push_back(i);
        return ansx;
    }
};