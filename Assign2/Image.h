// Image.h
#pragma once

class Image
{
	int pixel_x;
	int pixel_y;
	int duration;
	char* name;
public:
	Image(int x, int y, int duration, char* name);
	Image(const Image&);
	~Image();
	friend ostream& operator<<(ostream&, Image&);
};