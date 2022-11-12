/**
 * @file alphabet.cc
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

#include "../include/alphabet.h"

/**
 * @brief This is the constructor of the different Alphabet objects.
 *
 */
Alphabet::Alphabet(){};

/**
 * @brief This method sets a symbol into the alphabet of the introduced example.
 *
 * @param line This is the readed line of the introduced file to obtain the
 * alphabet of the differents chains.
 */
void Alphabet::setSymbolsToAlphabet(std::vector<std::string> dividedAlphabet) {
  for (int i = 0; i < dividedAlphabet.size(); i++) {
    if (dividedAlphabet[i].size() == 1) {
      alphabet_.push_back(dividedAlphabet[i]);
    }
  }
};

/**
 * @brief This method prints the alphabet into the screen.
 *
 */
void Alphabet::PrintAlphabet() {
  std::cout << "{ ";
  for (int i = 0; i < alphabet_.size(); i++) {
    if (i != (alphabet_.size() - 1)) {
      std::cout << alphabet_[i] << " , ";
    } else {
      std::cout << alphabet_[i];
    }
  }
  std::cout << " } "
            << " ";
};

/**
 * @brief This method comprobes if a chain belongs at the alphabet.
 *
 * @param chain is the chain to comprobe.
 * @return true if the chain was formed by the alphabet.
 * @return false if the chain was not formed by the alphabet.
 */
bool Alphabet::AlphabetComprobation(std::string chain) {
  if (chain == "&") {
    return true;
  } else {
    bool flag;
    int counter = 0;
    for (int i = 0; i < chain.size(); i++) {
      for (int j = 0; j < alphabet_.size(); j++) {
        std::string auxiliary = alphabet_[j];
        if (chain[i] == auxiliary[0]) {
          counter++;
        }
      }
    }
    if (counter == chain.size()) {
      return true;
    } else {
      return false;
    }
  }
};

/**
 * @brief This method sets an alphabet into the class alphabet.
 *
 * @param alphabetToIntroduce This is the alphabet to introduce into the
 * alphabet object.
 */
void Alphabet::setAlphabet(std::vector<std::string> alphabetToIntroduce) {
  alphabet_ = alphabetToIntroduce;
};

/**
 * @brief This method returns the alphabet contained into the object.
 *
 * @return std::vector<std::string>
 */
std::vector<std::string> Alphabet::getAlphabet() { return alphabet_; };

/**
 * @brief This method comprobes if an introduced chain belongs at the object
 * alphabet.
 *
 * @param chain The introduced chain to comprobe if it belongs at the alphabet.
 * @return std::string
 */
std::string Alphabet::ChainComprobation(std::string chain) {
  std::string chainResult;
  for (int i = 0; i < chain.size(); i++) {
    for (int j = 0; j < alphabet_.size(); j++) {
      std::string auxiliary = alphabet_[j];
      if (chain[i] == auxiliary[0]) {
        if (chainResult.size() == 0) {
          chainResult.push_back(chain[i]);
        } else {
          int counter = 0;
          for (int k = 0; k < chainResult.size(); k++) {
            if (chain[i] == chainResult[k]) {
              counter = 1;
            }
          }
          if (counter == 0) {
            chainResult.push_back(chain[i]);
          }
        }
      }
    }
  }
  return chainResult;
};