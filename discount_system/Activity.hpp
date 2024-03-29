#include "Coupon.hpp"
class Activity {
private:
	unsigned int actid;
	int num;
	int deadline;
	bool finished;
	DiscountMode disconutMode;

	std::string identifier;

	Coupon* coupon;
	unsigned int generateID();
public:
	static int cnt;
	Activity(Coupon* coupon, int num, int deadline, DiscountMode disconutMode, std::string identifier);
	int Id();
	DiscountMode Type();
	int Amount();
	std::string Identifier();

	void GiveAway(User *user);
	
	friend std::ostream& operator<<(std::ostream& os, const Activity& activity);
};
