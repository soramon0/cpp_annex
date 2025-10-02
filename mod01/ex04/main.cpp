#include <fstream>
#include <iostream>
#include <string>

enum ErrorCode {
  SUCCESS = 0,
  ERROR_INVALID_ARGUMENT = 1,
  ERROR_INPUT_FILE = 2,
  ERROR_OUTPUT_FILE = 3,
  ERROR_UNKNOWN = 4
};

int replaceFile(std::string filename, std::string targetStr, std::string replcement) {
  if (targetStr.empty()) {
    std::cerr << "s1 cannot be an empty string. Nothing to replace"
              << std::endl;
    return ERROR_INVALID_ARGUMENT;
  }
  std::ifstream inputFile(filename.c_str());
  if (!inputFile.is_open()) {
    std::cerr << filename << ": Could not open input file" << std::endl;
    return ERROR_INPUT_FILE;
  }

  std::string outFilename = filename + ".replace";
  std::ofstream outputFile(outFilename.c_str());
  if (!outputFile.is_open()) {
    inputFile.close();
    std::cerr << outFilename << ": Could not create output file" << std::endl;
    return ERROR_OUTPUT_FILE;
  }

  std::string line;
  std::string content;
  while (std::getline(inputFile, line)) {
    content += line;

    if (!inputFile.eof()) {
      content += '\n';
    }
  }

  if (!inputFile.eof() && inputFile.fail()) {
    inputFile.close();
    outputFile.close();
    std::cerr << filename << ": Failed to read content" << std::endl;
    return ERROR_INPUT_FILE;
  }

  std::string result;
  size_t currentPos = 0;
  size_t foundPos = content.find(targetStr, currentPos);

  while (foundPos != std::string::npos) {
    result += content.substr(currentPos, foundPos - currentPos);
    result += replcement;
    currentPos = foundPos + targetStr.length();
    foundPos = content.find(targetStr, currentPos);
  }

  result += content.substr(currentPos);
  outputFile << result;

  if (outputFile.fail()) {
    std::cerr << outFilename << ": Failed to write content" << std::endl;
    return ERROR_OUTPUT_FILE;
  }

  inputFile.close();
  outputFile.close();
  return SUCCESS;
}

int main(int argc, char *argv[]) {
  if (argc != 4) {
    std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
    return ERROR_INVALID_ARGUMENT;
  }

  return replaceFile(argv[1], argv[2], argv[3]);
}
