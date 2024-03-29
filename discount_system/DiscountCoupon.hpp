
class DiscountCoupon : public Coupon {
private:
	int lim;
	float factor;
public:
	DiscountCoupon(int id, int lim, float discount_factor);
	float calculate(float pay);
	
	float Factor();
	float Lim();
};