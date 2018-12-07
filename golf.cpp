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
   angmill1 = acos((triX2-millcentX)/radmill);
   angmill2 = angmill1+2*atan((triX2-triX1)*.5/radmill);
   arrowx = 300, arrowy =675;
   radline =pow(pow(arrowx-ballx, 2) + pow(arrowy-bally,2), 0.5), angline = M_PI/2;
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
  angmill1+=M_PI/6;
  angmill2+=M_PI/6;
  triX1 = triX1+(radmill*(cos(angmill1-M_PI/6)-cos(angmill1)));
  triY1 = triY1+(radmill*(sin(angmill1-M_PI/6)-sin(angmill1)));
  triX2 = triX2+(radmill*(cos(angmill2-M_PI/6)-cos(angmill2)));
  triY2 = triY2+(radmill*(sin(angmill2-M_PI/6)-sin(angmill2)));
}

void Golf::displayarrow() {
   gfx_color(24, 60, 242);
   gfx_line(ballx, bally, arrowx, arrowy);
}

void Golf::changearrow(char c){  
      //display();
      //rotateMill();
      if (c == 'R') { //up
         if (arrowy > 600) {
           if (angline != (M_PI/2)) 
           arrowx = arrowx+5*(cos(angline));
           else 
           arrowy = arrowy-5;  
         }
      }
      if (c == 'Q') { //left
          if (arrowx > 200) {
            angline = angline + (M_PI/16);
            arrowx = arrowx+(radline)*cos(angline);
            arrowy = arrowy+(radline)*sin(angline - (M_PI/16))- radline*sin(angline);
          }
       }
      if (c == 'S') {  //right
          if (arrowx < 400) {
             angline = angline - (M_PI/16);
             arrowx = arrowx+(radline)*cos(angline);
             arrowy = arrowy+(radline)*sin(angline+ (M_PI/16)) - radline*sin(angline);
          }
      }
      if (c == 'T') { //down
         if (arrowy < 735) {
            if (angline != (M_PI/2))
              arrowx = arrowx+5*(cos(angline));
            else
              arrowy = arrowy-5;
         }
      }
      if (c==32) { //release
         // releaseball();
       }
      gfx_line(ballx, bally, arrowx, arrowy);
      gfx_flush();
     // usleep(70000);
     // gfx_clear();
 }

void Golf::releaseball() {
   while (true) {
      ballx = ballx+ (radline * 0.85);
      bally = bally + (radline * 0.85);
   if ((ballx <=0) || (bally <=0))
      break;
   if (ballx >= 500-ballrad) 
      ballx = -ballx;
   if (ballx <= 100+ballrad)
      ballx = -ballx;
   if (bally <= 550+ballrad)
      bally = -bally;
   if (bally >= 750 - ballrad)
      bally=-bally;
}
   usleep(70000);
   gfx_clear();
}

bool Golf::throughMill() {
  if ((ballx >298) && (ballx < 302)) {
    if ((bally+rad > 537.5) && (bally-rad < 550)) {
       return true;
    }
  }
  else 
    return false;
}



