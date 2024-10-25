#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

string evaluateStatement(vector<string> statement) {
    stack<string> stack;

    for (int i = 0; i < statement.size(); i++) {
        if (statement[i] == "true" || statement[i] == "false") {
            stack.push(statement[i]);
        } else if (statement[i] == "and" || statement[i] == "or") {
            string y = stack.top();
            stack.pop();
            string x = stack.top();
            stack.pop();

            if (statement[i] == "and") {
                stack.push((x == "true" && y == "true") ? "true" : "false");
            } else { // statement[i] == "or"
                stack.push((x == "true" || y == "true") ? "true" : "false");
            }
        }
    }

    return stack.top();
}

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<string> statement(N);
    for (int i = 0; i < N; i++) {
        cin >> statement[i];
    }

    string output = "";

    for (int i = 0; i < Q; i++) {
        int l, r;
        string value;
        cin >> l >> r >> value;

        vector<string> newStatement;
        for (int j = 0; j < l-1; j++) {
            newStatement.push_back(statement[j]);
        }
        newStatement.push_back(value);
        for (int j = r; j < N; j++) {
            newStatement.push_back(statement[j]);
        }

        string result = evaluateStatement(newStatement);

        if (result == "true") {
            output += 'Y';
        } else {
            output += 'N';
        }
    }

    cout << output << endl;

    return 0;
}