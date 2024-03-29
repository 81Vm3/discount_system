#ifndef COUPON_HPP
#define COUPON_HPP

typedef std::vector<std::unique_ptr<Coupon>> VCoupon;

class Coupon {
private:
	int id;
public:
	Coupon() = default;
	Coupon(int id);
	int Id();
	virtual float calculate(float pay);
};


#endif