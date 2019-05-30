#include <functional>
#include <sstream>
namespace NU {
class NewUser {
   public:
    void setUserName(std::string);
    void setPasswd(std::string);
    std::string getHashedPasswd() const;
    std::string getUserName() const;  //WTF????
    bool operator==(const NewUser&);

   private:
    std::string userName;
    std::string hashedPasswd;
};
}  // namespace NU

void NU::NewUser::setUserName(std::string name) {
    this->userName = name;
}

void NU::NewUser::setPasswd(std::string rawPasswd) {
    std::hash<std::string> str_hash;
    std::stringstream ss;
    ss << str_hash(rawPasswd);
    ss >> this->hashedPasswd;
}

std::string NU::NewUser::getHashedPasswd() const {
    return this->hashedPasswd;
}

std::string NU::NewUser::getUserName() const {
    return this->userName;
}

bool NU::NewUser::operator==(const NewUser& b) {
    return (this->getUserName() == b.getUserName()) && (this->getHashedPasswd() == b.getHashedPasswd());
}