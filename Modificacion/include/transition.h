/**
 * @file transition.h
 * @author Samuel Martín Morales (alu0101359526@ull.edu.es)
 * @brief This file contains the transition class.
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

#pragma once

/**
 * @brief This class contains the different transitions of the automata.
 *
 */
class Transition {
 public:
  Transition();
  void setTransitionSymbol(std::string transition_symbol);
  std::string getTransitionSymbol();
  void setTransitionState(std::string transition);
  std::string getTransitionState();
  std::string at();

 private:
  std::string transition_symbol_;
  std::string transition_;
};