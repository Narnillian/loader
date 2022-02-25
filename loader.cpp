#include <iostream>
#include <time.h>
using namespace std;

int moveback;
int characters;
int writeChars;


int printwait(struct timespec ts) {
  fflush(stdout);
  nanosleep(&ts,NULL);
  return 0;
}


void v1(struct timespec ts, int limit = 0) {
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
    printwait(ts);printwait(ts);printwait(ts);printwait(ts);printwait(ts);printwait(ts);printwait(ts);printwait(ts);printwait(ts);printwait(ts);
    //cout << iterations << "\033[2D";
    printwait(ts);printwait(ts);printwait(ts);printwait(ts);printwait(ts);printwait(ts);printwait(ts);printwait(ts);printwait(ts);printwait(ts);
    ts.tv_nsec=70000000;
    printwait(ts);
  }

}

int main() {
  
  struct timespec ts;
  ts.tv_sec=0;


  cout << "Loading...   ";

  v1(ts,10);

  cout << "\n";
  

  return 0;
}
