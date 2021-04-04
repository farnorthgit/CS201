//
//  main.cpp
//  HW6 hangman
//
//  Created by Mark Billingsley on 4/3/21.
//

#include <iostream>
using std::cout;
using std::endl;

void drawHangMan (int x) {
    cout << "   _____\n";
    cout << "  :     :\n";
    switch (x) {
        case 0:
            cout << "  :\n";
            cout << "  :\n";
            cout << "  :\n";
            cout << "  :\n";
            break;
        case 1:
            cout << "  :     O\n";
            cout << "  :\n";
            cout << "  :\n";
            cout << "  :\n";
            break;
        case 2:
            cout << "  :     O\n";
            cout << "  :     :\n";
            cout << "  :     :\n";
            cout << "  :\n";
            break;
        case 3:
            cout << "  :     O\n";
            cout << "  :    \\:\n";
            cout << "  :     :\n";
            cout << "  :\n";
            break;
        case 4:
            cout << "  :     O\n";
            cout << "  :    \\:/\n";
            cout << "  :     :\n";
            cout << "  :\n";
            break;
        case 5:
            cout << "  :     O\n";
            cout << "  :    \\:/\n";
            cout << "  :     :\n";
            cout << "  :    /\n";
            break;
        case 6:
            cout << "  :     O\n";
            cout << "  :    \\:/\n";
            cout << "  :     :\n";
            cout << "  :    / \\\n";
            break;
        case 7:
            cout << "  :   _ O\n";
            cout << "  :    \\:/\n";
            cout << "  :     :\n";
            cout << "  :    / \\\n";
            break;
        case 8:
            cout << "  :   _ O _\n";
            cout << "  :    \\:/\n";
            cout << "  :     :\n";
            cout << "  :    / \\\n";
            break;
        case 9:
            cout << "  :   _ O _\n";
            cout << "  :    \\:/\n";
            cout << "  :     :\n";
            cout << "  :   _/ \\\n";
            break;
        case 10:
            cout << "  :   _ O _\n";
            cout << "  :    \\:/\n";
            cout << "  :     :\n";
            cout << "  :   _/ \\_\n";
            break;
    }
    cout << "  :\n";
    cout << "__:__\n";
}
int main() {
    drawHangMan (0);
    drawHangMan (1);
    drawHangMan (2);
    drawHangMan (3);
    drawHangMan (4);
    drawHangMan (5);
    drawHangMan (6);
    drawHangMan (7);
    drawHangMan (8);
    drawHangMan (9);
    drawHangMan (10);

    return 0;
}
