//main.cpp
// Bella Murrer and Hannah Sarkey

#include "gfx3.h"
#include <iostream>
using namespace std;

int main() {
  bool loop = true;
  char c;
  gfx_open(600, 800, "Putt Putt");
  
  while (loop) {
    //switch(c) {
     //   case 
      
    float bx = 100, by = 550;
    float mx = 200, my = 250;
    float tx = 100, ty = 50;
    float l = 400, w = 200;
    float ml = 300, mw = 200;
    float hx= 287.5 , hy= 530 , hl = 25, hw = 20, a1 =0, a2 =180;
    
    gfx_color(29, 147, 41); // green course
    gfx_fill_rectangle(tx, ty, l, w);
    gfx_fill_rectangle(mx, my, mw, ml);
    gfx_fill_rectangle(bx, by, l, w);
    
    gfx_color(0, 0, 0); // hole arc & hole
    gfx_fill_arc(hx, hy, hw, hl, a1, a2);
    gfx_circle(150, 100, 10);

    gfx_color(0,43,4); // dropoff line
    gfx_line(200, 250, 400 , 250);
    
      if (gfx_event_waiting()) {
       c = gfx_wait();
       if (c == 'q') {
       break;
       }
     }
  }
}
    
    
