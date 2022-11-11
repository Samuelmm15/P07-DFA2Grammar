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

void Grammar::setNumberOfProductions(int number_of_productions) {
  number_of_productions_ = number_of_productions;
};

void Grammar::setProductions(std::vector<std::string> productions) {
  productions_ = productions;
};

void Grammar::PrintGrammar() {
  std::cout << "Grmática generada a partir del DFA introducido:" << std::endl;
    std::cout << "Nº de símbolos terminales: " << number_of_terminal_symbols_ << std::endl;
    
    std::cout << "Símbolos terminales: ";
    for (int i = 0; i < number_of_terminal_symbols_; i++) {
      std::cout << terminal_symbols_[i] << " ";
    }
    
    std::cout << std::endl;
    std::cout << "Nº de símbolos no terminales: " << number_of_non_terminal_symbols_ << std::endl;
    
    std::cout << "Símbolos no terminales: ";
    for (int i = 0; i < number_of_non_terminal_symbols_; i++) {
      std::cout << non_terminal_symbols_[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "Símbolo inicial: " << initial_symbol_ << std::endl;

    std::cout << "Producciones: " << std::endl;
    for (int i = 0; i < productions_.size(); i++) {
      std::cout << productions_[i] << std::endl;
    }
};

void Grammar::PrintGrammarToFile(std::string file_name) {
  
};