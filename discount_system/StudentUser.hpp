
class StudentUser : public User {
public:
	StudentUser(unsigned int id, std::string name);
	void GetDiscount();
	void CheckDiscount();
	float Pay(float amount);
};

