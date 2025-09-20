#pragma once

#include <string>

class Contact {
private:
  std::string _fname;
  std::string _lname;
  std::string _nickname;
  std::string _phone;
  std::string _darkestSecret;

public:
  const std::string getFname() const;
  const std::string getLname() const;
  const std::string getNickname() const;
  const std::string getPhone() const;
  const std::string getDarkestSecret() const;
  
  void setFname(const std::string fname);
  void setLname(const std::string lname);
  void setNickname(const std::string nickname);
  void setPhone(const std::string phone);
  void setDarkestSecret(const std::string darkestSecret);
  
  void print() const;
};
