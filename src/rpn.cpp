#include "rpn.h"
#include <stack>
#include <sstream>
#include <stdexcept>

double eval_rpn(const std::string& expr) {
    std::istringstream in(expr);
    std::stack<double> st;
    std::string t;
    while (in >> t) {
        if (t == "+" || t == "-" || t == "*" || t == "/") {
            if (st.size() < 2) throw std::runtime_error("bad expr");
            double b = st.top(); st.pop();
            double a = st.top(); st.pop();
            if (t == "+") st.push(a + b);
            else if (t == "-") st.push(a - b);
            else if (t == "*") st.push(a * b);
            else {
                if (b == 0.0) throw std::runtime_error("div by zero");
                st.push(a / b);
            }
        } else {
            st.push(std::stod(t));
        }
    }
    if (st.size() != 1) throw std::runtime_error("bad expr");
    return st.top();
}
