/**
 * @file state.h
 * @author Samuel Martín Morales (alu0101359526@ull.edu.es)
 * @brief This file contains the state class.
 * @version 0.1
 * @date 2022-11-10
 * @signature Computabilidad y Algoritmia.
 * @course 2022-2023.
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "../include/transition.h"

#pragma once

/**
 * @brief This class contains the different states of the automata.
 *
 */
class State {
 public:
  State();
  ~State();
  void setState(std::string state_number);
  void setTransitions(Transition transition);
  void setFinalState(bool final_state);
  void setNumberTransitions(int number_transitions);
  std::string getState();
  bool getFinalState();
  std::vector<Transition> getTransition();
  int getNumberTransitions();
  void PrintState();

 private:
  std::string state_;
  int number_of_transitions_;
  std::vector<Transition> transitions_;
  bool final_state_;  /// To comprobe that the state is final or not.
};