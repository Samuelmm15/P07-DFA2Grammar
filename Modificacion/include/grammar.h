/**
 * @file grammar.h
 * @author Samuel Martín Morales (alu0101359526@ull.edu.es)
 * @brief This file contains the grammar class.
 * @version 0.1
 * @date 2022-11-10
 * @signature Computabilidad y Algoritmia.
 * @course 2022-2023.
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#pragma once

/**
 * @brief This is the class that represents the grammar.
 * 
 */
class Grammar {
 public:
  Grammar();
  void setNumberOfTerminalSymbols(int number_of_terminal_symbols);
  void setNumberOfNonTerminalSymbols(int number_of_non_terminal_symbols);
  void setTerminalSymbols(std::vector<std::string> terminal_symbols);
  void setNonTerminalSymbols(std::vector<std::string> non_terminal_symbols);
  void setInitialSymbol(std::string initial_symbol);
  void setNumberOfProductions(int number_of_productions);
  void setProductions(std::vector<std::string> productions);
  void PrintGrammar();
  void PrintGrammarToFile(std::string file_name);

 private:
  int number_of_terminal_symbols_;
  std::vector<std::string> terminal_symbols_;
  int number_of_non_terminal_symbols_;
  std::vector<std::string> non_terminal_symbols_;
  std::string initial_symbol_;
  int number_of_productions_;
  std::vector<std::string> productions_;
};