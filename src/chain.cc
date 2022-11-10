/**
 * @file chain.cc
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

#include "../include/chain.h"

/**
 * @brief This is the constructor of the chains objects.
 * 
 */
Chain::Chain() {
};

/**
 * @brief Destroy the Chain:: Chain object
 * 
 */
Chain::~Chain() {
  chain_.clear();
};

/**
 * @brief This method adds the different introduced chains by the file into a vector of chains.
 * 
 * @param newChain is the chain to introduce into the vector.
 * @param alphabet is the alphabet of the introduced chain.
 */
void Chain::AddChain(std::string newChain, Alphabet alphabet) {
  if (alphabet.AlphabetComprobation(newChain) == true) {
    chain_ = newChain;
    alphabetChain_ = alphabet;
  } else {
    std::cout << "La cadena " << newChain << " no pertenece al alfabeto introducido" << std::endl;
  }
  chain_ = newChain;
};

/**
 * @brief This method returns the chain of the position given.
 * 
 * @param position is the position of the differents chain introduced.
 * @return std::string is the string that is gonna to use.
 */
std::string Chain::getChain() {
  return chain_;
};