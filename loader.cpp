#include <iostream>
#include <time.h>
using namespace std;


int wait(struct timespec ts) {
  fflush(stdout);
  nanosleep(&ts,NULL);
  return 0;
}

int main() {

  int moveback;
  int characters;
  int writeChars;

  struct timespec ts;
  ts.tv_nsec=20000000;
  ts.tv_sec=0;
  
  cout << "Loading...   ";
  characters = 15;
  for (writeChars = 0; writeChars < characters; writeChars++) {
    cout << "|";
    wait(ts);
  }
  cout << "\033[s";
  nanosleep(&ts,NULL);
  for (writeChars = 0; writeChars < characters; writeChars++) {
    moveback = writeChars-1;
    printf("\033u\033[%dD\\", moveback);
    wait(ts);
  }

  cout << "\n";
  

  return 0;
}


/*
int pipes=11;

  //begin pipe setup
  printf(" ");
  for (i=0; i<pipes+1; i++) {
    printf("| ");
    sleep(2);
  }

  //begin animation
  for (i=0; i<pipes+1; i++) {
    printf("\033[7");
  }
  printf("\n");


*/