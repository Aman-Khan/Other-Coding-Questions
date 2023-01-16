//
    void generate(int i, string temp, vector<string> &ans, int n, int balance){
        if(balance<0) return;
        if(temp.size()==n){
            if(balance==0) ans.push_back(temp);
            return;
        }

        if(temp.length()!=n-1){
            temp.push_back('(');
            balance++;
            generate(i+1, temp, ans, n, balance);
            balance--;
            temp.pop_back();
        }
        if(temp.length()!=0){
            temp.push_back(')');
            balance--;
            generate(i+1, temp, ans, n, balance);
            balance++;
        }
    }
    
   
// using balance variable
   void generator(int i, int balance, string temp, vector<string>& ans, int n){
        if(balance<0) return;
        if(i>=n){
            if(balance==0){
                ans.push_back(temp);
            }
            return;
        }

        if(balance-1>=0){
            temp.push_back(')');
            generator(i+1, balance-1, temp, ans, n);
            temp.pop_back();
        }

        temp.push_back('(');
        generator(i+1, balance+1, temp, ans, n);
        temp.pop_back();
    
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp="";
        int balance=0;
        generator(0, balance, temp, ans, n*2);
        return ans;
    }
