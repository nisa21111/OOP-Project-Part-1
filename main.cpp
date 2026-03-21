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


int main(){

    
    return 0;
}