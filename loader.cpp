#include <iostream>
#include <chrono>
using namespace std;

int moveback;
int characters;
int writeChars;


void printwait(struct timespec ts) {
  fflush(stdout);
  nanosleep(&ts,NULL);
}


void simpleloader(struct timespec ts, int limit = 0) {
  int iterations = 0;
  bool checker = true;
  if (limit) {
    checker = false;
  }
  while (checker || iterations < limit) {
    iterations++;
    ts.tv_nsec=20000000;
    characters = 15;
    for (writeChars=0; writeChars < characters; writeChars++) {
      cout << "|";
      printwait(ts);
    }
    cout << "\033[s";
    nanosleep(&ts,NULL);
    for (writeChars=0; writeChars < characters; writeChars++) {
      moveback = writeChars+1;
      cout << "\033[u\033[" << moveback << "D\\";
      printwait(ts);
    }
    cout << "\033[1D";
    ts.tv_nsec=70000000;
    printwait(ts);
  }

}


void iterativeloader(struct timespec ts, int limit = 0) {
  int iterations = 0;
  bool checker = true;
  if (limit) {
    checker = false;
  }
  while (checker || iterations < limit) {
    char fillers[] = {"/|\\-"};
    iterations++;
    ts.tv_nsec=20000000;
    characters = 15;
    for (int i = 0; i < 4; i++) {
      for (writeChars=0; writeChars < characters; writeChars++) {
        cout << fillers[i];
        printwait(ts);
      }
      cout << "\033[15D";
      nanosleep(&ts,NULL);
    }
  }
}

/**/
int main() {
  
  struct timespec ts;
  ts.tv_sec=0;


  cout << "Loading...   ";


  simpleloader(ts,5);
  cout << "\n";
  cout << "Loading...   ";

  iterativeloader(ts,10); //

  cout << "\n";
  

  return 0;
}
/**/