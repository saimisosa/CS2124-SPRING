/*Saimanasa Juluru
 * CS2124
 * Lab 10
 * 04/10/20
 * */

#include <iostream>
#include <vector>
using namespace std;

class Instrument {
public:
    Instrument() {}
    virtual void makeSound() const = 0 ;
    virtual void playNormal() const = 0;

};

//Sub Classes - Level 1

class Brass : public Instrument{
public:
    Brass(unsigned mouthpiece) : mouthpiece(mouthpiece){}

    void makeSound() const {
        cout << "To make a sound... blow on a mouthpiece of size "
             << mouthpiece << "." << endl;
    }

private:
    unsigned mouthpiece; // mouthpiece
};

class String : public Instrument{
public:
    String(unsigned pitch) : pitch(pitch){}

    void makeSound() const {
        cout << "To make a sound... bow a string with pitch "
             << pitch << "." << endl;
    }

private:
    unsigned pitch = 0; // pitch
};


class Percussion : public Instrument{
public:
    void makeSound() const {
        cout << "To make a sound... hit me!" << endl;
    }
};

//Sub Classes - Level 2

class Cello : public String{
public:
    Cello(unsigned pitch) : String(pitch){}
    //using String::makeSound;
    void playNormal() const {
        cout << "Squawk";
    }
};

class Violin : public String{
public:
    Violin(unsigned pitch) : String(pitch){}
    //using String::makeSound;
    void playNormal() const {
        cout << "Screech";
    }
};

class Trombone : public Brass {
public:
    Trombone(unsigned mouthpiece) : Brass(mouthpiece){}
    //using Brass::makeSound;
    void playNormal() const {
        cout << "Blat";
    }
};

class Trumpet : public Brass {
public:
    Trumpet(unsigned mouthpiece) : Brass(mouthpiece){}
    //using Brass::makeSound;
    void playNormal() const {
        cout << "Toot";
    }
};

class Cymbal : public Percussion {
public:
    //using Percussion::makeSound;
    void playNormal() const {
        cout << "Crash";
    }
};

class Drum : public Percussion {
public:
    //using Percussion::makeSound;
    void playNormal() const {
        cout << "Boom";
    }
};

class Musician {
public:
    Musician() : instr(nullptr) {}

    void acceptInstr(Instrument* instPtr) { instr = instPtr; }

    Instrument* giveBackInstr() {
        Instrument* result(instr);
        instr = nullptr;
        return result;
    }

    void testPlay() const {
        if (instr) instr->makeSound();
        else cerr << "have no instr\n";
    }

    void playMusic() const {
        if( instr != NULL ) {
            instr->playNormal();
        }
    }

private:
    Instrument* instr;
};

class MILL {
public:

    void receiveInstr(Instrument& instrument){
        for (int i = 0; i < library.size(); i++){
            if (library[i] == nullptr){
                library[i] = &instrument;
                return;
            }
        }
        library.push_back(&instrument);
    }

    Instrument* loanOut() {
        Instrument* loaned;
        if (library.size() != 0){
            for (int i = 0; i < library.size(); i++){
                if (library[i] != nullptr){
                    loaned = library[i];
                    library[i] = nullptr;
                    return loaned;
                }
            }
        }
    }

    void dailyTestPlay() const {
        for (const Instrument *instr : library){
            if (instr != nullptr){
                instr->makeSound();
            }
        }
    }

private:
    vector<Instrument*> library;
};

class Orch {
public:

    void addPlayer( Musician& guy ) {
        for( size_t i = 0; i < muse.size(); i++ ) {
            if( muse[i] == nullptr ) {
                muse[i] = &guy;
            }
        }
        muse.push_back(&guy);
    }
    void play() const {
        for( size_t i = 0; i < muse.size(); i++ ) {
            if( muse[i] != nullptr ) {
                muse[i]->playMusic();
            }
        }
        cout << endl;
    }
private:
    vector<Musician*> muse;
};



int main() {
    cout << "Define some instruments ------------------------------------\n";
    Drum drum;
    Cello cello(673);
    Cymbal cymbal;
    Trombone tbone(4);
    Trumpet trpt(12) ;
    Violin violin(567) ;

    // use the debugger to look at the mill
    cout << "Define the MILL --------------------------------------------\n";
    MILL mill;

    cout << "Put the instruments into the MILL --------------------------\n";
    mill.receiveInstr(trpt);
    mill.receiveInstr(violin);
    mill.receiveInstr(tbone);
    mill.receiveInstr(drum);
    mill.receiveInstr(cello);
    mill.receiveInstr(cymbal);

    cout << "Daily test -------------------------------------------------\n";
    cout << endl;
    cout << "dailyTestPlay()" << endl;
    mill.dailyTestPlay();
    cout << endl;

    cout << "Define some Musicians---------------------------------------\n";
    Musician harpo;
    Musician groucho;

    cout << "TESTING: groucho.acceptInstr(mill.loanOut());---------------\n";
    groucho.testPlay();
    cout << endl;
    groucho.acceptInstr(mill.loanOut());
    cout << endl;
    groucho.testPlay();
    cout << endl;
    cout << "dailyTestPlay()" << endl;
    mill.dailyTestPlay();

    cout << endl << endl;

    groucho.testPlay();
    cout << endl;
    mill.receiveInstr(*groucho.giveBackInstr());
    harpo.acceptInstr(mill.loanOut());
    groucho.acceptInstr(mill.loanOut());
    cout << endl;
    groucho.testPlay();
    cout << endl;
    harpo.testPlay();
    cout << endl;
    cout << "dailyTestPlay()" << endl;
    mill.dailyTestPlay();

    cout << "TESTING: mill.receiveInstr(*groucho.giveBackInstr()); ------\n";

    // fifth
    mill.receiveInstr(*groucho.giveBackInstr());
    cout << "TESTING: mill.receiveInstr(*harpo.giveBackInstr()); ------\n";
    mill.receiveInstr(*harpo.giveBackInstr());


    cout << endl;
    cout << "dailyTestPlay()" << endl;
    mill.dailyTestPlay();
    cout << endl;

    cout << endl;

} // main

