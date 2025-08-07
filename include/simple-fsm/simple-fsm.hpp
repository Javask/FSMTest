#ifndef SIMPLE_FSM_SIMPLE_FSM_HPP
#define SIMPLE_FSM_SIMPLE_FSM_HPP
#include <cassert>
#include <memory>
#include <string_view>
#include <unordered_map>
#include <vector>

#include "state.hpp"

namespace SimpleFSM {

template <typename StateEnum>
using FSMStateMap =
    std::unordered_map<StateEnum, std::shared_ptr<FSMState<StateEnum>>>;

template <typename StateEnum>
class FSMStateMachine {
 public:
  FSMStateMachine(StateEnum start, const FSMStateMap<StateEnum>& state);

  void goToState(StateEnum state);
  StateEnum getCurrentState() const;

  void run();

 private:
  StateEnum currentState_;
  FSMStateMap<StateEnum> states_;
};

template <typename StateEnum>
FSMStateMachine<StateEnum>::FSMStateMachine(
    StateEnum start, const FSMStateMap<StateEnum>& states)
    : currentState_(start), states_(states) {}

template <typename StateEnum>
void FSMStateMachine<StateEnum>::goToState(StateEnum state) {
  currentState_ = state;
}

template <typename StateEnum>
void FSMStateMachine<StateEnum>::run() {
  if (states_.count(currentState_) != 0) {
    states_.at(currentState_)->step(this);
  }
}

template <typename StateEnum>
StateEnum FSMStateMachine<StateEnum>::getCurrentState() const {
  return currentState_;
}

}  // namespace SimpleFSM

#endif
