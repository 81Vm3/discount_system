#include "DiscountSystem.hpp"

StudentUser::StudentUser(unsigned int id, std::string name) : User(id, name) {}

void StudentUser::GetDiscount() {
	
	using namespace std;

	Activity *activity = DiscountSystem::getInstance().GetRandomActivity();
	if (!activity) {
		cout << "No activity found! Failed to get discount!" << endl;
		return;
	}
	
	activity->GiveAway(this);
	cout << name << " received a coupon from activity " << *activity << endl;
}

void StudentUser::CheckDiscount() {
	VCoupon *v = DiscountSystem::getInstance().GetUserCoupons(this);
	if (v) {
		std::cout << name << " has " << v->size() << " coupons:" << std::endl;
	}
	else {
		std::cout << "No coupons found.";
	}
}

float StudentUser::Pay(float amount) {
	return DiscountSystem::getInstance().GetDiscount(this, amount);
}
