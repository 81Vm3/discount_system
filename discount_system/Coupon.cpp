#include "DiscountSystem.hpp"

Coupon::Coupon(int id) {
	this->id = id;
}
int Coupon::Id() { return id; }

float Coupon::calculate(float pay)
{
	return 0.0f;
}
