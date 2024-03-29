#include "DiscountSystem.hpp"

AdminUser::AdminUser(unsigned int id, std::string name) : User(id, name) {}

bool AdminUser::CreateActivity(Coupon* coupon, int num, int deadline, DiscountMode mode, std::string identifier) {
	Activity* activity = DiscountSystem::getInstance().CreateActivity(coupon, num, deadline, mode, identifier);
	if (activity) {
		std::cout << "[ACT] Admin " << name << " created an activity " << *activity << std::endl;
		return true;
	}
	std::cout << "[ERROR] Cannot create activity" << std::endl;
	return false;
}