
class User {
protected:
	unsigned int userid;
	std::string name;
	std::string password;
public:
	User(unsigned int id, std::string name);
	
	unsigned int UserID();
	std::string Name();
	std::string Password();

	virtual void f();
};