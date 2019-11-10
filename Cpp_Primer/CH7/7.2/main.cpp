#include <iostream>
#include "Sales_data.h"
#include <iostream>
//添加combine(),isbn()之后的Sale_data类
using std::cin;
using std::cout;
using std::endl;

int main()
{
    Sales_data total;
    if (cin >> total.BookNo >> total.units_sold >> total.revenue) {
        Sales_data trans;
        while (cin >> trans.BookNo >> trans.units_sold >> trans.revenue) {
            if (total.isbn() == trans.isbn())
                total.combine(trans);
            else {
                cout << total.BookNo << " " << total.units_sold << " "
                     << total.revenue << endl;
                total = trans;
            }
        }
        cout << total.BookNo << " " << total.units_sold << " " << total.revenue
             << endl;
    }
    else {
        std::cerr << "No data?!" << std::endl;
        return -1;
    }

    return 0;
}