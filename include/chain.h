/**
 * @file chain.h
 * @author Samuel Martín Morales (alu0101359526@ull.edu.es)
 * @brief This file contains the chain class.
 * @version 0.1
 * @date 2022-11-10
 * @signature Computabilidad y Algoritmia.
 * @course 2022-2023.
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <iostream>

#include "alphabet.h"

#pragma once

/**
 * @brief This is the class that represents the chain formed by the alphabets.
 *
 */
class Chain : public Alphabet {
 public:
  Chain();
  ~Chain();
  void AddChain(std::string newChain, Alphabet alphabet);
  std::string getChain();

 private:
  std::string chain_;
  Alphabet alphabetChain_;
};