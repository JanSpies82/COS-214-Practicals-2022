#include "Snapshot.h"
Snapshot::Snapshot(std::string username, std::string date, std::string state) {
    _username = username;
    _date = date;
    _state = state;

}
// Snapshot::~Snapshot() {
//     delete _username;
//     delete _date;
//     delete _state;
// }
std::string Snapshot::GetUsername()  const { return _username; }
std::string Snapshot::date() const { return _date; }
std::string Snapshot::state() const { return _state; }