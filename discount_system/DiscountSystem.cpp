#include "DiscountSystem.hpp"

DiscountSystem::DiscountSystem() {
	std::srand(std::time(nullptr));

	unsigned int id;
	std::string name;
	std::cout << "Admin not found, please create an admin account:" << std::endl;

	std::cout << "ID: ";
	std::cin >> id;

	std::cin.ignore();
	std::cout << "Name: ";
	std::getline(std::cin, name);

	users.emplace_back(std::make_unique<AdminUser>(id, name));
	onlineUsers.insert((AdminUser*)&users.front());

	std::cout << "Admin " << name << '(' << id << ')' << " created" << std::endl;
}

DiscountSystem& DiscountSystem::getInstance() {
	static DiscountSystem instance; // Guaranteed to be destroyed and instantiated on first use.
	return instance;
}

bool DiscountSystem::Login(User* user, std::string password) {
	if (user->Password() == password) {
		std::cout << "Login as " << user->Name() << std::endl;
		onlineUsers.insert(user);

		return true;
	}
	else {
		std::cout << "Error: Unauthorized login";
		return false;
	}
}

bool DiscountSystem::Login(unsigned int id, std::string password) {
	for (auto& it : users) {
		if (it->UserID() == id) {
			return Login(it.get(), password);
		}
	}
	std::cout << "Error: User " << id << " was not found in database";
	return false;
}

bool DiscountSystem::Login(std::string name, std::string password) {
	for (auto& it : users) {
		if (it->Name() == name) {
			return Login(it.get(), password);
		}
	}
	std::cout << "Error: User " << name << " was not found in database";
	return false;
}

Activity* DiscountSystem::CreateActivity(Coupon* coupon, int num, int deadline, DiscountMode mode, std::string identifier) {
	activity.emplace_back(coupon, num, deadline, mode, identifier);
	return &activity.back();
}

Activity* DiscountSystem::GetRandomActivity() {
	if (!activity.size())
		return nullptr;

	int r = std::rand() % (activity.size());
	return &activity[r];
}

void DiscountSystem::GiveCoupon(Coupon *c, User* user) {
	if (!user)
		return;

	DiscountCoupon* p1 = dynamic_cast<DiscountCoupon*>(c);
	if (p1) {
		userCoupon[user].push_back(std::make_unique<DiscountCoupon>(*p1));
	}
	else {
		CashCoupon* p2 = dynamic_cast<CashCoupon*>(c);
		if (p2) {
			userCoupon[user].push_back(std::make_unique<CashCoupon>(*p2));
		}
	}
}

StudentUser* DiscountSystem::AddStudent(unsigned int id, std::string name) {
	users.emplace_back(
		std::make_unique<StudentUser>(
			id, name
		)
	);
	return dynamic_cast<StudentUser*>(users.back().get());
}

AdminUser* DiscountSystem::GetAdmin() {
	AdminUser* r = nullptr;

	for (auto& it : users) {
		r = dynamic_cast<AdminUser*>(it.get());
		if (r != nullptr) {
			break;
		}
	}
	return r;
}

VCoupon* DiscountSystem::GetUserCoupons(User* user) {
	return &userCoupon[user];
}

float DiscountSystem::GetDiscount(User* user, float num) {
	CouponSorter s(num, &userCoupon[user]);

	std::cout << "==================================================" << std::endl;
	std::cout << "######## Casher: Processing " << num << '$' << " ########" << std::endl;
	std::cout << "Dearest customer " << user->Name() << ", now we are working for you.." << std::endl;

	Coupon* coupon = s.Get();
	if (coupon) {
		float r = coupon->calculate(num);
		if (r == num) {
			std::cout << "A coupon was found, but you do not reach the condition.";
		}
		else {
			std::cout << "A coupon was found: ";
			DiscountCoupon* p1 = dynamic_cast<DiscountCoupon*>(coupon);
			if (p1) {
				std::cout << "DiscountCoupon "
					<< std::setprecision(2) << std::fixed << p1->Factor() * 100
					<< "% discount for above "
					<< std::setprecision(2) << std::fixed << p1->Lim() << "$" << std::endl;
			}
			else {
				CashCoupon* p2 = dynamic_cast<CashCoupon*>(coupon);
				if (p2) {
					std::cout << "CashCoupon -" << p2->Amount() << " for above " << p2->Lim() << "$" << std::endl;
				}
			}

			std::cout << "We saved "
				<< std::setprecision(2) << std::fixed << num - r
				<< "$, now the price is: "
				<< std::setprecision(2) << std::fixed << r << std::endl;


			userCoupon[user].pop_back();
			return r;
		}
	}
	else {
		std::cout << "You have no any coupon, the price keeps " << num << '$' << std::endl;
	}

	return num;
}
