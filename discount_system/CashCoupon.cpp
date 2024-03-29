#include "DiscountSystem.hpp"

CashCoupon::CashCoupon(int id, float lim, float amount) : Coupon(id) {
	this->lim = lim;
	this->amount = amount;
}

float CashCoupon::calculate(float pay) {
	return pay >= lim ? pay - amount : pay;
}

float CashCoupon::Amount() {
	return amount;
}

float CashCoupon::Lim() {
	return lim;
}