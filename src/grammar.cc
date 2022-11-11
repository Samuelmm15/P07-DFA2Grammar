/**
 * @file grammar.cc
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

#include "../include/grammar.h"

Grammar::Grammar() {
};

void Grammar::setNumberOfTerminalSymbols(int number_of_terminal_symbols) {
  number_of_terminal_symbols_ = number_of_terminal_symbols;
};

void Grammar::setNumberOfNonTerminalSymbols(int number_of_non_terminal_symbols) {
  number_of_non_terminal_symbols_ = number_of_non_terminal_symbols;
};

void Grammar::setTerminalSymbols(std::vector<std::string> terminal_symbols) {
  terminal_symbols_ = terminal_symbols;
};

void Grammar::setNonTerminalSymbols(std::vector<std::string> non_terminal_symbols) {
  non_terminal_symbols_ = non_terminal_symbols;
};

void Grammar::setInitialSymbol(std::string initial_symbol) {
  initial_symbol_ = initial_symbol;
};

void Grammar::setProductions(std::vector<std::string> productions) {
  productions_ = productions;
};

void Grammar::PrintGrammar() {
  
};

void Grammar::PrintGrammarToFile(std::string file_name) {
  
};