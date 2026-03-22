#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <string>

class champion{
    private:
        static int nrInstances;
        const int id;
        
        char* name;
        float health, armor, magicResist, attackDamage,abilityPower;

    public:
        champion();
        champion(const char* n, float hp, float arm, float mr, float ad, float ap);
        champion(const champion& obj);
        ~champion();

        champion& operator=(const champion& obj);
        friend std::ostream& operator<<(std::ostream& out, const champion& obj);
        friend std::istream& operator>>(std::istream& in, champion& obj);

        const int get_id() const { return id;}
        const char* get_name() const {return name;}
        float get_health() const {return health;}
        float get_armour() const {return armor;}
        float get_mr() const {return magicResist;}
        float get_ad() const {return attackDamage;}
        float get_ap() const {return abilityPower;}
        static int get_nrInstances() { return nrInstances;}

        void set_name(const char* n);
        void set_health(float hp){this -> health= hp;}
        void set_abilityPower(float ap){this -> abilityPower= ap;}
        void set_attackDamage(float ad){this -> attackDamage= ad;}
        void set_armor(float arm){this -> armor= arm;}
        void set_magicResist(float mr){this -> magicResist= mr;}

};

int champion::nrInstances =0;

champion::champion() : id(++nrInstances){
    name= new char[8];
    strcpy(name, "Unknown");
    health= 500;
    armor=30;
    magicResist=30;
    attackDamage=55;
    abilityPower=0;
}

champion::champion(const char* n, float hp, float arm, float mr, float ad, float ap) : id(++nrInstances){
    this -> name = new char[strlen(n) +1];
    strcpy(this -> name, n);
    this -> health= hp;
    this -> armor= arm;
    this -> magicResist= mr;
    this -> abilityPower = ap;
    this -> attackDamage =ad;
}

champion::champion(const champion& obj) : id(++nrInstances){
    this -> name= new char[strlen(obj.name)+1];
    strcpy(this -> name, obj.name);
    this -> health = obj.health;
    this -> armor= obj.armor;
    this -> magicResist= obj.magicResist;
    this -> abilityPower= obj.abilityPower;
    this ->attackDamage = obj.attackDamage;
}

champion::~champion(){
    delete[] name;
}

champion& champion:: operator=(const champion& obj){
    if (this == &obj) return *this;

    delete[] this -> name;
    this -> name= new char[strlen(obj.name)+1];
    strcpy(this -> name, obj.name);

    this -> health = obj.health;
    this -> armor= obj.armor;
    this -> magicResist= obj.magicResist;
    this -> abilityPower= obj.abilityPower;
    this ->attackDamage = obj.attackDamage;

    return *this;
}

void champion::set_name(const char* n) {
    if (this -> name != nullptr) delete[] this -> name;
    this -> name = new char[ strlen(n)+1];
    strcpy(this -> name, n);
}

std::ostream& operator << (std::ostream& out, const champion& obj) {
    out << "___ Champion ["<<obj.id<<"] ___"<<"\n";
    out<<"Nume: "<< obj.name <<"\n";
    out<<"HP: "<<obj.health<< " |AD: "<<obj.attackDamage<<" |AP: "<<obj.abilityPower<<"\n";
    out<<"Armor: "<<obj.armor<<" |Magic Resist: "<<obj.magicResist<< "\n";
    return out;
}

std::istream& operator >>(std::istream& in, champion& obj){
    char buffer[100];

    std::cout << "Nume: ";
    in>>std::ws;
    in.getline(buffer, 100);
    obj.set_name(buffer);

    std::cout << "HP: "; in >> obj.health;
    std::cout << "Armor: "; in >> obj.armor;
    std::cout << "MR: "; in >> obj.magicResist;
    std::cout << "AP: "; in >> obj.abilityPower;
    std::cout << "AD: "; in >> obj.attackDamage;

    return in;
}

class item{
    private:
        const int id;
        static int nrInstances;

        char* name;
        float bonusHP;
        float bonusArmor;
        float bonusMR;
        float bonusAD;
        float bonusAP;

    public:

        item();
        item(const char* n, float bhp, float barm, float bmr, float bad, float bap);
        item(const item& obj);
        ~item();

        item& operator=(const item& obj);
        friend std::ostream& operator << (std::ostream& out, const item& obj);
        friend std::istream& operator >> (std::istream& in, item& obj);

        const int get_id() const {return id;}
        const char* get_name() const {return name;}
        float get_bonusHP() const {return bonusHP;}
        float get_bonusArmor() const {return bonusArmor;}
        float get_bonusMR() const {return bonusMR;}
        float get_bonusAD() const {return bonusAD;}
        float get_bonusAP() const {return bonusAP;}

        void set_name (const char* n);

};

int item::nrInstances=0;

item::item(): id(++nrInstances){
    name= new char[8];
    strcpy(name, "No Item");
    bonusHP=0;
    bonusArmor=0;
    bonusMR=0;
    bonusAD=0;
    bonusAP=0;

}

item::item (const char* n, float bhp, float barm, float bmr, float bad, float bap) : id(++nrInstances){
    this -> name = new char[strlen(n) + 1];
    strcpy(this -> name, n);
    this -> bonusHP = bhp;
    this -> bonusArmor = barm;
    this -> bonusMR = bmr;
    this -> bonusAD = bad;
    this -> bonusAP = bap;

}

item::item(const item& obj) : id(++nrInstances){
    this -> name = new char[strlen(obj.name)+1];
    strcpy(this ->name, obj.name);
    this -> bonusHP = obj.bonusHP;
    this -> bonusArmor = obj.bonusArmor;
    this -> bonusMR = obj.bonusMR;
    this -> bonusAD = obj.bonusAD;
    this -> bonusAP = obj.bonusAP;

}

item::~item(){
    delete[] name;
}

item& item::operator=(const item& obj){
    if (this == &obj) return *this;

    delete[] this -> name;
    this -> name = new char[strlen(obj.name)+1];
    strcpy(this -> name, obj.name);

    this -> bonusHP = obj.bonusHP;
    this -> bonusArmor = obj.bonusArmor;
    this -> bonusMR = obj.bonusMR;
    this -> bonusAD = obj.bonusAD;
    this -> bonusAP = obj.bonusAP;

    return *this;

}

void item::set_name(const char* n){
    if(this -> name != nullptr) delete[] this -> name;
    this -> name= new char[strlen(n)+1];
    strcpy(this -> name, n);
}

std::ostream& operator << (std::ostream& out, const item& obj){
    out<<"ITEM: [" << obj.id<< "]: "<<obj.name
       << "(+"<<obj.bonusHP<<" HP, +"<<obj.bonusArmor<<" Armor, +"<<obj.bonusMR<<" MR, +"<<obj.bonusAD<<" AD, +"<<obj.bonusAP<<" AP)";
    return out;
}

std::istream& operator >> (std::istream& in, item& obj){
    char buffer[100];
    std::cout<< "Nume Item: ";
    in >> std::ws;
    in.getline(buffer, 100);
    obj.set_name(buffer);

    std::cout << "Bonus HP: "; in >> obj.bonusHP;
    std::cout << "Bonus Armor : "; in >> obj.bonusArmor;
    std::cout << "Bonus MR: "; in >> obj.bonusMR;
    std::cout << "Bonus AD: "; in >> obj.bonusAD;
    std::cout << "Bonus AP: "; in >> obj.bonusAP;

    return in;

}

class matchupCalculator{
    public:
        static void predictWinner (const champion& c1, const champion& c2){
            float hp1 = c1.get_health();
            float hp2 = c2.get_health();

            float physReduc2= 100.0f / (100.0f + c2.get_armour());
            float magReduc2 = 100.0f / (100.0f + c2.get_mr());

            float physReduc1= 100.0f / (100.0f + c1.get_armour());
            float magReduc1= 100.0f / (100.0f +c1.get_mr());

            std::cout << "\n---SIMULARE DUEL---"<< std::endl;

            int rounds =0;
            while(hp1 >0 && hp2>0 && rounds<100){
                rounds++;

                float dmg1=c1.get_ad()* physReduc2;
                if (rounds %3==0){
                    dmg1 += (c1.get_ap()*1.5f)* magReduc2;
                }
                hp2-=dmg1;

                float dmg2=c2.get_ad()* physReduc1;
                if (rounds %3==0){
                    dmg2 += (c2.get_ap()*1.5f)* magReduc1;
                }
                hp1-=dmg2;
            }
            displayResult(c1, c2, hp1, hp2, rounds);
        }
    private:
        static void displayResult(const champion& c1, const champion& c2, float hp1, float hp2, int r){
            if (hp1 <= 0 && hp2 <=0){
                std::cout<<"DRAW! Ambii campion au murit in runda "<< r<<"\n";
            } else if (hp2 <=0){
                std::cout<<"WINNER! "<<c1.get_name()<<" (HP ramas: "<<std::max(0.0f, hp1)<<")\n";
                std::cout<<"Runde: "<<r<<std::endl;
            } else {
                std::cout<<"WINNER! "<<c2.get_name()<<" (HP ramas: "<<std::max(0.0f, hp2)<<")\n";
                std::cout<<"Runde: "<<r<<std::endl;
            }
        }
};


class player{
    private:
        const int id;
        static int nrInstances;

        char* username;
        champion selectedChampion;
        std::vector<item> inventory;


    public:

        player();
        player(const char* name, const champion& champ);
        player(const player& obj);
        ~player();

        player& operator=(const player& obj);

        const int get_id() const{return id;}
        const char* get_username() const {return username;}
        const champion& get_champion() const {return selectedChampion;}
        static int get_nrInstances() {return nrInstances;}

        void addItem(const item& it);
        void set_username(const char* name);
        champion get_stats_with_items() const;

        friend std::ostream& operator<<(std::ostream& out, const player& obj);
};

int player::nrInstances=0;

player::player() : id(++nrInstances), selectedChampion(){
    username=new char[8];
    strcpy(username, "Guest");
}

player::player(const char* name, const champion& champ) : id(++nrInstances), selectedChampion(champ){
    this -> username = new char[strlen(name) +1];
    strcpy(this -> username, name);
}

player::player(const player& obj) : id(++nrInstances), selectedChampion(obj.selectedChampion){
    this -> username = new char [strlen(obj.username)+1];
    strcpy(this -> username, obj.username);
    this -> inventory = obj.inventory;
}

player::~player(){
    delete[] username;
}

player& player::operator =(const player& obj){
    if(this == &obj) return *this;

    delete[] this -> username;
    this -> username = new char [strlen(obj.username)+1];
    strcpy(this -> username, obj.username);

    this -> selectedChampion = obj.selectedChampion;
    this -> inventory = obj.inventory;

    return *this;
}

void player::addItem(const item& it){
    if (inventory.size() <6){
        inventory.push_back(it);
        std::cout<<"Itemul: "<< it.get_name()<< " a fost adaugat pe "<< username<< ".\n";
    } else {
        std::cout<<" Inventory plin!";
    }
}

void player::set_username(const char* name){
    if( this -> username != nullptr) delete[] this -> username;
    this -> username = new char [strlen(name)+1];
    strcpy(this -> username, name);
}

champion player::get_stats_with_items() const{
    champion temp = selectedChampion;

    for (const auto& it : inventory){
        temp.set_health(temp.get_health() + it.get_bonusHP());
        temp.set_armor(temp.get_armour()+ it.get_bonusArmor());
        temp.set_magicResist(temp.get_mr()+ it.get_bonusMR());
        temp.set_attackDamage(temp.get_ad()+ it.get_bonusAD());
        temp.set_abilityPower(temp.get_ap()+ it.get_bonusAP());
    }
    return temp;
}

std::ostream& operator<<(std::ostream& out, const player& obj){
    out<<"Jucator: "<<obj.username<<" |Champion selectat: "<< obj.selectedChampion.get_name()<<"\n";
    out<<"Iteme echipate: "<< obj.inventory.size();
    return out;
}


class menu{
    private:
        std::vector<champion> availableChampions;
        std::vector<item> availableItems;
        player* p1;
        player* p2;

        void createChapion();
        void createItem();
        void setupPlayer();
        void managePlayerItems();
        void startDuel();
        void displayAvailableChampions();
        void displayAvailableItems();
    public:
        menu();
        ~menu();
        void run();
};

menu::menu(){
    p1= nullptr;
    p2= nullptr;
}

menu::~menu(){
    delete p1;
    delete p2;
}

void menu::createChapion(){
    champion temp;
    std::cin>> temp;
    availableChampions.push_back(temp);
    std::cout<<"Champion adaugat cu succes!\n";
}

void menu::createItem(){
    item temp;
    std::cin>>temp;
    availableItems.push_back(temp);
    std::cout<<"Item adaugat cu succes! \n";
}

void menu::displayAvailableChampions(){
    std::cout<<"\n---LISTA CAMPIONI DISPONIBILI---\n";
    if (availableChampions.empty()){
        std::cout<<"[GOL] Nu exista campioni creati.\n";
        return;
    }
    for (size_t i = 0; i< availableChampions.size(); i++){
        std::cout<< i<< ". "<<availableChampions[i].get_name()
                 << " (HP: "<<availableChampions[i].get_health()<<") \n";
    }
}

void menu::displayAvailableItems(){
    std::cout<<"\n ---LISTA ITEME DISPONIBILE---\n";
    if(availableItems.empty()){
        std::cout<<"[GOL] Nu exista iteme create.\n";
        return;
    }
    for (size_t i=0; i< availableItems.size(); i++){
        std::cout<<i<<". "<<availableItems[i].get_name()<<"\n";
    }
}

void menu::setupPlayer(){
    if(availableChampions.size()<2){
        std::cout<<"Eroare: Trebuie sa creezi cel putin 2 campioni pentru a continua!\n";
        return;
    }

    displayAvailableChampions();

    char name1[50], name2[50];
    int choice1, choice2;

    std::cout<<"Nume Jucator 1: "; std::cin>>name1;
    std::cout<<"Alege ID Champion (0 - "<<availableChampions.size()-1<<"): ";
    std::cin>>choice1;

    std::cout<<"Nume Jucator 2: "; std::cin>>name2;
    std::cout<<"Alege ID Champion (0 - "<<availableChampions.size()-1<<"): ";
    std::cin>>choice2;

    if(choice1 <0 || choice1 >= availableChampions.size()|| choice2< 0 || choice2 >= availableChampions.size()){
        std::cout<<"Index invalid! Reincearca configurarea.\n";
    }

    delete p1; delete p2;
    p1=new player(name1, availableChampions[choice1]);
    p2=new player(name2, availableChampions[choice2]);

    std::cout<<"\nJucatori adaigati cu succes!\n";

}

void menu::managePlayerItems(){
    if (p1==nullptr || p2==nullptr){
        std::cout<<"Eroare: Configureaza jucatorii (Optiunea 3) inainte de a pune iteme!\n";
        return;
    }
    if (availableItems.empty()){
        std::cout<<"Eroare: Nu exista iteme create (Optiunea 2)!\n";
        return;
    }

    int playerChoice;
    std::cout<<"\nCui vrei sa echipezi un itemul?\n1. "<<p1 -> get_username() << "\n2. "<<p2 -> get_username()<<"\nOptiune: ";
    std::cin>>playerChoice;

    displayAvailableItems();

    int itemIdx;
    std::cout<< "Alege INDEX item: ";
    std::cin >> itemIdx;

    if(itemIdx >= 0 && itemIdx < availableItems.size()){
        if(playerChoice == 1) p1 -> addItem(availableItems[itemIdx]);
        else if( playerChoice ==2) p2 -> addItem(availableItems[itemIdx]);
        else std::cout<< "Jucator invalid.\n";
    }else {
        std::cout<<"Index item invalid. \n";
    }
}

void menu::startDuel(){
    if (p1==nullptr || p2==nullptr){
        std::cout<<"Eroare: Jucatorii nu sunt setati!\n";
        return;
    }
    matchupCalculator::predictWinner(p1 -> get_stats_with_items(), p2 -> get_stats_with_items());
}

void menu::run(){
    int option =-1;
    while (option !=0){
        std::cout<<"\n=== LOL MATCHUP ANALYZER ===\n";
        std::cout<<"1. Creaza Campion\n";
        std::cout<<"2. Creaza Item\n";
        std::cout<<"3. Alege Campioni pentru jucatori\n";
        std::cout<<"4. Echipare Item\n";
        std::cout<<"5. --- SIMULEAZA DUEL ---\n";
        std::cout<<"0. Iesire\n";
        std::cout<< "===============\n";
        std::cout<<"Alege: ";
        std::cin>>option;

        switch (option)
        {
            case 1: createChapion(); break;
            case 2: createItem(); break;
            case 3: setupPlayer(); break;
            case 4: managePlayerItems(); break;
            case 5: startDuel(); break;
            case 0: std::cout<<"La Revedere!\n"; break;
            default: std::cout<<"Optiune invalida.\n";
        }
    }
}


int main(){

    menu app;
    app.run();
    return 0;
}