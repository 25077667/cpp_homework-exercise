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