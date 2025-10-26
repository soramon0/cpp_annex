#include "Harl.hpp"

int main(int argc, char *argv[]) {
  Harl harl;
  std::string lvl = "DEBUG";

  if (argc >= 2) {
    lvl = argv[1];
  }

  switch (harl.getPriority(lvl)) {
  case Logger::DEBUG:
    harl.complain("DEBUG");
    [[fallthrough]];
  case Logger::INFO:
    harl.complain("INFO");
    [[fallthrough]];
  case Logger::WARNING:
    harl.complain("WARNING");
    [[fallthrough]];
  case Logger::ERROR:
    harl.complain("ERROR");
    break;

  default:
    harl.complain("unknown");
  }

  return 0;
}
