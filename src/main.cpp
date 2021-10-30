#include <iostream>
#include "../headers/review.h"

using namespace std;

int main() {

  cout << "Hello" << endl;

  Review* r = new Review();

  r->teste();
  
  delete r; // don't remove this line (may cause memory leak)
}