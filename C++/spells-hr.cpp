#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Spell { 
    private:
        string scrollName;
    public:
        Spell(): scrollName("") { }
        Spell(string name): scrollName(name) { }
        virtual ~Spell() { }
        string revealScrollName() {
            return scrollName;
        }
};

class Fireball : public Spell { 
    private: int power;
    public:
        Fireball(int power): power(power) { }
        void revealFirepower(){
            cout << "Fireball: " << power << endl;
        }
};

class Frostbite : public Spell {
    private: int power;
    public:
        Frostbite(int power): power(power) { }
        void revealFrostpower(){
            cout << "Frostbite: " << power << endl;
        }
};

class Thunderstorm : public Spell { 
    private: int power;
    public:
        Thunderstorm(int power): power(power) { }
        void revealThunderpower(){
            cout << "Thunderstorm: " << power << endl;
        }
};

class Waterbolt : public Spell { 
    private: int power;
    public:
        Waterbolt(int power): power(power) { }
        void revealWaterpower(){
            cout << "Waterbolt: " << power << endl;
        }
};

class SpellJournal {
    public:
        static string journal;
        static string read() {
            return journal;
        }
}; 
string SpellJournal::journal = "";

void counterspell(Spell *spell) {

    if(dynamic_cast<Fireball*>(spell))
        static_cast<Fireball*>(spell) -> revealFirepower();
    else if (dynamic_cast<Frostbite*>(spell))
        static_cast<Frostbite*>(spell) -> revealFrostpower();
    else if (dynamic_cast<Thunderstorm*>(spell))
        static_cast<Thunderstorm*>(spell) -> revealThunderpower();
    else if  (dynamic_cast<Waterbolt*>(spell))
        static_cast<Waterbolt*>(spell) -> revealWaterpower();
    else {
        string spellName = spell -> revealScrollName();
        string journalName = SpellJournal::read();
        int i = spellName.length();
        int j = journalName.length();
        cout << length_lcs(spellName, journalName, i, j);
    }

}

int length_lcs(const string& text1, const string& text2, int i, int j){

    if (i == 0 || j == 0){
        return 0;
    }
    if (text1[i-1] == text2[j-1]) {
        return 1 + length_lcs(text1, text2, i-1, j-1);
    } else {
        int without_i = length_lcs(text1, text2, i - 1, j);
        int without_j = length_lcs(text1, text2, i, j - 1);
        return max(without_i, without_j);
    }
}

class Wizard {
    public:
        Spell *cast() {
            Spell *spell;
            string s; cin >> s;
            int power; cin >> power;
            if(s == "fire") {
                spell = new Fireball(power);
            }
            else if(s == "frost") {
                spell = new Frostbite(power);
            }
            else if(s == "water") {
                spell = new Waterbolt(power);
            }
            else if(s == "thunder") {
                spell = new Thunderstorm(power);
            } 
            else {
                spell = new Spell(s);
                cin >> SpellJournal::journal;
            }
            return spell;
        }
};

int main() {
    int T;
    cin >> T;
    Wizard Arawn;
    while(T--) {
        Spell *spell = Arawn.cast();
        counterspell(spell);
    }
    return 0;
}