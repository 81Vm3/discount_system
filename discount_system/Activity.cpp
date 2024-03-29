#include "DiscountSystem.hpp"

int Activity::cnt = 0;

unsigned int Activity::generateID() {
	auto now = std::chrono::system_clock::now();
	auto now_c = std::chrono::system_clock::to_time_t(now);

	// Use tm to break down time into calendar components
	tm now_tm = *std::localtime(&now_c);

	// Use stringstream and put_time to format the date
	std::stringstream date_stream;
	date_stream << std::put_time(&now_tm, "%Y%m%d") << ++cnt;

	unsigned int r;
	date_stream >> r;

	return r;
}

Activity::Activity(Coupon* coupon, int num, int deadline, DiscountMode disconutMode, std::string identifier) {
	this->coupon = coupon;
	this->actid = generateID();
	this->num = num;
	this->deadline = deadline;
	this->disconutMode = disconutMode;
	this->identifier = identifier;
	this->finished = false;
}

int Activity::Id() { return actid; }

DiscountMode Activity::Type() {
	return disconutMode;
}

int Activity::Amount() {
	return num;
}

std::string Activity::Identifier() {
	return identifier;
}
void Activity::GiveAway(User* user) {
	if (finished)
		return;

	if (!user)
		return;

	DiscountSystem& s = DiscountSystem::getInstance();

	s.GiveCoupon(coupon, user);
	num--;

	if (num <= 0) {
		finished = true;
	}
}

std::ostream& operator<<(std::ostream& os, const Activity& activity)
{
	os << '\"' << activity.identifier << '\"' << "  (" << activity.actid << ')';
	return os;
}
