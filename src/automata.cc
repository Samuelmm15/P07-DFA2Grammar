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

Grammar Automata::ConvertToGrammar() {

};