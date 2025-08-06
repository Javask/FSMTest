#ifndef SIMPLE_FSM_PROCESS_HPP
#define SIMPLE_FSM_PROCESS_HPP
#include <memory>
#include <string_view>

namespace SimpleFSM {

class FSMProcessBase {
 protected:
  FSMProcessBase() = default;

 public:
  virtual ~FSMProcessBase() = default;
};

template <enum StateEnum>
class FSMProcess : public FSMProcessBase, FSMState {
 protected:
  FSMProcess(std::string_view) = default;

 public:
  virtual ~FSMProcess() = default;

 private:
  std::map<StateEnum, std::unique_ptr<FSMState>> states_;
};

}  // namespace SimpleFSM
#endif
