#ifndef DISCOUNT_SYSTEM_HPP
#define DISCOUNT_SYSTEM_HPP

#include <iostream>
#include <chrono>
#include <iomanip>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>


#include "DiscountMode.hpp"

#include "User.hpp"
#include "StudentUser.hpp"
#include "AdminUser.hpp"
#include "Activity.hpp"

#include "Coupon.hpp"
#include "DiscountCoupon.hpp"
#include "CashCoupon.hpp"
#include "CouponSorter.hpp"

class DiscountSystem {
private:

	std::vector<std::unique_ptr<User>> users;
	std::vector<Activity> activity;

	std::map<User*, VCoupon> userCoupon;
	std::set<User*> onlineUsers;

	DiscountSystem();

	DiscountSystem(const DiscountSystem&) = delete;
	DiscountSystem& operator=(const DiscountSystem&) = delete;

public:
	static DiscountSystem& getInstance();

	bool Login(User* user, std::string password);
	bool Login(unsigned int id, std::string password);
	bool Login(std::string name, std::string password);

	Activity* CreateActivity(Coupon* coupon, int num, int deadline, DiscountMode mode, std::string identifier);
	void GiveCoupon(Coupon *c, User* user);

	Activity* GetRandomActivity();

	StudentUser* AddStudent(unsigned int id, std::string name);
	AdminUser* GetAdmin();

	VCoupon* GetUserCoupons(User* user);
	float GetDiscount(User* user, float num);
};

#endif