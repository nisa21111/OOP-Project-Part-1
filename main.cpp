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




int main(){


    return 0;
}