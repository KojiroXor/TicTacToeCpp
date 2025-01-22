#include <iostream>
#include <vector>
#include <cstdlib>

void stampaMatrice(const std::string matrice[3][3]) {
    std::cout<<std::endl<<"-----"<<std::endl;
    for (int i=0; i<3; i++) {
        for (int j=0; j<2; j++)
            std::cout<<matrice[i][j]<<"|";
        std::cout<<matrice[i][2];
        std::cout<<std::endl<<"-----"<<std::endl;
    }
}

bool checks(std::string matrice[3][3]) {
    if (matrice[0][0]==matrice[0][1] && matrice[0][1]==matrice[0][2]
        || matrice[0][0]==matrice[1][0] && matrice[1][0]==matrice[2][0]
        || matrice[2][0]==matrice[2][1] && matrice[2][1]==matrice[2][2]
        || matrice[0][2]==matrice[1][2] && matrice[1][2]==matrice[2][2]
        || matrice[0][1]==matrice[1][1] && matrice[1][1]==matrice[2][1]
        || matrice[1][0]==matrice[1][1] && matrice[1][1]==matrice[1][2]
        || matrice[0][0]==matrice[1][1] && matrice[1][1]==matrice[2][2]
        || matrice[0][2]==matrice[1][1] && matrice[1][1]==matrice[2][0])
        return false;
    else return true;
}

int main() {
    int giocata;
    bool Alt=true, Giocatore=true;
    std::cout << "Welcome to Tic Tac Toe!" << std::endl;
    std::string tabella[3][3] = {{"1", "2", "3"}, {"4", "5", "6"}, {"7", "8", "9"}};
    std::string* ptr = &tabella[0][0];
    while (Alt) {
        system("clear");
        stampaMatrice(tabella);
        std::cout<<"Inserisci la tua giocata (1-9): ";
        while (true) {
            std::cin>>giocata;
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore();
                std::cout<<"Inserisci un numero valido: ";
            }
            else if (giocata<1 || giocata>9 || ptr[giocata-1] == "X" || ptr[giocata-1] == "O") {
                std::cout<<"Inserisci un numero valido: ";
            }
            else break;
        }
        if (Giocatore) {
            ptr[giocata-1] = "X";
            Giocatore=false;
        }
        else {
            ptr[giocata-1] = "O";
            Giocatore=true;
        }
        Alt = checks(tabella);
    }
    std::cout<<"Ha vinto giocatore: "<<(!Giocatore ? "X" : "O")<<std::endl;

    return 0;
}