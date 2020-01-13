#ifndef GRAPHICSDISPLAY_H
#define GRAPHICSDISPLAY_H
#include "observer.h"
#include "subject.h"
#include "state.h"
#include "info.h"
#include "window.h"

class GraphicsDisplay: public Observer<Info, State> {
	int rectSize;
	Xwindow w;

 public:
  GraphicsDisplay(size_t n);
  void notify(Subject<Info, State> &whoNotified) override;
};
#endif
