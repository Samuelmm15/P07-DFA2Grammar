/**
 * @file main.cc
 * @author Samuel Martín Morales (alu0101359526@ull.edu.es)
 * @brief This is the file that contains the main function of the program.
 * @version 0.1
 * @date 2022-11-04
 * @signature Computabilidad y Algoritmia.
 * @course 2022-2023.
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <regex>

#include "../include/automata.h"

/**
 * @brief This overload implements the read of the input file.
 * 
 * @param input The name of the input file.
 * @param vector_chains The vector that contains the chains to be evaluated.
 * @return std::istream& 
 */
std::istream& operator>>(std::istream& input, std::vector<std::string>& vector_chains) {
    std::string line; 
    while (std::getline(input, line)) {
        vector_chains.push_back(line);
    }
    return input;
}

/**
 * @brief This is the main function of the program.
 * 
 * @param argc This is the number of arguments that the program receives.
 * @param argv This is the vector of arguments that the program receives.
 * @return int 
 */
int main(int argc, char** argv) {
  if (argc == 3) {
    /// Format of the input files
    std::string automata_file = argv[1];
    std::string chains_file = argv[2];
    std::regex automata__file_regex(".*\\.fa$");
    if (!std::regex_match(automata_file, automata__file_regex)) {
      std::cout << "ERROR: El fichero de entrada de especificación del autómata, no tiene el formato de fichero correcto." << std::endl;
      std::cout << "Para más información haga uso de la opción -h o --help" << std::endl;
      std::cout << "./p06_automata_simulator (-h | --help)" << std::endl;
      return 1;
    }
    std::regex chains_file_regex(".*\\.txt$");
    if (!std::regex_match(chains_file, chains_file_regex)) {
      std::cout << "ERROR: El fichero de entrada de las cadenas a comprobar, no tiene el formato de fichero correcto." << std::endl;
      std::cout << "Para más información haga uso de la opción -h o --help" << std::endl;
      std::cout << "./p06_automata_simulator (-h | --help)" << std::endl;
      return 1;
    }
    /// Read the automata file
    std::ifstream automata_file_content(automata_file);
    std::vector<std::string> automata_file_lines_vector;
    automata_file_content >> automata_file_lines_vector;
    automata_file_content.close();
    /// Automata object creation 
    Automata new_automata(automata_file_lines_vector);

    /// Read the chains file
    std::ifstream chains_file_content(chains_file);
    std::vector<std::string> chains_file_lines_vector;
    chains_file_content >> chains_file_lines_vector;
    chains_file_content.close();

    std::vector<Chain> chains_to_validate;
    for (int i = 0; i < chains_file_lines_vector.size(); i++) {
      Chain new_chain;
      new_chain.AddChain(chains_file_lines_vector[i], new_automata.getAlphabet());
      chains_to_validate.push_back(new_chain);
    }

    std::cout << std::endl;
    for (int i = 0; i < chains_to_validate.size(); i++) {
      if (new_automata.DFAChainsValidation(chains_to_validate[i].getChain()) == true) {
        std::cout << i << ". " << chains_to_validate[i].getChain() << " --- aceptada." << std::endl;
      } else {
        std::cout << i << ". " << chains_to_validate[i].getChain() << " --- rechazada." << std::endl;
      }
    }

    // std::cout << std::endl;
    // for (int i = 0; i < chains_to_validate.size(); i++) {
    //   if (new_automata.NFAChainsValidation(chains_to_validate[i].getChain()) == true) {
    //     std::cout << i << ". " << chains_to_validate[i].getChain() << " --- aceptada." << std::endl;
    //   } else {
    //     std::cout << i << ". " << chains_to_validate[i].getChain() << " --- rechazada." << std::endl;
    //   }
    // }

  } else if (argc == 2) {
    std::string option = argv[1];
    if ((option == "-h") || (option == "--help")) {
      std::cout << "Usage: ./p06_automata_simulator [file_name.fa] [file_name.txt]" << std::endl;
      return 1; /// Exit code 1
    } else {
      std::cout << "ERROR: La opción introducida es incorrecta." << std::endl;
      std::cout << "Para más información haga uso de la opción -h o --help" << std::endl;
      std::cout << "./p06_automata_simulator (-h | --help)" << std::endl;
      return 1; /// Exit code 1
    }
  } else {
    std::cout << "ERROR: El número de argumentos es inválido." << std::endl;
    std::cout << "Para más información haga uso de la opción -h o --help" << std::endl;
    std::cout << "./p06_automata_simulator (-h | --help)" << std::endl;
    return 1; /// Exit code 1
  }
return 0; /// Exit code 0
}
