#pragma once
#include "field.h"

template<int width =30, int height = 30>

class FieldSize {
public:
	void operator()(Field* field) {
		if (height < 1 || width < 1) {
			field->resizeField(30, 30);
		}
		else {
			field->resizeField(width, height);
		}
	}
};