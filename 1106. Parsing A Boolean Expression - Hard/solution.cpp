static auto _ = [] () {ios_base::sync_with_stdio(false);cin.tie(nullptr);return 0;}();
class Solution {
public:
    enum Operations {
        Not,
        And,
        Or
    };
    
    bool parseBoolExpr(string expression) {
        stack < Operations > operations;
        stack < stack < bool > > variables;
        variables.push({});
        
        set < char > brackets_set = {'(', ')'};
        set < char > operations_set = {'&', '|', '!'};
        set < char > variables_set = {'t', 'f'};
        
        auto it = expression.begin();
        while (it != expression.end()) {
            if (operations_set.count(*it)) {
                switch (*it) {
                    case '&': {operations.push(Operations::And); break;}
                    case '|': {operations.push(Operations::Or ); break;}
                    case '!': {operations.push(Operations::Not); break;}
                }
            } else if (brackets_set.count(*it)) {
                if (*it == '(') {
                    variables.push({});
                } else {
                    bool result;
                    if (operations.top() == Operations::Not) {
                        result = !variables.top().top();
                    } else if (operations.top() == Operations::And) {
                        result = true;
                        while (!variables.top().empty()) {
                            result &= variables.top().top();
                            variables.top().pop();
                        }
                    } else {
                        result = false;
                        while (!variables.top().empty()) {
                            result |= variables.top().top();
                            variables.top().pop();
                        }
                    }
                    operations.pop();
                    variables.pop();
                    variables.top().push(result);
                }
            } else if (variables_set.count(*it)) {
                variables.top().push(*it == 't');
            }
            
            ++it;
        }
        
        return variables.top().top();
    }
};