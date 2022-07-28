#include "memberType.h"

// compare overloading
bool MemberType::operator == (const MemberType& data) {
	if (this->m_name == data.m_name) {
		return true;
	}
	else
		return false;
}
bool MemberType::operator > (const MemberType& data) {
	if (this->m_name > data.m_name) {
		return true;
	}
	else
		return false;
}
bool MemberType::operator < (const MemberType& data) {
	if (this->m_name < data.m_name) {
		return true;
	}
	else
		return false;
}