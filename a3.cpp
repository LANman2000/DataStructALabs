#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <list>
#include <utility>
#include <cctype>

// Helper function to edit user input
std::string toUpper(std::string s) {
    std::transform(s.begin(), s.end(), s.begin(), ::toupper);
    return s;
}

// Capitalize first letter only, rest lowercase
std::string toTitle(std::string s) {
    std::transform(s.begin(), s.end(), s.begin(), ::tolower);
    s[0] = toupper(s[0]);
    return s;
}

int main() {

    std::map<std::string, bool> exonThree;

    // Load into map withtout duplicates
    exonThree["GLY"] = true;
    exonThree["ILE"] = true;
    exonThree["VAL"] = true;
    exonThree["GLU"] = true;
    exonThree["GLN"] = true;
    exonThree["CYS"] = true;
    exonThree["ALA"] = true;
    exonThree["SER"] = true;
    exonThree["LEU"] = true;
    exonThree["TYR"] = true;
    exonThree["ASN"] = true;

    std::list<std::pair<std::string, std::string>> translations = {
        {"Ala", "Alanine"},
        {"Arg", "Arginine"},
        {"Asn", "Asparagine"},
        {"Asp", "Aspartic acid"},
        {"Cys", "Cysteine"},
        {"Gln", "Glutamine"},
        {"Glu", "Glutamic acid"},
        {"Gly", "Glycine"},
        {"His", "Histidine"},
        {"Ile", "Isoleucine"},
        {"Leu", "Leucine"},
        {"Lys", "Lysine"},
        {"Met", "Methionine"},
        {"Phe", "Phenylalanine"},
        {"Pro", "Proline"},
        {"Ser", "Serine"},
        {"Thr", "Threonine"},
        {"Trp", "Tryptophan"},
        {"Tyr", "Tyrosine"},
        {"Val", "Valine"}
    };

    std::string input;

    while (true) {
        std::cout << "Enter a 3-letter amino acid code (or 'quit' to exit): ";
        std::cin >> input;
        
        if (toUpper(input) == "QUIT") break;

        std::string upperInput = toUpper(input);
        std::string titleInput = toTitle(upperInput);

        if (exonThree.find(upperInput) != exonThree.end()) {
            // Found, normal hit look up full name in list
            std::string fullName;
            for (const auto& p : translations) {
                if (p.first == titleInput) {
                    fullName = p.second;
                    break;
                }
            }

            if (fullName.empty()) {
                std::cout << "Normal hit, but translation not found." << std::endl;
            } else {
                std::cout << "Normal: " << fullName << std::endl;
            }
        } else {
            std::cout << "Mutation: Code not found." << std::endl;
        }
    }

    return 0;
}
