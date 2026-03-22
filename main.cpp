#include <iostream>
#include <cstring>

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


int main(){


    return 0;
}