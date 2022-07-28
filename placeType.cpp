#include "placeType.h"

// compare overloading
bool PlaceType::operator == (const PlaceType& data) {
	if (this->p_name == data.p_name) {
		return true;
	}
	else
		return false;
}
bool PlaceType::operator > (const PlaceType& data) {
	if (this->p_name > data.p_name) {
		return true;
	}
	else
		return false;
}
bool PlaceType::operator < (const PlaceType& data) {
	if (this->p_name < data.p_name) {
		return true;
	}
	else
		return false;
}