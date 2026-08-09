#include "FriendList.hpp"

void FriendList::addFriend(const std::string &username) {
  friends.push_back(std::make_unique<FriendInWS>(username));
}

void FriendList::render() {
  for (auto &friendItem : friends) {
    friendItem->render();
  }
}