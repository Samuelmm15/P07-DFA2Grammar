/**
 * @file state.cc
 * @author Samuel Martín Morales (alu0101359526@ull.edu.es)
 * @brief 
 * @version 0.1
 * @date 2022-11-10
 * @signature Computabilidad y Algoritmia.
 * @course 2022-2023.
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "../include/state.h"
#include "../include/transition.h"

/**
 * @brief This is the constructor of the different states.
 * 
 */
State::State() {
  state_ = "";
};

/**
 * @brief This is the destructor of the different states.
 * 
 */
State::~State() {
  state_ = "";
  transitions_.clear();
};

/**
 * @brief This method sets the state.
 * 
 * @param state is the state to set.
 */
void State::setState(std::string state_number) {
  state_ = state_number;
};

/**
 * @brief This method sets the different transitions of the state.
 * 
 * @param transition is the transition to set to the state.
 */
void State::setTransitions(Transition transition) {
  transitions_.push_back(transition);
};

/**
 * @brief This method sets the final state.
 * 
 * @param final_state is the final state of the automata.
 */
void State::setFinalState(bool final_state) {
  final_state_ = final_state;
};

/**
 * @brief This method sets the number of transitions of the state.
 * 
 * @param number_transitions is the number of transitions of the state.
 */
void State::setNumberTransitions(int number_transitions) {
  number_of_transitions_ = number_transitions;
};

/**
 * @brief This method gets the state.
 * 
 * @return std::string is the number of the state.
 */
std::string State::getState() {
  return state_;
};

/**
 * @brief This method gets the final state.
 * 
 * @return true if the state is final.
 * @return false if the state is not final.
 */
bool State::getFinalState() {
  return final_state_;
};

/**
 * @brief This method returns the vector of transitions of the state.
 * 
 * @return std::vector<Transition> 
 */
std::vector<Transition> State::getTransition() {
  return transitions_;
};

int State::getNumberTransitions() {
  return number_of_transitions_;
};

/**
 * @brief This method prints the state and the different information.
 * 
 */
void State::PrintState() {
    std::cout << "State: " << state_ << std::endl;
    std::cout << "Number of transitions: " << number_of_transitions_ << std::endl;
    std::cout << "Transitions: " << std::endl;
    std::vector<Transition> transitions = getTransition();
    for (int i = 0; i < getTransition().size(); i++) {
        std::cout << transitions[i].at() << std::endl;
    }
};