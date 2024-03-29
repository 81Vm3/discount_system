#include "DiscountSystem.hpp"

User::User(unsigned int id, std::string name) {
	this->userid = id;
	this->name = name;
}
unsigned int User::UserID() {
	return userid;
}
std::string User::Name() {
	return name;
}
std::string User::Password() {
	return password;
}

void User::f()
{
}
