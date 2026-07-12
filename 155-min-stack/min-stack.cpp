class MinStack {
public:
    stack<long long> st;
    long long mini;

    MinStack() {
        
    }
    
    void push(int value) {
        long long val = value; // promote to long long
        if (st.empty()) {
            mini = val;
            st.push(val);
            return;
        }
        
        if (val > mini) {
            st.push(val);
        }
        else {
            st.push(2 * val - mini); 
            mini = val;
        }
    }
    
    void pop() {
        if (st.empty()) return;
        
        long long x = st.top();
        st.pop();
        
        if (x < mini) {
            mini = 2 * mini - x;    
        }
    }
    
    int top() {
        if (st.empty()) return -1;
        
        long long x = st.top();
        
        if (mini < x) return (int)x;
        return (int)mini;
    }
    
    int getMin() {
        return (int)mini;
    }
};