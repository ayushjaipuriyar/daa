// Online C++ compiler to run C++ program online
#include <iostream>
#include <ctime>
using namespace std;
int main()
{
  // Write C++ code here
  // std::cout << "Hello world!";
  time_t now = time(NULL);
  struct tm *s10 = localtime(&now);
  s10->tm_hour = 10;
  s10->tm_hour = 0;
  s10->tm_sec = 0;
  cout << now << endl;
  cout << mktime(s10);
  time_t r = mktime(s10);
  cout << endl
       << ctime(&r);

  return 0;
}