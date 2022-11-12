/**
 * @file automata.h
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

#include <stdlib.h>

#include <algorithm>
#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

#include "../include/alphabet.h"
#include "../include/chain.h"
#include "../include/grammar.h"
#include "../include/state.h"

#pragma once

class Automata : public Chain {
 public:
  Automata(std::vector<std::string> automata_file_lines_vector);
  Alphabet getAlphabet();
  std::vector<State> getStates();
  std::string getInitialState();
  bool IsDFA();
  void PrintAutomata();
  bool DFAChainsValidation(std::string chain);
  Grammar ConvertToGrammar(Automata automata_to_convert);

 private:
  int number_of_states_;
  std::vector<State> states_;
  Alphabet alphabet_;
  std::string initial_state_;
};