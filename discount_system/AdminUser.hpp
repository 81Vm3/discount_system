class Coupon;
class AdminUser : public User {
public:
	AdminUser(unsigned int id, std::string name);

	bool CreateActivity(Coupon* coupon, int num, int deadline, DiscountMode mode, std::string identifier);
};