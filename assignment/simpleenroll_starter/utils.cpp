/*
 * CS106L SimpleEnroll Assignment Part 1
 * Created by Fabio Ibanez
 * Please complete each STUDENT TODO in this file.
 *
 * Students must implement: parse_csv, write_courses_offered,
 * write_courses_not_offered
 */

// (FIRST) STUDENT TODO: change how variables are passed into the functions you
// must complete

#include <fstream>
#include <iostream>
#include <sstream>
#include <tuple>
#include <vector>

// STUDENT TODO: add paths
std::string COURSES_OFFERED_CSV_PATH = "/Users/yaoyaoling/code/cpp/cs106L/assignment/simpleenroll_starter/student_output/courses_offered.csv";

std::string COURSES_NOT_OFFERED_CSV_PATH = "/Users/yaoyaoling/code/cpp/cs106L/assignment/simpleenroll_starter/student_output/courses_not_offered.csv";

struct Course {
  /* STUDENT TODO: ADD TYPE */ std::string title;
  /* STUDENT TODO: ADD TYPE */ std::string number_of_units;
  /* STUDENT TODO: ADD TYPE */ std::string quarter;

  // ignore this!
  bool operator==(const Course &other) const {
    return title == other.title && number_of_units == other.number_of_units &&
           quarter == other.quarter;
  }
};

// forward declarations
void delete_elem_from_vector(std::vector<Course> &v, Course &elem);
std::vector<std::string> split(std::string s, char delim);

/*
 * This function should populate the vector_of_courses with structs of type
 * Class We want to create these structs with the records in the courses.csv
 * file, where each line is a record!
 *
 * Hints:
 * 1) Take a look at the split function we provide
 * 2) Each LINE is a record! *this is important, so we're saying it again :>)*
 */
void parse_csv(std::string filename, std::vector<Course>& vector_of_courses) {
  // STUDENT TODO: Implement this function
  using namespace std;
  ifstream file(filename);
  string line;
  // Swallow the first line
  getline(file, line);
  while (getline(file, line)) {
    vector<string> record = split(line, ',');
    Course course;
    course.title = record[0];
    course.number_of_units = record[1];
    course.quarter = record[2];
    // cout << "course.title = " << course.title << endl;
    vector_of_courses.push_back(course);
  }
  cout << "vector_of_courses.size() = " << vector_of_courses.size() << endl;
  // cout << "vector_of_courses[0].title = " << vector_of_courses[0].title << endl;
  file.close();
}

/*
 * This function has TWO requirements.
 * 1) Write the courses that are offered to the file courses_offered.csv inside
 * the student_output folder
 *
 * 2) Delete classes that are offered from vector_of_courses.
 * IMPORTANT: do this after you write out to the file!
 *
 * HINTS:
 * 1) Keep track of the classes that you need to delete!
 * 2) Use the delete_elem_from_vector function we give you!
 */
void write_courses_offered(std::vector<Course>& vector_of_courses) {
  // STUDENT TODO: implement this function
  using namespace std;
  ofstream file(COURSES_OFFERED_CSV_PATH);
  cout << "vector_of_courses.size() before offered = " << vector_of_courses.size() << endl;
  
  // for (Course& course : vector_of_courses) {
  //   if (course.quarter != "null") {
  //     file << course.title << "," << course.number_of_units << "," << course.quarter << endl;
  //     // 不能立刻删除，因为删除了之后，vector_of_courses.size()会变小，导致后面的元素索引变化
  //     // delete_elem_from_vector(vector_of_courses, course);
  //   }
  // }
  for (auto it = vector_of_courses.begin(); it != vector_of_courses.end();) {
    if (it->quarter != "null") {
      file << it->title << "," << it->number_of_units << "," << it->quarter << endl;
      it = vector_of_courses.erase(it);
    } else {
      ++it;
    }
  }
  cout << "vector_of_courses.size() after offered= " << vector_of_courses.size() << endl;
  file.close();
}

/*
 * This function writes the courses NOT offered to the file
 * courses_not_offered.csv inside of the student_output folder
 *
 * This function is ALWAYS called after the write_courses_offered function.
 * vector_of_courses will trivially contain classes that are not offered
 * since you delete offered classes from vector_of_courses in the
 * 'write_courses_offered' function.
 *
 * HINT: This should be VERY similar to write_courses_offered
 */
void write_courses_not_offered(std::vector<Course>& vector_of_courses) {
  // STUDENT TODO: implement this function
  using namespace std;
  ofstream file(COURSES_NOT_OFFERED_CSV_PATH);
  cout << "vector_of_courses.size() = " << vector_of_courses.size() << endl;
  for (Course& course : vector_of_courses) {
    // if (course.quarter == "null") 
    file << course.title << "," << course.number_of_units << "," << course.quarter << endl;
  }
  file.close();
  // vector_of_courses.clear();
}

/* ######## HEYA! DON'T MODIFY ANYTHING BEYOND THIS POINT THX ######## */

// TODO: ADD DOCUMENTATION COMMENTS
void print_vector(std::vector<Course> vector_of_courses) {
  for (int i = 1; i < vector_of_courses.size(); ++i) {
    std::cout << vector_of_courses[i].title << ","
              << vector_of_courses[i].number_of_units << ","
              << vector_of_courses[i].quarter << std::endl;
  }
}

void delete_elem_from_vector(std::vector<Course> &v, Course &elem) {
  auto it = std::find(v.begin(), v.end(), elem);
  // std::cout << "erasing " << elem.title << " from vector" << std::endl;
  v.erase(it);
  // std::cout << "vector_of_courses.size() = " << v.size() << std::endl;
}

std::vector<std::string> split(std::string s, char delim) {
  std::vector<std::string> return_vec;
  std::stringstream ss(s);
  std::string token;
  while (getline(ss, token, delim)) {
    return_vec.push_back(token);
  }
  return return_vec;
}
