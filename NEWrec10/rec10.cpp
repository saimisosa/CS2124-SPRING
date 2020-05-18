/*Saimanasa Juluru
 * CS2124
 * Lab 10
 * 04/10/20
 * */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Instrument {
public:
    //Instrument() {}
    virtual void makeSound() const = 0 ;
    virtual void playNormal() const = 0;

};
// since this part of the sentence is common...
void Instrument::makeSound() const {
    cout << "To make a sound...";
}

//Sub Classes - Level 1

class Brass : public Instrument{
public:
    Brass(unsigned mouthpiece) : mouthpiece(mouthpiece){}

    void makeSound() const {
        Instrument::makeSound(); // calls the common part of the code
        cout << " blow on a mouthpiece of size "
             << mouthpiece << "." << endl;
    }

private:
    unsigned mouthpiece; // mouthpiece
};

class String : public Instrument{
public:
    String(unsigned pitch) : pitch(pitch){}

    void makeSound() const {
        Instrument::makeSound(); // calls the common part of the code
        cout << " bow a string with pitch "
             << pitch << "." << endl;
    }

private:
    unsigned pitch = 0; // pitch
};


class Percussion : public Instrument{
public:
    void makeSound() const {
        Instrument::makeSound(); // calls the common part of the code
        cout << " hit me!" << endl;
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
        if( instr ) {
            instr->playNormal();
        }
    }

private:
    Instrument* instr;
};

class MILL {
public:

    void receiveInstr(Instrument& instrument){
        instrument.makeSound();
        for (size_t i = 0; i < library.size(); ++i){
            if (library[i] == nullptr) {
                library[i] = &instrument;
                return;
            }
        }

        library.push_back(&instrument);
    }

    Instrument* loanOut() {
        Instrument* loaned;

        if (library.size() != 0) {
            for (size_t i = 0; i < library.size(); i++){
                if (library[i] != nullptr){
                    loaned = library[i];
                    library[i] = nullptr;
                    return loaned;
                }
            }
            return nullptr;
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
            if( &guy == muse[i] ) {
                cerr << "This person is already in the Orchestra!" << endl;
                return;
            }
        }
        muse.push_back(&guy);
    }
    void play() const {
        for( size_t i = 0; i < muse.size(); i++ ) {
            muse[i]->playMusic();
        }
        cout << endl;
    }
private:
    vector<Musician*> muse;
};

int main() {
    // The initialization phase

    Drum drum;
    Cello cello(673);
    Cymbal cymbal;
    Trombone tbone(4);
    Trumpet trpt(12);
    Violin violin(567);

    MILL mill;
    mill.receiveInstr(trpt);
    mill.receiveInstr(violin);
    mill.receiveInstr(tbone);
    mill.receiveInstr(drum);
    mill.receiveInstr(cello);
    mill.receiveInstr(cymbal);
    cout << endl;

    Musician bob;
    Musician sue;
    Musician mary;
    Musician ralph;
    Musician jody;
    Musician morgan;

    Orch orch;

    // THE SCENARIO

    //Bob joins the orchestra without an instrument.
    orch.addPlayer(bob);

    //The orchestra performs
    cout << "orch performs\n";
    orch.play();

    //Sue gets an instrument from the MIL2 and joins the orchestra.
    sue.acceptInstr(mill.loanOut());
    orch.addPlayer(sue);

    //Ralph gets an instrument from the MIL2.
    ralph.acceptInstr(mill.loanOut());

    //Mary gets an instrument from the MIL2 and joins the orchestra.
    mary.acceptInstr(mill.loanOut());
    orch.addPlayer(mary);

    //Ralph returns his instrument to the MIL2.
    mill.receiveInstr(*ralph.giveBackInstr());
    cout << endl;

    //Jody gets an instrument from the MIL2 and joins the orchestra.
    jody.acceptInstr(mill.loanOut());
    orch.addPlayer(jody);

    // morgan gets an instrument from the MIL2
    morgan.acceptInstr(mill.loanOut());

    //The orchestra performs.
    cout << "orch performs\n";
    orch.play();

    //Ralph joins the orchestra.
    orch.addPlayer(ralph);

    //The orchestra performs.
    cout << "orch performs\n";
    orch.play();

    // bob gets an instrument from the MIL2
    bob.acceptInstr(mill.loanOut());

    // ralph gets an instrument from the MIL2
    ralph.acceptInstr(mill.loanOut());

    //The orchestra performs.
    cout << "orch performs\n";
    orch.play();

    //Morgan joins the orchestra.
    orch.addPlayer(morgan);

    //The orchestra performs.
    cout << "orch performs\n";
    orch.play();

} // main


