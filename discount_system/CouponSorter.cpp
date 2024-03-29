#include "DiscountSystem.hpp"

bool CouponSorter::cmp(Coupon* a, Coupon* b) const {
	int ca = a->calculate(num);
	int cb = b->calculate(num);
	if (ca == cb) {
		return a->Id() > b->Id();
	}
	return ca > cb;
}

CouponSorter::CouponSorter(float m, VCoupon* v) {
	num = m;
	conpons = v;
}

Coupon* CouponSorter::Get() {
	if (conpons->empty())
		return nullptr;

	std::sort(conpons->begin(), conpons->end(),
		[this](auto& a, auto& b) {
			return this->cmp(a.get(), b.get());
		});
	return conpons->back().get();
}