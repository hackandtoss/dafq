#define cimg_display 0
#include "CImg.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace cimg_library;
using namespace std;


//This will dump the contents of an image file to the screen
//Useful for debugging your code
void print_image(unsigned char in[], int width, int height) {
	for (int i = 0; i < width * height * 3; i++)
		cout << (unsigned int) in[i] << endl;
}

//Globals for our current image
int width = 0;
int height = 0;
int stride = 0; //width*height

//These are helper functions that will return the red, green, or blue value at
// any given location, or allow you to set the value there as well.
//We're accessing a 1D array as if it was a 3D array

int R(int i, int j) {
	return j * width + i;
}
int G(int i, int j) {
	return stride + j * width + i;
}
int B(int i, int j) {
	return stride + stride + j * width + i;
}

CImg <unsigned char> temp("mandalore.jpg"); 
CImg <unsigned char> bg(temp.height(), temp.width(), 1, 3, 0); 

void set_water(unsigned char in[], unsigned char out[], int x_min, int y_min, int x_max, int y_max) {
	for (int i = x_min; i <= x_max; i++) {
		for (int j = y_min; j <= y_max; j++) {
			if (in[R(i, j)] != 0xFF && in[G(i, j)] != 0xFF && in[B(i, j)] == 0xFF) {
				out[R(i,j)] = in[R(i, j)];
				out[B(i,j)] = in[B(i, j)];
				out[G(i,j)] = in[G(i, j)];
			}
		}
	}
}

void set_rekt(unsigned char out[], int x_min, int y_min, int x_max, int y_max) {
	for (int i = x_min; i <= x_max; i++) {
		for (int j = y_min; j <= y_max; j++) {
			out[R(i,j)] = 0;
			out[G(i,j)] = 0;
			out[B(i,j)] = 0;
		}
	}
}
/* Gradient code
   unsigned int new_r = (unsigned int)in[R(i,j)];
   float percentage = float(i)/width;
   new_r += percentage * 255;
   if (new_r > 255) new_r = 255;
   out[R(i,j)] = new_r;
   out[G(i,j)] = in[G(i,j)];
   out[B(i,j)] = in[B(i,j)];
   */

//This code will darken the image by 50%
/*
   void colorize(unsigned char in[], unsigned char out[]) {
//Note: i is the x coordinate, j is the y coordinate
for (int i = 0; i < width; i++) {
for (int j = 0; j < height; j++) { //At each pixel...
int how_blue = in[B(i,j)];
if (how_blue > 100) {
int temp_r = in[R(i, j)] + 50; 
int temp_g = in[G(i, j)] + 50 ; 
int temp_b = in[B(i, j)]; 
if (temp_r > 255) temp_r = 255; //Saturating arithmetic
if (temp_g > 255) temp_g = 255; //Saturating arithmetic
if (temp_b > 255) temp_b = 255; //Saturating arithmetic
out[R(i, j)] = temp_r;
out[G(i, j)] = temp_g;
out[B(i, j)] = temp_b;
}
else {
int average = (in[R(i,j)] + in[G(i,j)] + in[B(i,j)]) / 3;
double percentage = how_blue / 100.0;
int temp_r = average + 50 * percentage; 
int temp_g = average + 50 * percentage;
int temp_b = average;
if (temp_r > 255) temp_r = 255; //Saturating arithmetic
if (temp_g > 255) temp_g = 255; //Saturating arithmetic
if (temp_b > 255) temp_b = 255; //Saturating arithmetic
out[R(i, j)] = temp_r;
out[G(i, j)] = temp_g;
out[B(i, j)] = temp_b;
}
}
}
}
*/

//This code will darken the image by 50%
void vegnette(unsigned char in[], unsigned char out[]) {
	//Note: i is the x coordinate, j is the y coordinate
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) { //At each pixel...
			//Vignette Effectv
			int center_x = width/2;
			int center_y = height/2;
			double distance = sqrt(pow(i-center_x,2)+pow(j-center_y,2));
			double max_distance = sqrt(pow(center_x,2)+pow(center_y,2));
			double scaling_factor = 2 - 2*(distance / max_distance);
			int temp_r = in[R(i, j)] * scaling_factor;
			int temp_g = in[G(i, j)] * scaling_factor;   
			int temp_b = in[B(i, j)] * scaling_factor;   
			if (temp_r > 255) temp_r = 255; //Saturating arithmetic 
			if (temp_g > 255) temp_g = 255;
			if (temp_b > 255) temp_b = 255;
			out[R(i, j)] = temp_r;
			out[G(i, j)] = temp_g;
			out[B(i, j)] = temp_b;
			//}
	}
}
return;
}

//This code will darken the image by 50%
void dark(unsigned char in[], unsigned char out[]) {
	//Note: i is the x coordinate, j is the y coordinate
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) { //At each pixel...
			out[R(i, j)] = in[R(i, j)] / 2; //Decrease red by 50%  
			out[G(i, j)] = in[G(i, j)] / 2; //Decrease green by 50%
			out[B(i, j)] = in[B(i, j)] / 2; //Decrease blue by 50%  
		}
	}
	return;
}

void thresh_mono(unsigned char in[], unsigned char out[], unsigned char threshold) {
	//temp.resize_halfXY();
	//bg.draw_image(20, 100, temp);
	//set_water(bg, out, 1, 1, bg.height() - 1, bg.width() - 1);
	//Note: i is the x coordinate, j is the y coordinate
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) { //At each pixel...
			if (in[R(i,j)] > threshold) { 
				out[R(i, j)] = in[R(i, j)];   
				out[G(i, j)] = in[G(i, j)];   
				out[B(i, j)] = in[B(i, j)];   
			}
			else {
				unsigned int brightness = (unsigned int)in[R(i,j)];
				brightness += in[G(i,j)];
				brightness += in[B(i,j)];
				brightness /= 3;
				out[R(i,j)] = brightness;
				out[G(i,j)] = brightness;
				out[B(i,j)] = brightness;
			}
		}
	}
	/*
	   auto w = width / 16;
	   auto h = height / 2;
	   set_rekt(out, w,h, w + 50, h + 25);
	   */


	return;
}

void colorize(unsigned char in[], unsigned char out[], unsigned char threshold, string c) {
	//Note: i is the x coordinate, j is the y coordinate
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) { //At each pixel...
			if (c == "green") {
				if (in[R(i,j)] > threshold) { 
					out[R(i, j)] = in[R(i, j)];   
					out[G(i, j)] = in[G(i, j)];   
					out[B(i, j)] = in[B(i, j)];   
				}
				else {
					unsigned int brightness = (unsigned int)in[R(i,j)];
					//brightness += in[G(i,j)];
					brightness += in[B(i,j)];
					brightness /= 2;
					out[R(i,j)] = brightness;
					//out[G(i,j)] = in[B(i, j)];
					//out[G(i,j)] = in[B(i, j)] % 100;
					out[G(i,j)] = in[G(i, j)] % 100;
					out[B(i,j)] = brightness;
				}
			}
			if (c == "blue") {
				if (in[R(i,j)] > threshold) { 
					out[R(i, j)] = in[R(i, j)];   
					out[G(i, j)] = in[G(i, j)];   
					out[B(i, j)] = in[B(i, j)];   
				}
				else {
					unsigned int brightness = (unsigned int)in[R(i,j)];
					brightness += in[G(i,j)];
					//brightness += in[B(i,j)];
					brightness /= 2;
					out[R(i,j)] = brightness;
					//out[B(i,j)] = in[B(i, j)];
					out[B(i,j)] = in[B(i, j)] % 100;
					out[G(i,j)] = brightness;
				}
			}
			if (c == "red") {
				if (in[R(i,j)] > threshold) { 
					out[R(i, j)] = in[R(i, j)];   
					out[G(i, j)] = in[G(i, j)];   
					out[B(i, j)] = in[B(i, j)];   
				}
				else {
					unsigned int brightness = (unsigned int)in[B(i,j)];
					brightness += in[G(i,j)];
					brightness /= 2;
					out[B(i,j)] = brightness;
					out[R(i,j)] = in[R(i, j)] % 100;
					out[G(i,j)] = brightness;
				}
			}
		}
	}
	return;
}

void usage() {
	cout << "Error: this program needs to be called with a command line parameter indicating what file to open.\n";
	cout << "For example, a.out kyoto.jpg\n";
	exit(1);
}

int main(int argc, char **argv) {
	if (argc != 2) usage(); //Check command line parameters

	//PHASE 1 - Load the image
	clock_t start_time = clock();
	CImg<unsigned char> image(argv[1]);
	temp.resize_halfXY();
	image.draw_image(20, 100, temp, .5);
	string filename = argv[1];
	width = image.width(); //Set the globals
	height = image.height();
	stride = width * height;
	CImg<unsigned char> darkimage(image.width(), image.height(), 1, 3, 0);
	CImg<unsigned char> sepia_image(image.width(), image.height(), 1, 3, 0);
	//If you want to make an animated gif, use this:
	CImgList<unsigned char> harambe(0,image.width(), image.height(), 1, 3);
	clock_t end_time = clock();
	cerr << "Image load time: " << double (end_time - start_time) / CLOCKS_PER_SEC << " secs\n";

	//PHASE 2 - Darken the image
	start_time = clock();
	//This is how you make an animated gif
	// blw
	for (int i = 0; i < 512; i = i + 10) {
		int thresh = i;
		if (thresh >= 256) thresh = 512 - thresh;
		thresh_mono(image, darkimage, thresh);
		harambe.push_back(darkimage);
	}
	// green?
	for (int i = 0; i < 512; i = i + 10) {
		int thresh = i;
		if (thresh >= 256) thresh = 512 - thresh;
		colorize(image, darkimage, thresh, "green");	
		harambe.push_back(darkimage);
	}
	// blue?
	for (int i = 0; i < 512; i = i + 10) {
		int thresh = i;
		if (thresh >= 256) thresh = 512 - thresh;
		colorize(image, darkimage, thresh, "blue");	
		harambe.push_back(darkimage);
	}
	/*
	// red?
	for (int i = 0; i < 512; i = i + 10) {
		int thresh = i;
		if (thresh >= 256) thresh = 512 - thresh;
		colorize(image, darkimage, thresh, "red");	
		harambe.push_back(darkimage);
	}
	*/
	end_time = clock();
	cerr << "Thresh_mono time: " << double (end_time - start_time) / CLOCKS_PER_SEC << " secs\n";

	//PHASE 3 - Write the image
	start_time = clock();
	filename = filename + ".gif";
	harambe.save_gif_external(filename.c_str(), 25, 0); //Animated gif a
	end_time = clock();
	cerr << "Image write time: " << double (end_time - start_time) / CLOCKS_PER_SEC << " secs\n";
}


/*
//This code will darken the image by 50%
void dark(unsigned char in[], unsigned char out[]) {
//Note: i is the x coordinate, j is the y coordinate
for (int i = 0; i < width; i++) {
for (int j = 0; j < height; j++) { //At each pixel...
out[R(i, j)] = in[R(i, j)] / 2; //Decrease red by 50%  
out[G(i, j)] = in[G(i, j)] / 2; //Decrease green by 50%
out[B(i, j)] = in[B(i, j)] / 2; //Decrease blue by 50%  
}
}
return;
}

//This filter is a placeholder - it just copies the input image to the output image
void copy(unsigned char *in, unsigned char *out) {
const int stride = width * height;
for (int i = 0; i < width; i++) {
for (int j = 0; j < height; j++) {
out[R(i, j)] = in[R(i,j)] * 1;  
out[G(i, j)] = in[G(i,j)] * 1;
out[B(i, j)] = in[B(i,j)] * 1;
}
}
return;
}
*/
/*
//This code will darken the image by 50%
void colorize(unsigned char in[], unsigned char out[]) {
//Note: i is the x coordinate, j is the y coordinate
for (int i = 0; i < width; i++) {
for (int j = 0; j < height; j++) { //At each pixel...
int how_blue = in[B(i,j)];
if (how_blue > 100) {
int temp_r = in[R(i, j)] + 50; 
int temp_g = in[G(i, j)] + 50 ; 
int temp_b = in[B(i, j)]; 
if (temp_r > 255) temp_r = 255; //Saturating arithmetic
if (temp_g > 255) temp_g = 255; //Saturating arithmetic
if (temp_b > 255) temp_b = 255; //Saturating arithmetic
out[R(i, j)] = temp_r;
out[G(i, j)] = temp_g;
out[B(i, j)] = temp_b;
}
else {
int average = (in[R(i,j)] + in[G(i,j)] + in[B(i,j)]) / 3;
double percentage = how_blue / 100.0;
int temp_r = average + 50 * percentage; 
int temp_g = average + 50 * percentage;
int temp_b = average;
if (temp_r > 255) temp_r = 255; //Saturating arithmetic
if (temp_g > 255) temp_g = 255; //Saturating arithmetic
if (temp_b > 255) temp_b = 255; //Saturating arithmetic
out[R(i, j)] = temp_r;
out[G(i, j)] = temp_g;
out[B(i, j)] = temp_b;
}
}
}
}
*/
/*
//This code will darken the image by 50%
void vegnette(unsigned char in[], unsigned char out[]) {
//Note: i is the x coordinate, j is the y coordinate
for (int i = 0; i < width; i++) {
for (int j = 0; j < height; j++) { //At each pixel...
//Vignette Effectv
int center_x = width/2;
int center_y = height/2;
double distance = sqrt(pow(i-center_x,2)+pow(j-center_y,2));
double max_distance = sqrt(pow(center_x,2)+pow(center_y,2));
double scaling_factor = 2 - 2*(distance / max_distance);
int temp_r = in[R(i, j)] * scaling_factor;
int temp_g = in[G(i, j)] * scaling_factor;   
int temp_b = in[B(i, j)] * scaling_factor;   
if (temp_r > 255) temp_r = 255; //Saturating arithmetic 
if (temp_g > 255) temp_g = 255;
if (temp_b > 255) temp_b = 255;
out[R(i, j)] = temp_r;
out[G(i, j)] = temp_g;
out[B(i, j)] = temp_b;
//}
}
}
return;
}
*/
