#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

class Person {

    public:

        Person(int id_, string name_, string email_) {

            id = id_;
            name = name_;
            email = email_;

        }

    private:

        int id = 0;
        string name = "";
        string email = "";

};

class Lehrperson : public Person {

    public:

        Lehrperson(int id_, string name_, string email_) : Person(id_, name_, email_) {



        }

        void notenEintragen(Fach& fach, Leistungsnachweis nachweis) {

            fach.addNachweis(nachweis);

        }

    private:



    protected:

};

class Leistungsnachweis {

    public:

        Leistungsnachweis(double note_, string datum_, double gewichtung_) {

            note = note_;
            datum = datum_;
            gewichtung = gewichtung_;

        }

        double getNote() {
            
            return note;
        
        }

        double getGewichtung() {
            
            return gewichtung;
        
        }

    private:

        double note = 0;
        string datum = "";
        double gewichtung = 0;

};


class Fach {

    public:

        Fach(string name_, vector<Leistungsnachweis> nachweise_) {

            name = name_;
            nachweise = nachweise_;

        }

        void addNachweis(Leistungsnachweis nachweise_) {

            nachweise.push_back(nachweise_);

        }

        double berechneDurchschnitt() {

            double summeGewichtet = 0;
            double summeGewichtung = 0;

            for (int i = 0; i < nachweise.size(); i++) {

            summeGewichtet += nachweise[i].getNote()*nachweise[i].getGewichtung(); 
            summeGewichtung += nachweise[i].getGewichtung();

            }

            return summeGewichtet / summeGewichtung;

        }

    private:

       string name;
       vector<Leistungsnachweis> nachweise;

    protected:

};

class Schueler : public Person {

    public:

        Schueler(int id_, string name_, string email_) : Person(id_, name_, email_) { 

        }

        void addFach(Fach faecher_) {

            faecher.push_back(faecher_);

        }

    private:

        vector<Fach> faecher;

    protected:


};

int main() {

    Schueler schueler(1, "bernt", "bernt@schule.ch");
    Lehrperson lehrer(2, "frank", "frank@schule.ch");

    vector<Leistungsnachweis> leer;
    Fach mathe("Mathematik", leer);

    lehrer.notenEintragen(mathe, Leistungsnachweis(5.5, "01.03.2025", 2));
    lehrer.notenEintragen(mathe, Leistungsnachweis(4.0, "15.04.2025", 1));

    schueler.addFach(mathe);

    cout << "Durchschnitt Mathematik: " << mathe.berechneDurchschnitt() << endl;

    return 0;
}
