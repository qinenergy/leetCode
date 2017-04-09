class Solution2 {
public:
    int evalRPN(vector<string>& tokens) {
        int len = tokens.size(), rst = 0;
        stack<int> operands;
        for(auto& ch : tokens){
            if(ch.size() == 1 && (ch[0] == '*' || ch[0] == '/' || ch[0] == '+' || ch[0] == '-')){
                auto op1 = operands.top();
                operands.pop();
                auto op2 = operands.top();
                operands.pop();
                switch(ch[0]){
                    case '*':
                        rst = op1 * op2;
                        break;
                    case '/':
                        rst = op2 / op1;
                        break;
                    case '+':
                        rst = op1 + op2;
                        break;
                    case '-':
                        rst = op2 - op1;
                        break;
                    default:
                        break;
                }
                operands.push(rst);
            }
            else{
                if(ch[0] == '-')
                    operands.push(-atoi(ch.substr(1).c_str()));
                else
                    operands.push(atoi(ch.c_str()));
            }
        }
        return operands.top();
    }
};