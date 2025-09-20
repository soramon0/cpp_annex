#pragma once

#include <string>

class Zoombie {
private:
  std::string _name;

public:
  Zoombie(std::string name);
  ~Zoombie();

  void announce(void) const;
};
