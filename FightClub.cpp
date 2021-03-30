#include <iostream>
#include <string>
#include <chrono>
#include <thread>
using namespace std;

class Fighter;

int mode = 0;
bool quit = false;
int chooseenemy;
int choice;
int modeselect;
int menuchoose;
int choosecharacter;

bool random();
void vsmenu();

class Fighter { //Figther elements
public:
    std::string name;
    int cast;
    int life;
    int abilities[2];
    
    int attack_choice;
    bool status;
    int points;

    
    Fighter() : cast(0), life(0), attack_choice(0), status(false), points(0) {
        abilities[0] = 0;
        abilities[1] = 0;
    }

    
}player_A, COM, player_B;

void playerAfunc() {
    if (player_A.cast == 1) {
        player_A.life = 150;
        player_A.abilities[0] = 4;
        player_A.abilities[1] = 7;

    }
    else if (player_A.cast == 2) {
        player_A.life = 100;
        player_A.abilities[0] = 6;
        player_A.abilities[1] = 11;
    }
    else if (player_A.cast == 3) {
        player_A.life = 80;
        player_A.abilities[0] = 8;
        player_A.abilities[1] = 14;
    }
}
void playerBfunc() {
    if (player_B.cast == 1) {
        player_B.life = 150;
        player_B.abilities[0] = 4;
        player_B.abilities[1] = 7;
    }
    else if (player_B.cast == 2) {
        player_B.life = 100;
        player_B.abilities[0] = 6;
        player_B.abilities[1] = 11;
    }
    else if (player_B.cast == 3) {
        player_B.life = 80;
        player_B.abilities[0] = 8;
        player_B.abilities[1] = 14;
    }
}

class Game_com {
public:
    
    
    void entry() {
        cout << "\nOkay, hold on and defeat your opponent!" << endl; //menu text
        cout << "\nYou have two spells!" << endl
            << "First one(1) is a small but secure attack." << endl <<"It hits almost every time the enemy." << endl
            << "Second one(2) is a big but not so secure attack. It is not successful every time, because it is slower and the enemy can parry it." << endl;
    }
    void start() { //start of the game
        
        //Fighter;
    STARTCHALL:
        cout << "\nThere is three guy in the room. Which one do you want to challenge?" << endl
            << "Warrior(1), Hunter(2) or Mage(3)?\n->";
        cin >> COM.cast;
        if (COM.cast == 1) {
            COM.life = 150;
            COM.abilities[0] = 4;
            COM.abilities[1] = 7;
        }
        else if (COM.cast == 2) {
            COM.life = 100;
            COM.abilities[0] = 6;
            COM.abilities[1] = 11;
        }
        else if (COM.cast == 3) {
            COM.life = 80;
            COM.abilities[0] = 8;
            COM.abilities[1] = 14;
        }
        else {
            cout << "\nInvalid answer! Try again!\n";
            goto STARTCHALL;
        }
        system("cls");
    }
    void chooseenemyfunc() {
        if (chooseenemy == 1) {
            COM.life = 150;
            COM.abilities[0] = 4;
            COM.abilities[1] = 7;
        }
        else if (chooseenemy == 2) {
            COM.life = 100;
            COM.abilities[0] = 6;
            COM.abilities[1] = 11;
        }
        else if (chooseenemy == 3) {
            COM.life = 80;
            COM.abilities[0] = 8;
            COM.abilities[1] = 14;
        }
    }
    
    void game_check() { //check if it is over or not

        quit = false;
        if (player_A.life <= 0 && mode == 1) { // if you lose
            player_A.status = false;
            COM.status = true;
            for (int i = 0; i < 4; i++) {
                cout << "\n";
            }
            cout << "You lose! \n\nPress 1 to restart\nPress 2 to quit to menu (If it goes back to your turn just press (2) again! Here is an error, sorry!)\n-> ";
            
        CHOOSE_COM: //choose: restart or quit
            cin >> choice;
            switch (choice) {
            case 1:
                //COM
                if (COM.cast == 1) {
                    COM.life = 150;
                    COM.abilities[0] = 4;
                    COM.abilities[1] = 7;
                }
                else if (COM.cast == 2) {
                    COM.life = 100;
                    COM.abilities[0] = 6;
                    COM.abilities[1] = 11;
                }
                else if (COM.cast == 3) {
                    COM.life = 80;
                    COM.abilities[0] = 8;
                    COM.abilities[1] = 14;
                }
                //PLAYER_A
                playerAfunc();
                game_com.start();
                break;
            case 2: //if quit
                player_A.life = 0;
                COM.life = 0;
                quit = true;
                
                break;
            default:
                cout << "\nInvalid answer. Type (1) to continue or (2) to quit to menu (If it goes back to your turn just press (2) again! Here is an error, sorry!).\n->";
                goto CHOOSE_COM;
                break;
            }
        }
        else if (COM.life <= 0 && mode == 1) { //if you win
            player_A.status = true;
            COM.status = false;
            for (int i = 0; i < 4; i++) {
                cout << "\n";
            }
            cout << "You win! \n\nPress 1 to restart\nPress 2 to quit to menu (If it goes back to your turn just press (2) again! Here is an error, sorry!)\n-> ";

            CHOOSE_COMS:
            cin >> choice;
            switch (choice) {
            case 1:
                //COM
                chooseenemyfunc();
                
                //PLAYER_A
                playerAfunc();
                
                game_com.start();
                break;
            case 2:
                player_A.life = 0;
                COM.life = 0;
                quit = true;
                
                break;
            default:
                cout << "\nInvalid answer. Type (1) to continue or (2) to quit to menu (If it goes back to your turn just press (2) again! Here is an error, sorry!).\n->";
                goto CHOOSE_COMS;
                break;
            }
        }
    
    }

    void enemy_attack_choice() { // enemy attack funtion
        this_thread::sleep_for(chrono::milliseconds(250));
    CHOICE:
        cout << "\n_____________________" << endl;
        cout << "Enemy's turn!" << endl;
        COM.attack_choice = rand() % 4 + 1; //randomize the attack
        this_thread::sleep_for(chrono::milliseconds(250));
        switch (COM.attack_choice) {

        case 1:
            player_A.life = player_A.life - COM.abilities[0];
            cout << "\nThe enemy damaged you a bit!" << endl;
            break;
        case 2:
            COM.life = COM.life - 2; //parry 1. spell
            cout << "\nYou parried the enemy's spell, and you could push him/her away! Great one!" << endl;
            break;
        case 3:
            player_A.life = player_A.life - COM.abilities[1];
            cout << "\nThe enemy damaged you a lot!" << endl;
            break;
        case 4:
            COM.life = COM.life - 4; //parry 2. spell
            cout << "\nYou parried the enemy's huge spell, and you could hit him/her! You can do it!" << endl;
            break;
        default:
            goto CHOICE;
            break;
        }
        
    }
    bool random() { //simple randomization
        if (rand() % 2 == 0)
            return true;
        else return false;
    }
    void attack_choice() { //player attack
        this_thread::sleep_for(chrono::milliseconds(250));
        game_check();
        string spellone;
        string spelltwo;
        if (player_A.cast == 1) {
            spellone = "Charge";
            spelltwo = "Slam";

        }
        else if (player_A.cast == 2) {
            spellone = "Arcane shot";
            spelltwo = "Marked shot";
        }
        else if (player_A.cast == 3) {
            spellone = "Frostbolt";
            spelltwo = "Fireball";
        }
        
        cout << "_____________________" << endl;
        cout << "Your turn!\n\nWhich spell do you want to use? " << spellone << "(1) or " << spelltwo << "(2)?\n->";
        SPELLACOM:
        cin >> player_A.attack_choice;
        if (player_A.attack_choice != 1 && player_A.attack_choice != 2) {
            cout << "\nInvalid answer. Try again!\n->";
            goto SPELLACOM;
        }
        system("cls");
        this_thread::sleep_for(chrono::milliseconds(250));
        switch (player_A.attack_choice) {
        case 1:
            if (random() == 0) {
                COM.life = COM.life - player_A.abilities[0];
                cout << "\nYou damaged the enemy a bit!" << endl;
            }else{
                player_A.life = player_A.life - 2;
                cout << "\nThe enemy parried your spell, and he/she could push you away!" << endl;
            }
            break;
        case 2:
            if (random() == 0) {
                COM.life = COM.life - player_A.abilities[1];
                cout << "\nYou damaged the enemy a lot!" << endl;
            }
            else {
                player_A.life = player_A.life - 4;
                cout << "\nThe enemy parried your huge spell, and he/she could hit you!" << endl;
            }
            break;
        }
        
        

    }

} game_com;


class Game_vs {
public:

    void entry() {
        this_thread::sleep_for(chrono::milliseconds(250));
        cout << "\nOkay, hold on and defeat your opponent!" << endl; //menu text
        cout << "\nYou have two spells!" << endl
            << "First one(1) is a small but secure attack.\nIt hits almost every time the enemy." << endl
            << "Second one(2) is a big but not so secure attack.\nIt is not successful every time, because it is slower and the enemy can parry it." << endl;
        system("cls");
    }

    void game_check() { //check if it is over or not

        quit = false;
        if (player_A.life <= 0 && mode == 1) { // if 1.player lose
            player_A.status = false;
            player_B.status = true;
            player_B.points++;
            for (int i = 0; i < 4; i++) {
                cout << "\n";
            }
            cout << player_B.name << " win! \n\nPress 1 to quit to menu (If it goes back to your turn just press (2) again! Here is an error, sorry!)\n-> ";

        CHOOSE_COM: //choose: restart or quit
            cin >> choice;
            switch (choice) {
            case 1:
                system("cls");
                player_A.life = 0;
                player_B.life = 0;
                quit = true;
                break;
                
            default:
                cout << "\nInvalid answer. Type (1) to quit to menu (If it goes back to your turn just press (2) again! Here is an error, sorry!).\n->";
                goto CHOOSE_COM;
                break;
            }
            system("cls");
        }
        else if (player_B.life <= 0 && mode == 1) { //if 1.player win
            player_A.status = true;
            player_B.status = false;
            for (int i = 0; i < 4; i++) {
                cout << "\n";
            }
            player_A.points++;
            cout << player_A.name << " win! \n\nPress 1 to quit to menu\n-> ";

            CHOOSE_COMB:
            cin >> choice;
            switch (choice) {
            case 1:
                system("cls");
                player_A.life = 0;
                player_B.life = 0;
                quit = true;
                break;
       
            default:
                cout << "\nInvalid answer. Type (1) to quit to menu.\n->";
                goto CHOOSE_COMB;
                break;
            }
            system("cls");
        }
        
    }

    

    void firstplayer_attack_choice() { //1.player attack
        game_check();
        string spellone;
        string spelltwo;
        if (player_A.cast == 1) {
            spellone = "Charge";
            spelltwo = "Slam";

        }
        else if (player_A.cast == 2) {
            spellone = "Arcane shot";
            spelltwo = "Marked shot";
        }
        else if (player_A.cast == 3) {
            spellone = "Frostbolt";
            spelltwo = "Fireball";
        }
        this_thread::sleep_for(chrono::milliseconds(250));
        cout << "_____________________" << endl;
        
        cout << player_A.name << "'s turn!\n\nWhich spell do you want to use? " << spellone << "(1) or " << spelltwo << "(2)?\n->";
        SPELLA:
        cin >> player_A.attack_choice;
        if (player_A.attack_choice != 1 && player_A.attack_choice != 2) {
            cout << "\nInvalid answer. Try again!\n->";
            goto SPELLA;
        }
        system("cls");
        cout << endl;
        this_thread::sleep_for(chrono::milliseconds(250));
        switch (player_A.attack_choice) {
        case 1:
            if (random() == 0) {
                player_B.life = player_B.life - player_A.abilities[0];
                cout << "You damaged the enemy a bit!" << endl;
            }
            else {
                player_A.life = player_A.life - 2;
                cout << player_B.name <<" parried your spell, and could push you away!" << endl;
            }
            break;
        case 2:
            if (random() == 0) {
                player_B.life = player_B.life - player_A.abilities[1];
                cout << "You damaged the enemy a lot!" << endl;
            }
            else {
                player_A.life = player_A.life - 4;
                cout << player_B.name << " parried your huge spell, and could hit you!" << endl;
            }
            break;
        }
        cout << endl;
    }
        void secondplayer_attack_choice() { //2.player attack
            game_check();
            string spellone;
            string spelltwo;
            if (player_A.cast == 1) {
                spellone = "Charge";
                spelltwo = "Slam";

            }
            else if (player_A.cast == 2) {
                spellone = "Arcane shot";
                spelltwo = "Marked shot";
            }
            else if (player_A.cast == 3) {
                spellone = "Frostbolt";
                spelltwo = "Fireball";
            }
            this_thread::sleep_for(chrono::milliseconds(250));
            cout << "_____________________" << endl;
            cout << player_B.name << "'s turn!\n\nWhich spell do you want to use? (1)" << spellone << " or (2)" << spelltwo << "?\n->";
            SPELLB:
            cin >> player_B.attack_choice;
            if (player_B.attack_choice != 1 && player_B.attack_choice != 2) {
                cout << "\nInvalid answer. Try again!\n->";
                goto SPELLB;
            }
            system("cls");
            this_thread::sleep_for(chrono::milliseconds(250));
            cout << endl;
            switch (player_B.attack_choice) {

            case 1:
                random();
                if (random == 0) {
                    player_A.life = player_A.life - player_B.abilities[0];
                    cout << "You damaged the enemy a bit!" << endl;
                }
                else {
                    player_B.life = player_B.life - 2;
                    cout << player_A.name << " parried your spell, and he/she could push you away!" << endl;
                }
                break;
            case 2:
                random();
                if (random == 0) {
                    player_A.life = player_A.life - player_B.abilities[1];
                    cout << "You damaged the enemy a lot!" << endl;
                }
                else {
                    player_B.life = player_B.life - 4;
                    cout << player_A.name << " parried your huge spell, and he/she could hit you!" << endl;
                }
                break;
            }
            cout << endl;
        }





} game_vs;

bool random() { //simple randomization
    if (rand() % 2 == 0)
        return true;
    else return false;
}

void vsmenu(){
    cout << player_A.name << "'s score: ";
    cout << player_A.points << endl;
    cout << player_B.name << "'s score: "; 
    cout << player_B.points << endl << endl;
    cout << "The fight has begin!\n\n";
    random();
    if (random == 0) {
        cout << player_B.name, "'s turn!\n";
        game_vs.secondplayer_attack_choice();
    }
    else {
        cout << player_A.name, "'s turn!\n";
        game_vs.firstplayer_attack_choice();
    }
    

}


void storymenu() {  // Menu
    system("cls");
    if (player_A.status == true) {
        cout << "What a match! Well done! Go and train with the others too!" << endl;
    }
    if (player_A.status == false) {
        cout << "These guys are not beginners as you can see, but keep training!" << endl
            << "Go and train with the others too! Do not forget: This gym is only for the winners!\n";
    }
    playerAfunc();
    game_com.start(); //NOT SURE IF IT GOES BACK TO INT MAIN
}




int main()
{
    cout << "_______  _________    _______             _________\n"
        << "(  ____ \\\\__   __ /  (____ \\   |\\     /|  \\__   __/\n"
        << "| (    \\/   ) (      | (  \\/   |)     (|     ) (\n"
        << "| (__       | |      | |       | (___) |     | |\n"
        << "|  __)      | |      | | ____  |  ___  |     | |\n"
        << "| (         | |      | | \\ _ ) | (   ) |     | |\n"
        << "|)       ___) (___   | (___) | | )   ( |     | |\n"
        << "|/       \_______ /   (_______) |/     \\|     )_(\n\n"
        << " _______     _                    ______\n"
        << "(  ____ \\   ( \\        | \\    /| (  ___ \\\n"
        << "| (    \\/   | (        | )   ( | | (   ) )\n"
        << "| |         | |        | |   | | | (__/ /\n"
        << "| |         | |        | |   | | |  __  (\n"
        << "| |         | |        | |   | | | (   \\ \\\n"
        << "| (____ /\\  | (____ /\\ | (___) | | )___) )\n"
        << "(_______ /  (_______ / (_______) |/ \\___ /\n";
    cout << "\nLOADING";
    this_thread::sleep_for(1s);
    cout << ".";
    this_thread::sleep_for(1s);
    cout << ".";
    this_thread::sleep_for(1s);
    cout << ".";
    this_thread::sleep_for(1s);
    cout << "\nDONE";
    this_thread::sleep_for(chrono::milliseconds(2000));
    system("cls");
    
    mode = 1; //informations
    MODE:
    cout << "Story mode(1) or 2 player mode(2)?\n->";
    cin >> modeselect;
    if (modeselect != 1 && modeselect != 2) {
        cout << "\nInvalid answer. Try again!\n";
        goto MODE;
    }
//STORY MODE

    if (modeselect == 1) {
        cout << "\nWhat is your name?\n->";
        cin >> player_A.name;
        ACASTCOM:
        cout << "\nWhat kind of character do you want to be?" << endl << "Warrior(1), Hunter(2) or Mage(3)?\n->";
        cin >> player_A.cast;
        if (player_A.cast != 1 && player_A.cast != 2 && player_A.cast != 3) {
            cout << "\nInvalid answer. Try again!\n";
            goto ACASTCOM;
        }
        playerAfunc();
        
        this_thread::sleep_for(chrono::milliseconds(500));
        system("cls");
        cout << "\nWelcome " << player_A.name << "!" << endl; //history
        cout << "\nI see you're new here. Let me lead you around." << endl
            << "This gym has been the most famous in the area for centuries." << endl
            << "Whoever decided to train here left as a true warrior." << endl
            << "Remember, if you feel that you are not able to prepare, leave the gym." << endl
            << "However, if you feel that nothing can stop you, here’s your place. Go fight one of the newcomers." << endl
            << "Welcome in the Fight Club!" << endl;


     //menu
        game_com.entry();
        game_com.start();

    FIGHT_STORY: //fight
        if (quit == true) {
            storymenu();
        }
        game_com.game_check();
        if (quit == true) {
            storymenu();
        }
        

        if (random == 0) {
            cout << "Enemy's turn!\n";
            game_com.enemy_attack_choice();
        }
        else {
            
            game_com.attack_choice();
        }
     //enemy attack
        game_com.enemy_attack_choice();
        cout << "\nYour HP: "<< player_A.life<< " \\ Enemy's HP: "<< COM.life; cout << "\n";
    
        game_com.attack_choice(); // player attack
        cout << "\nYour HP: "<< player_A.life<< " \\ Enemy's HP: "<< COM.life; cout << "\n";
        goto FIGHT_STORY;
    }
//VS MODE
    if (modeselect == 2) {
        system("cls");
        cout << "\nWhat is your name 1. player?\n->";
        cin >> player_A.name;
        ACASTVS:
        cout << "\nWhat kind of character do you want to be?" << endl << "Warrior(1), Hunter(2) or Mage(3)?\n->";
        cin >> player_A.cast;
        if (player_A.cast != 1 && player_A.cast != 2 && player_A.cast != 3) {
            cout << "\nInvalid answer. Try again!\n";
            goto ACASTVS;
        }
        
        playerAfunc();
        system("cls");
        cout << "\nWhat is your name 2. player?" << endl;
        cin >> player_B.name;
        BCAST:
        cout << "\nWhat kind of character do you want to be second player?" << endl << "Warrior(1), Hunter(2) or Mage(3)?\n->";
        cin >> player_B.cast;
        if (player_B.cast != 1 && player_B.cast != 2 && player_B.cast != 3) {
            cout << "\nInvalid answer. Try again!\n";
            goto BCAST;
        }
        playerBfunc();
        system("cls");
        cout << "\nWelcome " << player_A.name << " and " << player_B.name << "!" << endl;
        cout << "\nIt is time show to the gym, who is stronger.\nYou can play with each other as much as you want.\nYour scores will be shown after every match.\nGood luck and have fun!" << endl << endl;
        MENUVS:
        cout << "Menu:\n\n  1. Play\n  2. History\n  3. Choose another character\n\nWhat do you want do? Type the proper number!\n->";
        MENUCHOOSE:
        cin >> menuchoose;
        if (menuchoose == 1) {
            system("cls");
         //menu
            game_vs.entry();
            
        FIGHT_VERSUS: //fight
            game_vs.game_check();
            if (quit == true) {
                goto MENUVS;
            }
            

         //2.player attack
            game_vs.secondplayer_attack_choice();
            cout << player_A.name<< "'s HP: "<< player_A.life<< " \\ " << player_B.name << "'s HP: " << player_B.life; cout << "\n";
        
            game_vs.firstplayer_attack_choice(); // 1. player attack
            cout << player_A.name << "'s HP: " << player_A.life << " \\ " << player_B.name << "'s HP: " << player_B.life; cout << "\n";
            goto FIGHT_VERSUS;



        }
        else if (menuchoose == 2) {
            system("cls");
            cout << "\nHistory of the Fight Club:\n\nMore than 3,000 years ago, the innovative Persians established Zurkhanehs, which were essentially the ancient-world equivalent of modern-day gyms.\nThe word “Zurkhaneh” translates to “house of strength,” and the facilities were strictly for the use of men.\nScholars have described the physical activities there as being a cross between the martial arts and Iranian yoga.\nMen came to the Zurkhaneh to improve their speed, endurance and concentration while also turning themselves into warriors." << endl;
            char back;
            cout << "\nPress 'b' to go back to the menu!\n->";
            BACK:
            cin >> back;
            if (back != 'b') {
                cout << "\nInvalid answer. Try again!\n->" << endl;
                goto BACK;
            }
            system("cls");
            cout << endl;
            goto MENUVS;
        }
        else if (menuchoose == 3) {
            system("cls");
        PLAYER12:
            cout << endl;
            cout << player_A.name << "(1) or " << player_B.name << "(2)?\n->";
            cin >> choosecharacter;
            if (choosecharacter == 1) {
                MENUCHARA:
                cout << "\nWhat kind of character do you want to be?" << endl << "Warrior(1), Hunter(2) or Mage(3)?\n->";
                cin >> player_A.cast;
                if (player_A.cast != 1 && player_A.cast != 2 && player_A.cast != 3) {
                    cout << "\nInvalid answer. Try again!\n";
                    goto MENUCHARA;
                }
                playerAfunc();
            }
            else if (choosecharacter == 2) {
                MENUCHARB:
                cout << "\nWhat kind of character do you want to be second player?" << endl << "Warrior(1), Hunter(2) or Mage(3)?\n->";
                cin >> player_B.cast;
                if (player_B.cast != 1 && player_B.cast != 2 && player_B.cast != 3) {
                    cout << "\nInvalid answer. Try again!\n";
                    goto MENUCHARB;
                }
                playerBfunc();
            }
            else {
                cout << "\nInvalid answer. Try again!\n";
                goto PLAYER12;
            }
            system("cls");
            goto MENUVS;
        }
        else{
            cout << "\nInvalid answer. Try again.\n";
            goto MENUCHOOSE;
        }
        
    }
  


    return 0;
}
