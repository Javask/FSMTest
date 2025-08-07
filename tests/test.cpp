#include <catch2/catch_test_macros.hpp>
#include <cstdint>
#include <simple-fsm/simple-fsm.hpp>

enum BasicStates {
  START,
  WORK,
  ERROR,
  END,
};

TEST_CASE("Basic") {
  using namespace SimpleFSM;
  const auto states = FSMStateMap<BasicStates>{
      {START, std::make_shared<FSMSimpleState<BasicStates>>(
                  [](FSMStateMachine<BasicStates>* process) {
                    process->goToState(WORK);
                  })},
      {WORK, std::make_shared<FSMSimpleState<BasicStates>>(
                 [](FSMStateMachine<BasicStates>* process) {
                    process->goToState(END);
                 })},
      {ERROR, std::make_shared<FSMSimpleState<BasicStates>>(
                  [](FSMStateMachine<BasicStates>* process) {

                  })},
      {END, std::make_shared<FSMSimpleState<BasicStates>>(
                [](FSMStateMachine<BasicStates>* process) {

                })},
  };

  FSMStateMachine<BasicStates> stateMachine(START, states);
  REQUIRE(stateMachine.getCurrentState() == START);
  stateMachine.run();
  REQUIRE(stateMachine.getCurrentState() == WORK);
  stateMachine.run();
  REQUIRE(stateMachine.getCurrentState() == END);
  stateMachine.run();
  REQUIRE(stateMachine.getCurrentState() == END);
}