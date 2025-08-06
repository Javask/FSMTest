#ifndef SIMPLE_FSM_STATE_HPP
#define SIMPLE_FSM_STATE_HPP
#include <string_view>

namespace SimpleFSM {

class FSMProcessBase;

class FSMState {
 protected:
  FSMState(std::string_view name);

 public:
  virtual ~FSMState() = default;
  virtual void step(FSMProcessBase* process) = 0;
};

}  // namespace SimpleFSM
#endif
