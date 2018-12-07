//golf.cpp
//Bella Murrer and Hannah Sarkey

#include "golf.h"

Golf::Golf() {
   ballx = 300, bally = 740, ballrad = 7.5;
   bx = 100, by = 550;
   mx = 200, my = 250;
   tx = 100, ty = 50;
   l = 400, w = 200;
   ml = 300, mw = 200;
   hx= 287.5 , hy= 537.5 , hl = 25, hw = 20, a1 =0, a2 =180;
   millcentX = 300, millcentY = 400, triX1 = 270, triY1 = 250, triX2 = 330, triY2 = 250;
   radmill = pow(pow(millcentX-triX2, 2)+pow(millcentY-triY2, 2), .5);
   angmill = asin((millcentX-triX2)/radmill);
   arrowx = 300, arrowy =675;
}

Golf::~Golf() { }

void Golf::display() {
   gfx_color(29, 147, 41); // green course
    gfx_fill_rectangle(tx, ty, l, w);
    gfx_fill_rectangle(mx, my, mw, ml);
    gfx_fill_rectangle(bx, by, l, w);
    
    //Ms. Ball
    gfx_color(255, 255, 255);
    gfx_fill_circle(ballx, bally, ballrad);
       
    gfx_color(170, 184, 255);  //the windmill herself
    gfx_fill_rectangle(250, 400, 100, 150);
    XPoint pt = {200, 550};
    XPoint mypoints1[] = { {200, 550}, {250, 400}, {250, 550} };
    XPoint mypoints2[] = { {350, 550}, {350, 400}, {400, 550} };
    int size1 = sizeof(mypoints1)/sizeof(pt);
    gfx_fill_polygon(mypoints1, size1);
    gfx_fill_polygon(mypoints2, size1);
    
    gfx_color(0, 0, 0); // hole arc & hole
    gfx_fill_arc(hx, hy, hw, hl, a1, a2);
    gfx_fill_circle(150, 100, 10);

    gfx_color(0,43,4); // dropoff line
    gfx_line(200, 250, 400 , 250);
}


void Golf::rotateMill() {
  //first top triangle
  XPoint pt = {(short)millcentX, (short)millcentY};
  XPoint mypoints1[] = { {(short)millcentX, (short)millcentY}, {(short)triX1, (short)triY1}, {(short)triX2, (short)triY2} };
  int size1 = sizeof(mypoints1)/sizeof(pt);
  gfx_color(192, 242, 247);
  gfx_fill_polygon(mypoints1, size1);
  angmill+=M_PI/6;
  triX1 = triX1-(radmill*(cos(angmill-M_PI/6)-cos(angmill)));
  triY1 = triY1+(radmill*(sin(angmill-M_PI/6)-sin(angmill)));
  triX2 = triX2+(radmill*(cos(angmill-M_PI/6)-cos(angmill)));
  triY2 = triY2-(radmill*(sin(angmill-M_PI/6)-sin(angmill)));
}

void Golf::displayarrow() {
   gfx_color(24, 60, 242);
   gfx_line(ballx, bally, arrowx, arrowy);
}

void Golf::changearrow(char c){  
   while (true) {	
      if (c== ‘R’) { //up
         if (arrowy > 600) {
 	        arrowy = arrowy -5;
         }
      }
      if (c == ’S’) { //down
          if (arrowy < 735) {
            arrowy = arrowy +5;
          }
       }
      if (c == ’T’) {  //left
          if (arrowx > 200) {
            arrowx = arrowx -5;
          }
      }
      if (c==‘Q’) { //right
         if (arrowx < 400) {
            arrowx = arrow +5;
         }
      }
      if (c==32) { //release
         // releaseball();
          break;
       }
      gfx_line(ballx, bally, arrowx, arrowy);
      c= gfx_wait();
      }
}
/*
bool Golf::throughMill() {
  
}

float Golf::ballAngle() {

}

float Golf::ballSpeed() {

}*/


