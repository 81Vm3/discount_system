#include <iostream>
#include "DiscountSystem.hpp"

int main() {
	
	using namespace std;

	DiscountSystem &s = DiscountSystem::getInstance();

	DiscountCoupon coupon1(0, 100, 0.8f);
	CashCoupon coupon2(1, 200, 50);

	AdminUser* admin = s.GetAdmin();
	admin->CreateActivity(
		&coupon1,
		16, 1, Factor, "²âÊÔ»î¶¯");

	admin->CreateActivity(
		&coupon2,
		16, 1, Cash, "VÎÒ50");
	
	StudentUser* me = s.AddStudent(10, "Brian");
	me->GetDiscount();
	me->GetDiscount();
	me->GetDiscount();

	StudentUser* m2 = s.AddStudent(11, "miku");
	m2->GetDiscount();
	m2->GetDiscount();
	m2->GetDiscount();
	m2->GetDiscount();
	m2->GetDiscount();

	me->CheckDiscount();
	m2->CheckDiscount();

	me->Pay(200);
	me->Pay(200);
	me->Pay(500);
	me->Pay(10);
	me->Pay(999);
	return 0;
}