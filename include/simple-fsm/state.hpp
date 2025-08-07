#ifndef SIMPLE_FSM_STATE_HPP
#define SIMPLE_FSM_STATE_HPP
#include <functional>

namespace SimpleFSM {

template <typename StateEnum>
class FSMStateMachine;

template <typename StateEnum>
class FSMState {
 protected:
  FSMState() = default;

 public:
  virtual ~FSMState() = default;
  virtual void step(FSMStateMachine<StateEnum>* process) = 0;
};

template <typename StateEnum>
class FSMSimpleState : public FSMState<StateEnum> {
 public:
  FSMSimpleState(std::function<void(FSMStateMachine<StateEnum>*)> stepFunc);
  ~FSMSimpleState() = default;
  void step(FSMStateMachine<StateEnum>* process);

 private:
  const std::function<void(FSMStateMachine<StateEnum>*)> stepFunc_;
};

template <typename StateEnum>
FSMSimpleState<StateEnum>::FSMSimpleState(
    std::function<void(FSMStateMachine<StateEnum>*)> stepFunc)
    : stepFunc_(stepFunc) {}

template <typename StateEnum>
void FSMSimpleState<StateEnum>::step(FSMStateMachine<StateEnum>* process) {
  stepFunc_(process);
}

}  // namespace SimpleFSM
#endif
