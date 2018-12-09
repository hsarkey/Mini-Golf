//project.cpp
//Lab 12 Main Program
//Isobel Murrer and Hannah Sarkey

#include "golf.h"

int main() {
	Golf h1;
	bool loop = true;
	bool win  = false;
	bool directions = true;
	bool windisplay = true;
	char c, d, f;

	gfx_open(600, 800, "Putt Putt");

		 gfx_clear();
		 h1.resetplacements(); // resets ball if user plays again

		 while (directions) { // message screen for directions
			 gfx_color(170, 184, 255);
			 char font[] = "9x15"; // set new font size
			 gfx_changefont(font);
			 gfx_text(190, 350, "Welcome to Mini-Golf!");
			 gfx_text(80, 375, "Click to adjust the direction and speed of your ball.");
			 gfx_text(145, 400, "A blue line will be shown to guide you."); 
			 gfx_text(140, 425, "Hit space bar when you are ready to putt.");
			 gfx_text(165, 650, "If you are ready to play, hit 'p'!");
			 gfx_text(165, 675, "If you want to quit, hit 'q'.");
			 if (gfx_event_waiting()) {
				 c= gfx_wait();
				 if (c=='p') { // user plays
					 break;
				 }
				 if (c=='q') {
					 goto END; // user quits
				 }  
			 }
		 }
		 while (loop) { // start user play
			 h1.display();
			 h1.rotateMill();
			 h1.displayarrow();
			 if (gfx_event_waiting()) { // waits for user direction
				 c = gfx_wait();
				 if (c== 1) { //user decides to click to change direction of ball
					 h1.changearrow(c);
					 c = gfx_wait();
				 }
				 if (c== 32) { //space bar to release ball
					 win = h1.releaseball();
					 if(win) // if user wins go to end screen
						 goto END;
					 c = gfx_wait();
				 }
				 if (c == 'q') { // user quit, get rid of screen
					 break;
				 }
			 }
			 gfx_flush();
			 usleep(30000);
			 gfx_clear();
		 }
END: {}
	  if (win) { // if user wins display a new message
		  h1.displayinhole();
		  usleep(40000);
		  gfx_clear();
		  while (windisplay) {
			  gfx_color(170, 184, 255);
			  gfx_text(275, 400, "WINNER!");
			  gfx_text(225, 700, "Hit 'a' to play again.");
			  gfx_text(225, 725, "Hit 'q' to quit.");
			  if (gfx_event_waiting()) {
				  c = gfx_wait();
				  if (c=='a') { // if user decides to play again
					  goto BEGIN; 
				  }
				  if (c =='q') {
					  break;
				  }
			  }
		  }
	  }
}
