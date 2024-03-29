
class CashCoupon : public Coupon {
private:
	float lim;
	float amount;
public:
	CashCoupon(int id, float lim, float amount);
	float calculate(float pay);

	float Amount();
	float Lim();
};