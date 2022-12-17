class Solution {
public:
    
#define ll long long
int evalRPN(vector<string>& tokens) 
{
    stack<ll> st;
    for(int i=0; i< tokens.size(); i++){
        if(tokens[i] == "*"){
            ll a = st.top();   st.pop();
            ll b = st.top();   st.pop();

            ll c = a  * b;
            st.push(c);
        }
        else if(tokens[i] == "+"){
            ll a = st.top();   st.pop();
            ll b = st.top();   st.pop();

            ll c = a  + b;
            st.push(c);
        }
        else if(tokens[i] == "-"){
           ll a = st.top();   st.pop();
           ll b = st.top();   st.pop();

           ll c = b - a;
           st.push(c); 
        }
        else if(tokens[i] == "/"){
             ll a = st.top();   st.pop();
             ll b = st.top();   st.pop();

             ll c = b / a;
             st.push(c);
        }else{
            ll k = stoi(tokens[i]);
            st.push(k);
        }
    }

    return st.top();
}

};