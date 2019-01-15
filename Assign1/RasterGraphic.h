//RasterGraphic.h
#pragma once
class RasterGraphic
{
	GraphicElement* GraphicElements;

public:
	RasterGraphic();
	~RasterGraphic() { delete GraphicElements; } // inline
	void InsertGraphicElement();
	void DeleteGraphicElement();
	void ReportRasterGraphic();
};

