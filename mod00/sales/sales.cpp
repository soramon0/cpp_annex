#include <iostream>
#include <istream>

class Sales_data {
  friend std::ostream &print(std::ostream &os, const Sales_data &item);
  friend std::istream &read(std::istream &is, Sales_data &item);

  std::string bookNo;
  unsigned units_sold;
  double revenue;

public:
  Sales_data() : bookNo("N/A"), units_sold(0), revenue(0.0) {}
  Sales_data(const std::string &s) : bookNo(s), units_sold(0), revenue(0.0) {}
  Sales_data(const std::string &s, unsigned n, double p)
      : bookNo(s), units_sold(n), revenue(p * n) {}
  Sales_data(std::istream &is) : bookNo("N/A"), units_sold(0), revenue(0.0) {
    read(is, *this);
  }

  std::string isbn() const { return bookNo; }

  Sales_data &combine(const Sales_data &rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
  }

private:
  double avg_price() const {
    if (units_sold) {
      return revenue / units_sold;
    }
    return 0;
  }
};

// Sales_data::Sales_data(std::istream &is)
//     : bookNo("N/A"), units_sold(0), revenue(0.0) {
//   read(is, *this);
// }

std::istream &read(std::istream &is, Sales_data &item) {
  double price = 0;
  is >> item.units_sold >> price;
  item.revenue = price * item.units_sold;
  return is;
}

std::ostream &print(std::ostream &os, const Sales_data &item) {
  os << item.isbn() << " " << item.units_sold << " " << item.revenue << " "
     << item.avg_price();
  return os;
}

int main() {
  struct Sales_data total(std::cin);

  // if (!read(std::cin, total)) {
  //   std::cerr << "No Data ?!" << std::endl;
  //   return 1;
  // }
  //
  // Sales_data trans;
  // while (read(std::cin, trans)) {
  //   if (total.isbn() == trans.isbn()) {
  //     total.combine(trans);
  //   } else {
  //     print(std::cout, total) << std::endl;
  //     total = trans;
  //   }
  // }
  print(std::cout, total) << std::endl;
  return 0;
}
