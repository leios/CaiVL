# Makefile for general visualization

CXX = g++
#CXXFLAGS = -std=c++11 -g -Wall -march=native -fopenmp -fno-omit-frame-pointer -O2 -flto -Wno-sign-compare -fsanitize=address
CXXFLAGS = -std=c++11 -g -Wall -march=native -fopenmp -O2 -fno-omit-frame-pointer -flto -Wno-sign-compare

CAIROFLAGS = `pkg-config --cflags --libs cairo`
BINS = vis_test
OBJ = vis_test.o cairo_vis.o frame_functions.o
DEPS = include/cairo_vis.h include/vec.h include/frame_functions.h

$(BINS): $(OBJ)
	$(CXX) $(CXXFLAGS) $(CAIROFLAGS) -o $(BINS) $^
	#./vis_test
	#convert -delay 5 -loop 0 /tmp/*.png frames/animation.gif

cairo_vis.o: src/cairo_vis.cpp $(DEPS)
	$(CXX) $(CXXFLAGS) $(CAIROFLAGS) -c -o $@ $<

%.o: src/%.cpp $(DEPS)
	$(CXX) $(CXXFLAGS) $(CAIROFLAGS) -c -o $@ $<

clean:
	rm -Rf $(BINS) $(OBJ) file*

