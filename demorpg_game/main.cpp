#include <iostream>

char* the_map[12][13] = {
    "############",
    "#----------#",
    "#----------#",
    "#----------#",
    "#----------#",
    "#----------#",
    "#----------#",
    "#----------#",
    "#----------#",
    "#----------#",
    "#----------#",
    "############",
};

struct Pipi {
    int x_pos, y_pos;
};


void showmap() {
    // system("CLS"); windows
    for(int i = 0; i < 12; i++) {
        for(int j = 0; j < 13; j++) {
            std::cout << the_map[i][j];
       }
       std::cout << "\n";
    }
}


int main(int argc, char** argv) {
    bool running = true;

    while(running) {
        
        showmap();
    
    }

    return 0;
}