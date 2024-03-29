#include "DiscountSystem.hpp"

DiscountCoupon::DiscountCoupon(int id, int lim, float discount_factor) : Coupon(id) {
	this->lim = lim;
	this->factor = discount_factor;
}

float DiscountCoupon::calculate(float pay) {
	return pay >= lim ? pay * factor : pay;
}

float DiscountCoupon::Factor() {
	return factor;
}

float DiscountCoupon::Lim() {
	return lim;
}