// classes example
#include <iostream>
using namespace std;

class Rectangle {
   float width, height;
 public:
   void set_values (int,int);
   int area()
   {return width+height;}
   float time()
   {return width/height+width;}
};

void Rectangle::set_values (int x, int y) {
 width = x;
 height = y;
}

int main () {
 Rectangle rect;
 rect.set_values (3,4);
 Rectangle funk;
 funk.set_values(22,51);
 cout << "area: " << rect.area()<< endl;
 cout << "time: " << rect.time()<< endl;
 cout << "area: " << funk.area()<< endl;
 cout << "time: " << funk.time()<< endl;
 return 0;
}
