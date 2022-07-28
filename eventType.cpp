#include "eventType.h"

// compare overloading
bool EventType::operator == (const EventType& data) {
	if (this->e_name == data.e_name) {
		return true;
	}
	else
		return false;
}
bool EventType::operator > (const EventType& data) {
	if (this->e_name > data.e_name) {
		return true;
	}
	else
		return false;
}
bool EventType::operator < (const EventType& data) {
	if (this->e_name < data.e_name) {
		return true;
	}
	else
		return false;
}