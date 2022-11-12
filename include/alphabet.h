/**
 * @file alphabet.h
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

#include <iostream>
#include <vector>

#pragma once

/**
 * @brief This class contains the different alphabets of the introduced file.
 *
 */
class Alphabet {
 public:
  Alphabet();
  void setSymbolsToAlphabet(std::vector<std::string> dividedAlphabet);
  bool AlphabetComprobation(std::string chain);
  void PrintAlphabet();
  void setAlphabet(std::vector<std::string> alphabetToIntroduce);
  std::vector<std::string> getAlphabet();
  std::string ChainComprobation(std::string chain);

 private:
  std::vector<std::string> alphabet_;
};