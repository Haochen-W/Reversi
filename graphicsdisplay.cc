#include "graphicsdisplay.h"

GraphicsDisplay::GraphicsDisplay(size_t n): rectSize{500/static_cast<int>(n)} {
	for(int i = 0; i < 500; i += 500/n){
		for(int j = 0; j < 500; j += 500/n){
			w.fillRectangle(j, i, rectSize - 2, rectSize - 2, Xwindow::Blue);
		}
	}
}

void GraphicsDisplay::notify(Subject<Info, State> &whoNotified){
	Info c = whoNotified.getInfo();
	if (c.colour == Colour::Black){
		w.fillRectangle(c.col * rectSize, c.row * rectSize, rectSize - 2, rectSize - 2, Xwindow::Black);
	} else if (c.colour == Colour::White){
		w.fillRectangle(c.col * rectSize, c.row * rectSize, rectSize - 2, rectSize - 2, Xwindow::White);
	} 
}
