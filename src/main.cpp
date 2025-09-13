#include <iostream>
#include "rpn.h"
int main(int argc, char** argv){
    std::string expr = (argc>1)? argv[1] : "3 4 + 2 *";
    try { std::cout << eval_rpn(expr) << "\n"; }
    catch(const std::exception& e){ std::cerr << "Error: " << e.what() << "\n"; return 1; }
    return 0;
}
