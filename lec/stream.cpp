#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <sstream>

void classExample() {
  std::string lectureString = "1 2 3 4 5 6";
  /// initializing a stringstream with lectureString
  std::stringstream ss(lectureString);

  ///  defining my output type as a int for 'one', 'two', 'three', 'four'
  int one, two, three, four;

  /// defining my output type for five as a string
  std::string five, six;

  ss >> one;
  ss >> two;
  ss >> three;
  ss >> four >> five >> six;

  std::cout << one + two + three + four << std::endl;
}

void extractedQuoteFailureExample() {
  /// partial Bjarne Quote
  std::string initial_quote =
      "Bjarne Stroustrup C makes it easy to shoot yourself in the foot";

  /// create a stringstream
  std::stringstream ss;
  ss << initial_quote;

  /// data destinations
  std::string first;
  std::string last;
  std::string language, extracted_quote;

  ss >> first >> last >> language >> extracted_quote;
  std::cout << first << " " << last << " said this: " << language << " "
            << extracted_quote << std::endl;
}

void extractedQuoteSuccessExample() {
  /// partial Bjarne Quote
  std::string initial_quote = "Bjarne Stroustrup C makes it easy to shoot"
                              "yourself in the foot ";

  /// create a stringstream
  std::stringstream ss(initial_quote);

  /// data destinations
  std::string first;
  std::string last;
  std::string language, extracted_quote;
  std::getline(ss, extracted_quote);
  ss >> first >> last >> language;

  std::cout << first << " " << last << " said: " << language << " "
            << extracted_quote << '\n';
}

/*
 * Weird behaviour!
 */
void extractedQuoteSuccessExampleOrdered() {
  /// partial Bjarne Quote
  std::string initial_quote = "Bjarne Stroustrup C makes it easy to shoot"
                              "yourself in the foot ";

  /// create a stringstream
  std::stringstream ss(initial_quote);

  /// data destinations
  std::string first;
  std::string last;
  std::string language, extracted_quote;
  ss >> first >> last >> language;
  std::getline(ss, extracted_quote);

  std::cout << first << " " << last;
  std::cout << " said: " << language << " " << extracted_quote << '\n';
}

void verifyPi() {
  double pi;
  std::cin >> pi;
  /// verify the value of pi and type
  std::cout << pi / 2 << '\n';
}

int outputFileStreamCodeTruncate() {
  /// associating file on construction
  std::ofstream ofs("truncate.txt");
  if (ofs.is_open()) {
    ofs << "Hello CS106L!" << '\n';
  }
  ofs.close();
  ofs << "this will not get written";

  // to append instead of truncate!
  ofs.open("truncate.txt");
  ofs << "this will though! It’s open again";
  return 0;
}

int outputFileStreamCodeAppend() {
  /// associating file on construction
  std::ofstream ofs("append.txt");
  if (ofs.is_open()) {
    ofs << "Hello CS106L!";
  }
  ofs.close();
  ofs << "this will not get written";

  // to append instead of truncate!
  ofs.open("append.txt", std::ios::app);
  ofs << "this will though! It’s open again";

  ofs.close();
  return 0;
}

int inputFileStreamExample() {
  std::ifstream ifs("append.txt");
  if (ifs.is_open()) {
    std::string line;
    std::getline(ifs, line);
    std::cout << "Read from the file: " << line << '\n';
  }

  if (ifs.is_open()) {
    std::string lineTwo;
    std::getline(ifs, lineTwo);
    std::cout << "After reopening, read: " << lineTwo << '\n';
  }

  return 0;
}

void cinFailure() {
  double pi;
  double tao;
  std::string name;
  std::cin >> pi;
  std::cin >> name;
  std::cin >> tao;
  std::cout << "my name is : " << name << " tao is : " << tao
            << " pi is : " << pi << '\n';
}

void cinGetlineBug() {
  double pi;
  double tao;
  std::string name;
  std::cin >> pi;
  std::getline(std::cin, name);
  std::cin >> tao;
  std::cout << "my name is : " << name << " tao is : " << tao
            << " pi is : " << pi << '\n';
}

void cinActuallyFixed() {
  double pi;
  double tao;
  std::string name;
  std::cin >> pi;

  /// consumes the '\n' character
  std::getline(std::cin, name);
  std::getline(std::cin, name);
  std::cin >> tao;
  std::cout << "my name is : " << name << " tao is : " << tao
            << " pi is : " << pi << '\n';
}

int testFstream() {
  std::fstream fs("append.txt", std::ios::in | std::ios::out | std::ios::app);

  // Write to the file
  if (fs.is_open()) {
    fs << "Hello CS106L!" << '\n';

    // moves the get pointer to the beginning of the file
    fs.seekg(0, std::ios::beg);

    std::string line;
    std::getline(fs, line);
    std::cout << "Read from the file: " << line << '\n';

    std::string lineTwo;
    std::getline(fs, lineTwo);
    std::cout << "Read from the file: " << lineTwo << '\n';
  } else {
    std::cout << "Whoops the file is not open!" << '\n';
  }
  // close the file when done!
  fs.close();

  return 0;
}

/*
 * TODO(Fabio): fix the stream bug in this code!
 */
int main() {
  std::map<std::string, std::function<void()>> functionMap = {
      {"extractedQuoteFailureExample", extractedQuoteFailureExample},
      {"extractedQuoteSuccessExample", extractedQuoteSuccessExample},
      {"extractedQuoteSuccessExampleOrdered",
       extractedQuoteSuccessExampleOrdered},
      {"verifyPi", verifyPi},
      {"cinFailure", cinFailure},
      {"cinGetlineBug", cinGetlineBug},
      {"cinActuallyFixed", cinActuallyFixed},
      {"testFstream", testFstream},
      {"classExample", classExample},
      {"outputFileStreamCodeTruncate", outputFileStreamCodeTruncate},
      {"outputFileStreamCodeAppend", outputFileStreamCodeAppend},
      {"inputFileStreamExample", inputFileStreamExample}};

  std::string inputFunctionName;
  while (true) {
    std::cout << "\nYou can run one of these functions:\n";
    for (const auto &pair : functionMap) {
      std::cout << pair.first << '\n';
    }
    std::cout << "\nEnter the name of the function you want to run (or 'exit' "
                 "to quit): ";
    std::getline(std::cin, inputFunctionName);

    if (inputFunctionName == "exit") {
      break;
    }

    auto iter = functionMap.find(inputFunctionName);
    if (iter != functionMap.end()) {
      std::cout << "\n###### OUTPUT ######\n";
      iter->second();
    } else {
      std::cout << "Function name not recognized. Please try again."
                << std::endl;
    }
  }

  return 0;
}
