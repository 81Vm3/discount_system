
class CouponSorter {
	float num;
	VCoupon *conpons;

		
	bool cmp(Coupon* a, Coupon* b) const;
public:
	CouponSorter(float m, VCoupon *v);
	Coupon* Get();
};