#include <iostream>
#include "sales_item.h"

using namespace std;




int main() {
//   Sales_item book;
  
//   std::cin >> book;

//   std::cout << book << std::endl;

    int x = 0;

    int &r = x;

    r = 3;

    std::cout << r << std::endl;
    std::cout << x << std::endl;
    
    return 0;

}
