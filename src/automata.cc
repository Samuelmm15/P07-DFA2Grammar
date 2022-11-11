/**
 * @file automata.cc
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

#include "../include/automata.h"
#include "../include/alphabet.h"
#include "../include/state.h"
#include "../include/transition.h"
#include "../include/grammar.h"

/**
 * @brief This is the constructor of the different automatas objects.
 * 
 * @param automata_file_lines_vector This is the vector that contains the lines of the automata specifications.
 */
Automata::Automata(std::vector<std::string> automata_file_lines_vector) {
  std::string auxiliary_line;
  for (int i = 0; i < automata_file_lines_vector.size(); i++) {
    if (i == 0) {
        auxiliary_line = automata_file_lines_vector[i];
        std::vector<std::string> auxiliary_input;
        for (int j = 0; j < auxiliary_line.size(); j++) {
          if (auxiliary_line[j] != ' ') {
            std::string auxiliary_string;
            auxiliary_string = auxiliary_line[j];
            auxiliary_input.push_back(auxiliary_string);
          }
        }
        Alphabet auxiliary_alphabet;
        auxiliary_input.push_back(auxiliary_line);
        auxiliary_alphabet.setSymbolsToAlphabet(auxiliary_input);
        auxiliary_line.clear();
        alphabet_ = auxiliary_alphabet; /// This is the alphabet of the automata.
    } else if (i == 1) {
      number_of_states_ = std::stoi(automata_file_lines_vector[i]); /// Neccesary to convert into int.
    } else if (i == 2) {
      if (automata_file_lines_vector[i].size() == 1) {
        initial_state_ = automata_file_lines_vector[i];
      } else {
        std::cout << std::endl;
        std::cout << "ERROR >>> El autómata no puede tener más de un estado inicial" << std::endl;
        std::cout << std::endl;
        exit(1); /// Exit with error 1.
      }
    } else { /// This is the part of the automata where the states are created.
      auxiliary_line = automata_file_lines_vector[i];
      auxiliary_line.erase(std::remove(auxiliary_line.begin(), auxiliary_line.end(), ' '), auxiliary_line.end()); 
      State auxiliary_state;
      Transition auxiliary_transition;
      bool introduction_of_state = false;
      for (int j = 0; j < auxiliary_line.size(); j++) {
        if (j == 0) {
          std::string auxiliary_string;
          auxiliary_string = auxiliary_line[j];
          auxiliary_state.setState(auxiliary_string);
        } else if (j == 1) {
          if (auxiliary_line[j] == '0') {
            auxiliary_state.setFinalState(false);
          } else {
            auxiliary_state.setFinalState(true);
          }
        } else if (j == 2) {
          std::string auxiliary_string;
          auxiliary_string.push_back(auxiliary_line[j]);
          if (auxiliary_string == "0") {
            std::cout << std::endl;
            std::cout << "El estado " << auxiliary_state.getState() << " no tiene transiciones" << std::endl;
            std::cout << std::endl;
          } else {
            int auxiliary_number_of_transitions = std::stoi(auxiliary_string);
            auxiliary_state.setNumberTransitions(auxiliary_number_of_transitions);
          }
        } else {
          if (introduction_of_state == false) {
            std::string auxiliary_string;
            auxiliary_string.push_back(auxiliary_line[j]);
            if (alphabet_.AlphabetComprobation(auxiliary_string) == false) {
              std::cout << std::endl;
              std::cout << "ERROR >>> El símbolo " << auxiliary_string << " no pertenece al alfabeto del autómata" << std::endl;
              std::cout << std::endl;
              exit(1); /// Exit with error 1.
            }
            auxiliary_transition.setTransitionSymbol(auxiliary_string);
            introduction_of_state = true;
          } else {
            std::string auxiliary_string;
            auxiliary_string.push_back(auxiliary_line[j]);
            auxiliary_transition.setTransitionState(auxiliary_string);
            auxiliary_state.setTransitions(auxiliary_transition);
            introduction_of_state = false;
            Transition auxiliary_transition_; /// To reload the objects
          }
        }
      }
      auxiliary_line.clear();
      states_.push_back(auxiliary_state);
    }
  }
};

/**
 * @brief This method returns the alphabet of the automata.
 * 
 * @return Alphabet 
 */
Alphabet Automata::getAlphabet() {
  return alphabet_;
};

std::vector<State> Automata::getStates() {
  return states_;
};

std::string Automata::getInitialState() {
  return initial_state_;
};

void Automata::PrintAutomata() {
  std::cout << std::endl;
  std::cout << "Alfabeto del autómata: ";
  alphabet_.PrintAlphabet();
  std::cout << std::endl;
  std::cout << "Número de estados del autómata: " << number_of_states_ << std::endl;
  std::cout << "Estado inicial del autómata: " << initial_state_ << std::endl;
  std::cout << std::endl;
  std::cout << "Estados del autómata: " << std::endl;
  for (int i = 0; i < states_.size(); i++) {
    std::cout << "Estado: " << states_[i].getState() << std::endl;
    if (states_[i].getFinalState() == true) {
      std::cout << "Estado final: Sí" << std::endl;
    } else {
      std::cout << "Estado final: No" << std::endl;
    }
    std::cout << "Número de transiciones: " << states_[i].getNumberTransitions() << std::endl;
    std::cout << std::endl;
  }
};

/**
 * @brief This method validates the chains of the automata.
 * 
 * @param chain The chain that is going to be validated.
 * @return true If the chain is valid.
 * @return false If the chain is not valid.
 */
bool Automata::DFAChainsValidation(std::string chain) {
  std::string current_state = initial_state_;
  std::string next_state;
  bool chain_accepted = false;
  for (int i = 0; i < chain.size(); i++) {
    std::string auxiliary_string;
    auxiliary_string.push_back(chain[i]);
    for (int j = 0; j < states_.size(); j++) {
      if (states_[j].getState() == current_state) {
        for (int k = 0; k < states_[j].getTransition().size(); k++) {
          if (states_[j].getTransition()[k].getTransitionSymbol() == auxiliary_string) {
            next_state = states_[j].getTransition()[k].getTransitionState();
          }
        }
      }
    }
    current_state = next_state;
  }
  for (int i = 0; i < states_.size(); i++) {
    if (states_[i].getState() == current_state) {
      if (states_[i].getFinalState() == true) {
        chain_accepted = true;
      }
    }
  }
  return chain_accepted;
};

Grammar Automata::ConvertToGrammar(Automata automata_to_convert) {
  /// Determinación de los símbolos terminales, que corresponden con el alfabeto del automata.
  Grammar auxiliary_grammar;
  int number_of_terminal_symbols = automata_to_convert.getAlphabet().getAlphabet().size();
  auxiliary_grammar.setNumberOfTerminalSymbols(number_of_terminal_symbols);
  /// Determinación de los distintos símbolos terminales que corresponden los distintos símbolos terminales de la gramática.
  std::vector<std::string> terminal_symbols;
  for (int i = 0; i < number_of_terminal_symbols; i++) {
    terminal_symbols.push_back(automata_to_convert.getAlphabet().getAlphabet()[i]);
  }
  auxiliary_grammar.setTerminalSymbols(terminal_symbols);
  /// Determinación de los símbolos no terminales, que corresponden con los estados del automata.
  int number_of_non_terminal_symbols = automata_to_convert.getStates().size();
  auxiliary_grammar.setNumberOfNonTerminalSymbols(number_of_non_terminal_symbols);
  /// Determinación de los distintos símbolos no terminales que corresponden los distintos símbolos no terminales de la gramática.
  std::vector<std::string> non_terminal_symbols;
  for (int i = 0; i < number_of_non_terminal_symbols; i++) {
    non_terminal_symbols.push_back(automata_to_convert.getStates()[i].getState());
  }
  auxiliary_grammar.setNonTerminalSymbols(non_terminal_symbols);

  /// Determinación del símbolo inicial de la gramática, que corresponde con el estado inicial del automata.
  std::string initial_symbol = automata_to_convert.getInitialState();
  auxiliary_grammar.setInitialSymbol(initial_symbol);

  /// Determinación del número de producciones de la gramática.
  int number_of_productions = 0;
  for (int i = 0; i < automata_to_convert.getStates().size(); i++) {
    number_of_productions += automata_to_convert.getStates()[i].getNumberTransitions();
  }
  auxiliary_grammar.setNumberOfProductions(number_of_productions);

  /// Determinación de las distintas producciones de la gramática.
  std::vector<std::string> productions;
  for (int i = 0; i < automata_to_convert.getStates().size(); i++) {
    for (int j = 0; j < automata_to_convert.getStates()[i].getNumberTransitions(); j++) {
      std::string auxiliary_string;
      auxiliary_string.push_back(automata_to_convert.getStates()[i].getState()[0]);
      auxiliary_string.push_back('-');
      auxiliary_string.push_back('-');
      auxiliary_string.push_back('>');
      auxiliary_string.push_back(' ');
      auxiliary_string.push_back(automata_to_convert.getStates()[i].getTransition()[j].getTransitionSymbol()[0]);
      auxiliary_string.push_back(automata_to_convert.getStates()[i].getTransition()[j].getTransitionState()[0]);
      productions.push_back(auxiliary_string);
    }
    if (automata_to_convert.getStates()[i].getFinalState() == true) {
        std::string auxiliary_string;
        auxiliary_string.push_back(automata_to_convert.getStates()[i].getState()[0]);
        auxiliary_string.push_back(' ');
        auxiliary_string.push_back('-');
        auxiliary_string.push_back('>');
        auxiliary_string.push_back(' ');
        auxiliary_string.push_back('&');
        productions.push_back(auxiliary_string);
      }
  }
  auxiliary_grammar.setProductions(productions);
  
  return auxiliary_grammar;
};