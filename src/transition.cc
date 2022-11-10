/**
 * @file transition.cc
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

#include "../include/transition.h"

/**
 * @brief This constructor of the transition objects.
 * 
 */
Transition::Transition() {
  transition_ = "";
};

/**
 * @brief This method sets the transition symbol.
 * 
 * @param transition_symbol is the symbol of the transition.
 */
void Transition::setTransitionSymbol(std::string transition_symbol) {
  transition_symbol_ = transition_symbol;
};

/**
 * @brief This method returns the transition symbol.
 * 
 * @return std::string is the transition symbol.
 */
std::string Transition::getTransitionSymbol() {
  return transition_symbol_;
};

/**
 * @brief This method sets the transition state.
 * 
 * @param transition is the transition state.
 */
void Transition::setTransitionState(std::string transition) {
    transition_ = transition;
};

/**
 * @brief This method returns the transition state.
 * 
 * @return std::string is the transition state.
 */
std::string Transition::getTransitionState() {
  return transition_;
};

/**
 * @brief This method returns the transition.
 * 
 */
std::string Transition::at() {
    return transition_;
};