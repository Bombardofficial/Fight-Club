#include <iostream>
#include <string>

using namespace std;

//class Ability;
class Fighter;
//class Enemy;

int mode = 0;
bool quit = false;
int chooseenemy;
int choice;
int modeselect;
int menuchoose;
int choosecharachter;

class Game_com {
    //Fighter fight;
    //Enemy enemy;
    void entry() {
        cout << "Okay, hold on and defeat your opponent!" << endl; //menu text
        cout << "You have two spells!" << endl
            << "First one(1) is a small but secure attack. It hits almost every time the enemy." << endl
            << "Second one(2) is a big but not so secure attack. It is not successful every time, because it is slower and the enemy can parry it." << endl;
    }
    void start() { //start of the game
        Fighter;
        CHOOSEENEMY:
        cout << "There is three guy in the room. Which one do you want to challenge?" << endl
            << "Warrior(1), Hunter(2) or Mage(3)?" << endl;
        cin >> COM.cast;
        if (COM.cast == 1) {
            COM.life = 150;
            COM.abilities[1] = 4;
            COM.abilities[2] = 7;
        }
        else if (COM.cast == 2) {
            COM.life = 100;
            COM.abilities[1] = 6;
            COM.abilities[2] = 11;
        }
        else if (player_A.cast == 3) {
            COM.life = 80;
            COM.abilities[1] = 8;
            COM.abilities[2] = 14;
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
            cout << "You lose! \n\nPress 1 to restart\nPress 2 to quit to menu\n-> ";
            
        CHOOSE_COM: //choose: restart or quit
            cin >> choice;
            switch (choice) {
            case 1:
                //COM
                if (COM.cast == 1) {
                    COM.life = 150;
                    COM.abilities[1] = 4;
                    COM.abilities[2] = 7;
                }
                else if (COM.cast == 2) {
                    COM.life = 100;
                    COM.abilities[1] = 6;
                    COM.abilities[2] = 11;
                }
                else if (COM.cast == 3) {
                    COM.life = 80;
                    COM.abilities[1] = 8;
                    COM.abilities[2] = 14;
                }
                //PLAYER_A
                if (player_A.cast == 1) {
                    player_A.life = 150;
                    player_A.abilities[1] = 4;
                    player_A.abilities[2] = 7;

                }
                else if (player_A.cast == 2) {
                    player_A.life = 100;
                    player_A.abilities[1] = 6;
                    player_A.abilities[2] = 11;
                }
                else if (player_A.cast == 3) {
                    player_A.life = 80;
                    player_A.abilities[1] = 8;
                    player_A.abilities[2] = 14;
                }
                Game_com start();
                break;
            case 2: //if quit
                player_A.life = 0;
                COM.life = 0;
                quit = true;
                break;
            default:
                cout << "Invalid answer. Type (1) to continue or (2) to quit to menu." << endl;
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
            cout << "You win! \n\nPress 1 to restart\nPress 2 to quit to menu\n-> ";

        CHOOSE:
            cin >> choice;
            switch (choice) {
            case 1:
                //COM
                if (chooseenemy == 1) {
                    COM.life = 150;
                    COM.abilities[1] = 4;
                    COM.abilities[2] = 7;
                }
                else if (chooseenemy == 2) {
                    COM.life = 100;
                    COM.abilities[1] = 6;
                    COM.abilities[2] = 11;
                }
                else if (chooseenemy == 3) {
                    COM.life = 80;
                    COM.abilities[1] = 8;
                    COM.abilities[2] = 14;
                }
                //PLAYER_A
                if (player_A.cast == 1) {
                    player_A.life = 150;
                    player_A.abilities[1] = 4;
                    player_A.abilities[2] = 7;

                }
                else if (player_A.cast == 2) {
                    player_A.life = 100;
                    player_A.abilities[1] = 6;
                    player_A.abilities[2] = 11;
                }
                else if (player_A.cast == 3) {
                    player_A.life = 80;
                    player_A.abilities[1] = 8;
                    player_A.abilities[2] = 14;
                }
                Game_com start();
                break;
            case 2:
                player_A.life = 0;
                COM.life = 0;
                quit = true;
                break;
            default:
                cout << "Invalid answer. Type (1) to continue or (2) to quit to menu." << endl;
                goto CHOOSE_COM;
                break;
            }
        }
    
    }
    void enemy_attack_choice() { // enemy attack funtion
    CHOICE:
        COM.attack_choice = rand() % 4 + 1; //randomize the attack
        switch (COM.attack_choice) {

        case 1:
            player_A.life = player_A.life - COM.abilities[1];
            cout << "The enemy damaged you a bit!" << endl;
            break;
        case 2:
            COM.life = COM.life - 2; //parry 1. spell
            cout << "You parried the enemy's spell, and you could push him/her away! Great one!" << endl;
            break;
        case 3:
            player_A.life = player_A.life - COM.abilities[2];
            cout << "The enemy damaged you a lot!" << endl;
            break;
        case 4:
            COM.life = COM.life - 4; //parry 2. spell
            cout << "You parried the enemy's huge spell, and you could hit him/her! You can do it!" << endl;
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
        cout << "Your turn!\nWhich spell do you want to use? (1)", spellone, " or (2)", spelltwo, "?\n";
        cin >> player_A.attack_choice;
        switch (player_A.attack_choice) {
        case 1:
            random();
            if (random == 0) {
                COM.life = COM.life - player_A.abilities[1];
                cout << "You damaged the enemy a bit!" << endl;
            }else{
                player_A.life = player_A.life - 2;
                cout << "The enemy parried your spell, and he/she could push you away!" << endl;
            }
            break;
        case 2:
            random();
            if (random == 0) {
                COM.life = COM.life - player_A.abilities[2];
                cout << "You damaged the enemy a lot!" << endl;
            }
            else {
                player_A.life = player_A.life - 4;
                cout << "The enemy parried your spell, and he/she could hit you!" << endl;
            }
            break;
        }
        
        

    }

};
/*
class Enemy {
    
public:
    Enemy(int enemylife, int consumption,std::string name);
    virtual~Enemy();
    void consumeEnergy();
    std::string getName() const;

protected:

    int enemylife;
    int curEnergy;
    int consumption;
    std::string name;

    private:



};
*/



class Fighter { //Figther elements
public:
    std::string name;
    int cast;
    int life;
    int abilities[2];
    //Ability* abilities[2];
    int attack_choice;
    bool status;
    int points;

    // milyen tulajdonságai vannak még.


    // konstruktor
    //void decreaseLife(int delta);
    // ...
}player_A, COM, player_B;
/*
void Fighter::decreaseLife(int delta) {
    COM.life -= delta;
}

class Ability {
public:
    virtual void execute(Fighter* enemy) = 0;
};

class SmallButSecureAttack : public Ability {
public:
    void execute(Fighter* enemy) {
        enemy->decreaseLife(1);
    }
};
*/

class Game_vs {

    void entry() {
        cout << "Okay, hold on and defeat your opponent!" << endl; //menu text
        cout << "You have two spells!" << endl
            << "First one(1) is a small but secure attack. It hits almost every time the enemy." << endl
            << "Second one(2) is a big but not so secure attack. It is not successful every time, because it is slower and the enemy can parry it." << endl;
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
            cout << "2.player win! \n\nPress 1 to restart\nPress 2 to quit to menu\n-> ";

        CHOOSE_COM: //choose: restart or quit
            cin >> choice;
            switch (choice) {
            case 1:
                //player_B
                if (player_B.cast == 1) {
                    player_B.life = 150;
                    player_B.abilities[1] = 4;
                    player_B.abilities[2] = 7;
                }
                else if (player_B.cast == 2) {
                    player_B.life = 100;
                    player_B.abilities[1] = 6;
                    player_B.abilities[2] = 11;
                }
                else if (player_B.cast == 3) {
                    player_B.life = 80;
                    player_B.abilities[1] = 8;
                    player_B.abilities[2] = 14;
                }
                //PLAYER_A
                if (player_A.cast == 1) {
                    player_A.life = 150;
                    player_A.abilities[1] = 4;
                    player_A.abilities[2] = 7;

                }
                else if (player_A.cast == 2) {
                    player_A.life = 100;
                    player_A.abilities[1] = 6;
                    player_A.abilities[2] = 11;
                }
                else if (player_A.cast == 3) {
                    player_A.life = 80;
                    player_A.abilities[1] = 8;
                    player_A.abilities[2] = 14;
                }
                vsmenu();
                break;
            case 2: //if quit
                player_A.life = 0;
                player_B.life = 0;
                quit = true;
                break;
            default:
                cout << "Invalid answer. Type (1) to continue or (2) to quit to menu." << endl;
                goto CHOOSE_COM;
                break;
            }
        }
        else if (player_B.life <= 0 && mode == 1) { //if 1.player win
            player_A.status = true;
            player_B.status = false;
            for (int i = 0; i < 4; i++) {
                cout << "\n";
            }
            player_A.points++;
            cout << "1. Player win! \n\nPress 1 to restart\nPress 2 to quit to menu\n-> ";

        CHOOSE:
            cin >> choice;
            switch (choice) {
            case 1:
                //PLAYER_B
                if (chooseenemy == 1) {
                    player_B.life = 150;
                    player_B.abilities[1] = 4;
                    player_B.abilities[2] = 7;
                }
                else if (chooseenemy == 2) {
                    player_B.life = 100;
                    player_B.abilities[1] = 6;
                    player_B.abilities[2] = 11;
                }
                else if (chooseenemy == 3) {
                    player_B.life = 80;
                    player_B.abilities[1] = 8;
                    player_B.abilities[2] = 14;
                }
                //PLAYER_A
                if (player_A.cast == 1) {
                    player_A.life = 150;
                    player_A.abilities[1] = 4;
                    player_A.abilities[2] = 7;

                }
                else if (player_A.cast == 2) {
                    player_A.life = 100;
                    player_A.abilities[1] = 6;
                    player_A.abilities[2] = 11;
                }
                else if (player_A.cast == 3) {
                    player_A.life = 80;
                    player_A.abilities[1] = 8;
                    player_A.abilities[2] = 14;
                }
                vsmenu();
                break;
            case 2:
                player_A.life = 0;
                player_B.life = 0;
                quit = true;
                break;
            default:
                cout << "Invalid answer. Type (1) to continue or (2) to quit to menu." << endl;
                goto CHOOSE_COM;
                break;
            }
        }

    }

    

    void firstplayer_attack_choice() { //1.player attack
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
        cout << player_A.name, "'s turn!\nWhich spell do you want to use? (1)",spellone," or (2)", spelltwo, "?\n";
        cin >> player_A.attack_choice;
        switch (player_A.attack_choice) {
        case 1:
            random();
            if (random == 0) {
                player_B.life = player_B.life - player_A.abilities[1];
                cout << "You damaged the enemy a bit!" << endl;
            }
            else {
                player_A.life = player_A.life - 2;
                cout << "The enemy parried your spell, and could push you away!" << endl;
            }
            break;
        case 2:
            random();
            if (random == 0) {
                player_B.life = player_B.life - player_A.abilities[2];
                cout << "You damaged the enemy a lot!" << endl;
            }
            else {
                player_A.life = player_A.life - 4;
                cout << "The enemy parried your spell, and could hit you!" << endl;
            }
            break;
        }
    }
        void secondplayer_attack_choice() { //2.player attack
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
            cout << player_B.name, "'s turn!\nWhich spell do you want to use? (1)", spellone, " or (2)", spelltwo, "?\n";
            cin >> player_B.attack_choice;
            switch (player_B.attack_choice) {

            case 1:
                random();
                if (random == 0) {
                    player_A.life = player_A.life - player_B.abilities[1];
                    cout << "You damaged the enemy a bit!" << endl;
                }
                else {
                    player_B.life = player_B.life - 2;
                    cout << "The enemy parried your spell, and he/she could push you away!" << endl;
                }
                break;
            case 2:
                random();
                if (random == 0) {
                    player_A.life = player_A.life - player_B.abilities[2];
                    cout << "You damaged the enemy a lot!" << endl;
                }
                else {
                    player_B.life = player_B.life - 4;
                    cout << "The enemy parried your spell, and he/she could hit you!" << endl;
                }
                break;
            }

        }





};

bool random() { //simple randomization
    if (rand() % 2 == 0)
        return true;
    else return false;
}
/// <summary>
/// HIBA VAN ITT EZT MÉG MEG KELL OLDANI  ILLETVE MÉG A SPELLEK VÁLTOZATOSSÁGÁT KELL CASTONKÉNT ÉS TALÁN ENNYI
/// </summary>

void vsmenu(){
    cout << player_A.name, "'s score: ";
    cout << player_A.points << endl;
    cout << player_B.name, "'s score: "; 
    cout << player_B.points << endl << endl;
    cout << "The fight has begin!\n\n";
    random();
    if (random == 0) {
        cout << player_B.name, "'s turn!\n";
        Game_vs secondplayer_attack_choice();
    }
    else {
        cout << player_A.name, "'s turn!\n";
        Game_vs firstplayer_attack_choice();
    }
    

}


void storymenu() {  // Menu
    if (player_A.status == true) {
        cout << "What a match! Well done! Go and train with the others too!" << endl;
    }
    if (player_A.status == false) {
        cout << "These guys are not beginners as you can see, but keep training!" << endl
            << "Go and train with the others too! Do not forget: This gym is only for the winners!";
    }
    Game_com start(); //NOT SURE IF IT GOES BACK TO INT MAIN
}




int main()
{
    START:
    Game_com;
    //string name;
    //int choosecast;
    mode = 1; //informations
    
    cout << "Story mode(1) or 2 player mode(2)?" << endl;
    cin >> modeselect;

//STORY MODE
    if (modeselect == 1) {
        cout << "What is your name?" << endl;
        cin >> player_A.name;
        cout << "What kind of character do you want to be?" << endl << "Warrior(1), Hunter(2) or Mage(3)?" << endl;
        cin >> player_A.cast;
        if (player_A.cast == 1) {
            player_A.life = 150;
            player_A.abilities[1] = 4;
            player_A.abilities[2] = 7;
        }
        else if (player_A.cast == 2) {
            player_A.life = 100;
            player_A.abilities[1] = 6;
            player_A.abilities[2] = 11;
        }
        else if (player_A.cast == 3) {
            player_A.life = 80;
            player_A.abilities[1] = 8;
            player_A.abilities[2] = 14;
        }
        cout << "Welcome " << player_A.name << "!" << endl; //history
        cout << "I see you're new here. Let me lead you around." << endl
            << "This gym has been the most famous in the area for centuries." << endl
            << " Whoever decided to train here left as a true warrior." << endl
            << "Remember, if you feel that you are not able to prepare, leave the gym." << endl
            << "However, if you feel that nothing can stop you, here’s your place. Go fight one of the newcomers." << endl
            << "Welcome in the Fight Club!" << endl;


    MENU: //menu
        Game_com entry();
        Game_com start();

    FIGHT: //fight
        Game_com game_check();
        if (quit == true) {
            storymenu();
        }
        system("cls"); // clean

        if (random == 0) {
            cout << "Enemy's turn!\n";
            Game_com enemy_attack_choice();
        }
        else {
            cout << "Your turn!\n";
            Game_com attack_choice();
        }
    ENEMY: //enemy attack
        Game_com enemy_attack_choice();
        cout << "Your HP: ", player_A.life, " \\ Enemy's HP: ", COM.life; cout << "\n";
    YOU:
        Game_com attack_choice(); // player attack
        cout << "Your HP: ", player_A.life, " \\ Enemy's HP: ", COM.life; cout << "\n";
        goto FIGHT;
    }
//VS MODE
    if (modeselect == 2) {
        cout << "What is your name 1. player?" << endl;
        cin >> player_A.name;
        cout << "What kind of character do you want to be?" << endl << "Warrior(1), Hunter(2) or Mage(3)?" << endl;
        cin >> player_A.cast;
        if (player_A.cast == 1) {
            player_A.life = 150;
            player_A.abilities[1] = 4;
            player_A.abilities[2] = 7;
        }
        else if (player_A.cast == 2) {
            player_A.life = 100;
            player_A.abilities[1] = 6;
            player_A.abilities[2] = 11;
        }
        else if (player_A.cast == 3) {
            player_A.life = 80;
            player_A.abilities[1] = 8;
            player_A.abilities[2] = 14;
        }
        cout << "What is your name 2. player?" << endl;
        cin >> player_B.name;
        cout << "What kind of character do you want to be second player?" << endl << "Warrior(1), Hunter(2) or Mage(3)?" << endl;
        cin >> player_B.cast;
        if (player_B.cast == 1) {
            player_B.life = 150;
            player_B.abilities[1] = 4;
            player_B.abilities[2] = 7;
        }
        else if (player_B.cast == 2) {
            player_B.life = 100;
            player_B.abilities[1] = 6;
            player_B.abilities[2] = 11;
        }
        else if (player_B.cast == 3) {
            player_B.life = 80;
            player_B.abilities[1] = 8;
            player_B.abilities[2] = 14;
        }
        cout << "Welcome " << player_A.name << " and " << player_B.name << "!" << endl;
        cout << "It is time show to the gym, who is stronger.\nYou can play with each other as much as you want.\nYour scores will be shown after every match.\nGood luck and have fun!" << endl << endl;
        MENUVS:
        cout << "Menu:\n1. Play\n2. History\n3. Choose another charachter\n\nWhat do you want do? Type the proper number." << endl;
        MENUCHOOSE:
        cin >> menuchoose;
        if (menuchoose == 1) {

        MENU: //menu
            Game_vs entry();
            
        FIGHT: //fight
            Game_vs game_check();
            if (quit == true) {
                goto MENUVS;
            }
            system("cls"); // clean

        SECONDPLAYER: //2.player attack
            Game_vs enemy_attack_choice();
            cout << player_A.name, "'s HP: ", player_A.life, " \\ ", player_B.name, "'s HP: ", player_B.life; cout << "\n";
        FIRSTPLAYER:
            Game_vs attack_choice(); // 1. player attack
            cout << player_A.name, "'s HP: ", player_A.life, " \\ ", player_B.name, "'s HP: ", player_B.life; cout << "\n";
            goto FIGHT;



        }
        else if (menuchoose == 2) {
            cout << "History of the Fight Club:\n\nMore than 3,000 years ago, the innovative Persians established Zurkhanehs, which were essentially the ancient-world equivalent of modern-day gyms.\nThe word “Zurkhaneh” translates to “house of strength,” and the facilities were strictly for the use of men.\nScholars have described the physical activities there as being a cross between the martial arts and Iranian yoga.\nMen came to the Zurkhaneh to improve their speed, endurance and concentration while also turning themselves into warriors." << endl;
        }
        else if (menuchoose == 3) {
            cout << "1. player(1) or 2. player(2)?" << endl;
            cin >> choosecharachter;
            if (choosecharachter == 1) {
                cout << "What kind of character do you want to be?" << endl << "Warrior(1), Hunter(2) or Mage(3)?" << endl;
                cin >> player_A.cast;
                if (player_A.cast == 1) {
                    player_A.life = 150;
                    player_A.abilities[1] = 4;
                    player_A.abilities[2] = 7;
                }
                else if (player_A.cast == 2) {
                    player_A.life = 100;
                    player_A.abilities[1] = 6;
                    player_A.abilities[2] = 11;
                }
                else if (player_A.cast == 3) {
                    player_A.life = 80;
                    player_A.abilities[1] = 8;
                    player_A.abilities[2] = 14;
                }
            }
            else if (choosecharachter == 2) {
                cout << "What kind of character do you want to be second player?" << endl << "Warrior(1), Hunter(2) or Mage(3)?" << endl;
                cin >> player_B.cast;
                if (player_B.cast == 1) {
                    player_B.life = 150;
                    player_B.abilities[1] = 4;
                    player_B.abilities[2] = 7;
                }
                else if (player_B.cast == 2) {
                    player_B.life = 100;
                    player_B.abilities[1] = 6;
                    player_B.abilities[2] = 11;
                }
                else if (player_B.cast == 3) {
                    player_B.life = 80;
                    player_B.abilities[1] = 8;
                    player_B.abilities[2] = 14;
                }
            }
        }
        else{
            cout << "Invalid answer. Try again." << endl;
            goto MENUCHOOSE;
        }
        
    }
  
   
        
    
    


    return 0;
}
