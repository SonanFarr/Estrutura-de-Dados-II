#include <iostream>
#include "../headers/review.h"

using namespace std;

int main() {

  Review* r = new Review();

  r->iniciar();
  
  delete r; // don't remove this line (may cause memory leak)
}