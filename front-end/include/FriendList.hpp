#include "FriendInWS.hpp"
#include "IRender.hpp"

#include <memory>
#include <string>
#include <vector>

class FriendList : IRender {
private:
  std::vector<std::unique_ptr<FriendInWS>> friends;
public:
  void addFriend(const std::string &username);
  void render() override;
};