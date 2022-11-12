/**
 * @file main.cc
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

/// FALTA COMPROBAR SI SE TRATA DE UN DFA O DE UN NFA.

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <regex>

#include "../include/automata.h"
#include "../include/grammar.h"

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
    std::string grammar_file = argv[2];
    std::regex automata__file_regex(".*\\.fa$");
    if (!std::regex_match(automata_file, automata__file_regex)) {
      std::cout << std::endl;
      std::cout << "ERROR: El fichero de entrada de especificación del autómata, no tiene el formato de fichero correcto." << std::endl;
      std::cout << "Para más información haga uso de la opción -h o --help" << std::endl;
      std::cout << "./dfa2grammar (-h | --help)" << std::endl;
      std::cout << std::endl;
      return 1;
    }
    std::regex grammar_file_regex(".*\\.gra$");
    if (!std::regex_match(grammar_file, grammar_file_regex)) {
      std::cout << std::endl;
      std::cout << "ERROR: El fichero de salida de la gramática generada no tiene el formato de fichero correcto." << std::endl;
      std::cout << "Para más información haga uso de la opción -h o --help" << std::endl;
      std::cout << "./dfa2grammar (-h | --help)" << std::endl;
      std::cout << std::endl;
      return 1;
    }
    /// Read the automata file
    std::ifstream automata_file_content(automata_file);
    std::vector<std::string> automata_file_lines_vector;
    automata_file_content >> automata_file_lines_vector;
    automata_file_content.close();
    /// Automata object creation 
    Automata new_automata(automata_file_lines_vector);
    new_automata.PrintAutomata();

    /// NFA or DFA comprobation
    if (new_automata.IsDFA()) {
      Grammar new_grammar;
      new_grammar = new_automata.ConvertToGrammar(new_automata);
      new_grammar.PrintGrammar();
      new_grammar.PrintGrammarToFile(grammar_file);
    } else {
      std::cout << "ERROR >>> No se pudo generar la gramática, debido a que el automata introducido no es un DFA." << std::endl;
      std::cout << "Para la correcta ejecución del programa introduzca un DFA." << std::endl;
      std::cout << "Para más información haga uso de la opción -h o --help" << std::endl;
      std::cout << std::endl;
      return 2; /// Salida con error de tipo 2
    }

  } else if (argc == 2) {
    std::string option = argv[1];
    if ((option == "-h") || (option == "--help")) {
      std::cout << std::endl;
      std::cout << "Usage: ./dfa2grammar [input.fa] [output.gra]" << std::endl;
      std::cout << std::endl;
      return 1; /// Exit code 1
    } else {
      std::cout << std::endl;
      std::cout << "ERROR: La opción introducida es incorrecta." << std::endl;
      std::cout << "Para más información haga uso de la opción -h o --help" << std::endl;
      std::cout << "./dfa2grammar (-h | --help)" << std::endl;
      std::cout << std::endl;
      return 1; /// Exit code 1
    }
  } else {
    std::cout << std::endl;
    std::cout << "ERROR: El número de argumentos es inválido." << std::endl;
    std::cout << "Para más información haga uso de la opción -h o --help" << std::endl;
    std::cout << "./dfa2grammar (-h | --help)" << std::endl;
    std::cout << std::endl;
    return 1; /// Exit code 1
  }
return 0; /// Exit code 0
}
