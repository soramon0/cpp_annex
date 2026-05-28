#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("Shrubbery Creation", 145, 137, "") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target)
    : AForm("Shrubbery Creation", 145, 137, target) {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other)
    : AForm(other) {}

ShrubberyCreationForm &
ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other) {
  AForm::operator=(other);
  return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::executeAction() const {
  std::string filename = getTarget() + "_shrubbery";
  std::ofstream file(filename.c_str());
  if (!file.is_open())
    return;
  file << "        #" << std::endl;
  file << "       ###" << std::endl;
  file << "      #####" << std::endl;
  file << "     #######" << std::endl;
  file << "    #########" << std::endl;
  file << "      #####" << std::endl;
  file << "     #######" << std::endl;
  file << "    #########" << std::endl;
  file << "   ###########" << std::endl;
  file << "  #############" << std::endl;
  file << "       ###" << std::endl;
  file.close();
}
