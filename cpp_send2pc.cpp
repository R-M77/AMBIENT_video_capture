#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
  // Your code to read and process tag data goes here
  bool tagDetected = true; // Example condition when a tag is detected

  if (tagDetected) {
    // Call the send2pc.py script using the system() function
    int systemResult = system("python /path/to/send2pc.py");
    if (systemResult != 0) {
      cout << "Error calling send2pc.py" << endl;
      return 1;
    }
  }

  return 0;
}
